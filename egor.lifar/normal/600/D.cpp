#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <string.h>
#include <sstream>
#include <queue>
#include <map>
#include <set>
#include <cstring>
#include <cmath>


using namespace std;


struct point{
    long double x, y;
    point(){}
    point(long double _x, long double _y) {
        x = _x;
        y = _y;
    }
    point(point a, point b) {
        x = b.x - a.x;
        y = b.y - a.y;
    }
};

point o, o1;
long double r, r1;


long double dist(point a, point b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}


int main() {
    cin >> o.x >> o.y >> r;
    cin >> o1.x >> o1.y >> r1;
    long double d = dist(o, o1);
    if (d >= r + r1) {
        printf("0.0\n");
        return 0;
    }
    if (dist(o, o1) + r <= r1) {
        printf("%.20lf\n", double(acos(-1) * r * r));
        return 0;
    }
    if (dist(o, o1) + r1 <= r) {
        printf("%.20lf\n", double(acos(-1) * r1 * r1));
        return 0;
    }    
    long double a = acos((r1 * r1 + d * d - r * r) / (2.0 * r1 * d));
    long double s = a * r1 * r1;
    long double t = r1 * r1 * sin(a) * cos(a);
    long double sum = 0.0;
    sum = s - t;
    a = acos((r * r + d * d - r1 * r1) / (2.0 * r * d));
    s = a * r * r;
    t = r * r * sin(a) * cos(a);
    sum += s - t;
    printf("%.20lf\n", double(sum));
    return 0;   
}