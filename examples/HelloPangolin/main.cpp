#include <pangolin/display/display.h>
#include <pangolin/display/view.h>
#include <pangolin/handler/handler.h>
#include <pangolin/gl/gldraw.h>

int main( int /*argc*/, char** /*argv*/ )
{
    //创建一个大小为640*480的窗口
    pangolin::CreateWindowAndBind("Main",640,480);
    //启用深度测试
    glEnable(GL_DEPTH_TEST);

    //定义投影和初始模型视图矩阵 
    //摆放一个相机
    pangolin::OpenGlRenderState s_cam(
        pangolin::ProjectionMatrix(640,480,420,420,320,240,0.2,100),
        pangolin::ModelViewLookAt(-2,2,-2, 0,0,0, pangolin::AxisY)
    );

    // Create Interactive View in window
    pangolin::Handler3D handler(s_cam);
    pangolin::View& d_cam = pangolin::CreateDisplay()
            .SetBounds(0.0, 1.0, 0.0, 1.0, -640.0f/480.0f)
            .SetHandler(&handler);

    while( !pangolin::ShouldQuit() )
    {
        // Clear screen and activate view to render into
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        d_cam.Activate(s_cam);

        // Render OpenGL Cube
        pangolin::glDrawColouredCube();

        // Swap frames and Process Events
        pangolin::FinishFrame();
    }

    return 0;
}
