#include <vector> 
#include <list> 
#include <map> 
#include <set> 
#include <queue>
#include <stack> 
#include <bitset> 
#include <algorithm> 
#include <numeric> 
#include <utility> 
#include <sstream> 
#include <iostream> 
#include <iomanip> 
#include <cstdio> 
#include <cmath> 
#include <cstdlib> 
#include <ctime> 
#include <cstring> 

using namespace std;

typedef long long ll; 
typedef pair<int, int> pii;

#define REP(i,n) for(int(i)=0;(i)<(int)(n);(i)++)

int x1, y1, x2, y2;
int vmax, t;
int wx, wy;

double project(double wx, double wy, double dx, double dy) {
    double dir_length = sqrt(dx*dx+dy*dy);
    double dot = wx*dx + wy*dy;
    return dot / dir_length;
}

double get_speed(double dx, double dy, double vmax, int wx, int wy) {
    double wind_speed = sqrt(wx*wx+wy*wy);
    double kk = project(wx, wy, dx, dy);
    //printf("kk=%f\n", kk);
    double ot = sqrt(wind_speed*wind_speed - kk*kk + 1e-8);
    //printf("ot=%f\n", ot);
    double my_help = sqrt(vmax*vmax - wind_speed*wind_speed + kk*kk + 1e-8);
    return kk + my_help;
}

int main() {
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
    
    if (x1 == x2 && y1 == y2) {
        printf("0.0\n");
        return 0;
    }

    int dir_x = x2-x1;
    int dir_y = y2-y1;
    double dist = sqrt(dir_x*dir_x + dir_y*dir_y);

    scanf("%d %d", &vmax, &t);
    scanf("%d %d", &wx, &wy);

    double sp = get_speed(dir_x, dir_y, vmax, wx, wy);
    //printf("%f\n", sp);

    if (dist <= sp * t) {
        printf("%.15f\n", dist / sp);
        return 0;
    }

    double xx = x1 + wx*t;
    double yy = y1 + wy*t;
    //double dx = x2-xx;
    //double dy = y2-yy;

    scanf("%d %d", &wx, &wy);

    double st = 0, ed = 1e9;
    REP(it, 1000) {
        double md = (st+ed)/2;
        double xxx = xx + wx*md;
        double yyy = yy + wy*md;
        double dx = x2-xxx;
        double dy = y2-yyy;
        double dist = sqrt(dx*dx+dy*dy);
        if (dist / vmax < (t+md)) {
            ed = md;
        }
        else {
            st = md;
        }
    }

    printf("%.15f\n", st + t);

}