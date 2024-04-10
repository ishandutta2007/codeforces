#include <iostream>
#include <sstream>
#include <cmath>
#include <algorithm>
#include <string>
#include <string.h>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <cstring>
#include <queue>
#include <bitset>
#include <queue>
#include <unordered_map>
#include <vector>


using namespace std;


#define Pi acos(-1)


struct point{
    double x, y;
    point(){}
    point(double _x, double _y) {
        x = _x;
        y = _y;
    }
    point(point a, point b) {
        x = b.x - a.x;
        y = b.y - a.y;
    }
};



int n;
point p;
point x[100001];


point intersection(point a, point b, point c, point d) {
    double fa = b.y - a.y;
    double fb = a.x - b.x;
    double fc = -(fa * a.x + fb * b.y);
    double fa1 = d.y - c.y;
    double fb1 = c.x - d.x;
    double fc1 = -(fa1 * c.x + fb1 * c.y);
    point s = point(-(fc * fb1 - fc1 * fb) / (fa * fb1 - fa1 * fb), -(fc * fa1 - fc1 * fa) / (fb * fa1 - fb1 * fa));
    return s;
}


double dist(point a, point b) {
    return sqrt((b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y));
}


double vec(point a, point b) {
    return a.x * b.y - a.y * b.x;
}


double scal(point a, point b) {
    return a.x * b.x + a.y * b.y;
}


int main() {
    cin >> n;
    cin >> p.x >> p.y;
    for (int i = 0; i < n; i++) {
        cin >> x[i].x >> x[i].y;
    }
    double ans = 100000000000.0;
    double ans1 = 0;
    for (int i = 0; i < n; i++) {
        ans = min(ans, dist(p, x[i]));
        ans1 = max(ans1, dist(p, x[i]));
    }
    for (int i = 0; i < n; i++) {
        int j = (i + 1) % n;
        point y = p;
        point y1 = point(p.x + -(x[j].y - x[i].y), p.y + (x[j].x - x[i].x));
        point g = intersection(x[i], x[j], y, y1);
        if (scal(point(x[i], p), point(x[i], x[j])) > -1e-9 && scal(point(x[j], p), point(x[j], x[i])) > -1e-9) {
            ans = min(ans, fabs(vec(point(x[i], x[j]), point(x[i], p)) / dist(point(0.0, 0.0), point(x[i], x[j]))));
        }
    }
    printf("%.12lf\n", Pi * (ans1 * ans1 - ans * ans));
    return 0;
}