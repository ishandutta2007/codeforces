#include <iostream>
#include <sstream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>    


using namespace std;


#define eps 0.00001
#define Pi acos(-1)


struct point{
    double x, y;
    point(){}
    point(double _x, double _y){
        x = _x;
        y = _y;
    }
};


struct line{
    double a, b, c;
    line(){}
    line(point begin, point end) {
        a = end.y - begin.y;
        b = begin.x - end.x;
        double d = sqrt(a * a + b * b);
        a /= d;
        b /= d;
        c /= d;
    }
};

point a[3];


point center(double a, double b, double c, double a1, double b1, double c1) {
    return point((c1 * b - c * b1) / (a * b1 - a1 * b), (c1 * a - c * a1) / (b * a1 - b1 * a));
}

double b[3];


int main() {
    for (int i = 0; i < 3; i++) {
        cin >> a[i].x >> a[i].y;
    }
    line l = line(a[0], a[1]);
    line l1 = line(a[0], a[2]);
    point m = point((a[0].x + a[1].x) / 2.0, (a[0].y + a[1].y) / 2.0);
    point m1 = point((a[0].x + a[2].x) / 2.0, (a[0].y + a[2].y) / 2.0);
    point s = center(-l.b, l.a, -(-l.b * m.x + l.a * m.y), -l1.b, l1.a, -(-l1.b * m1.x + l1.a * m1.y));
    for (int i = 0; i < 3; i++) {
        b[i] = atan2(a[i].y - s.y, a[i].x - s.x);
    }
   // cout << s.x << ' ' << s.y << endl;
    double aa = sqrt((a[0].x - a[1].x) * (a[0].x - a[1].x) + (a[0].y - a[1].y) * (a[0].y - a[1].y));
    double bb = sqrt((a[0].x - a[2].x) * (a[0].x - a[2].x) + (a[0].y - a[2].y) * (a[0].y - a[2].y));
    double cc = sqrt((a[2].x - a[1].x) * (a[2].x - a[1].x) + (a[2].y - a[1].y) * (a[2].y - a[1].y));
    double S = fabs((a[0].x - a[1].x) * (a[0].y - a[2].y) - (a[0].y - a[1].y) * (a[0].x - a[2].x)) / 2.00;
    double r = (aa * bb * cc) / (4.0 * S);
    for (int i = 3; i <= 100; i++) {
        bool bb = false;
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                if (fabs(sin((double(i) * (b[j] - b[k])) / 2.00)) > eps) {
                    bb = true;
                }
            }
        }
        if (!bb) {
            printf("%.10lf\n", 0.5 * double(i) * r * r * sin((2.0 * Pi) / double(i)));
            return 0;
        }
    }
    return 0;
}