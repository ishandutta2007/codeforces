#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <sstream>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <map>
#include <set>
#include <list>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define foreach(e, x) for (__typeof(x.begin()) e = x.begin(); e != x.end(); e++)
typedef long long LL;
typedef pair<int, int> PII;

double t1, t2, T1, T2; //t1 + shop + home, t2 + home
double x[3], y[3]; //0 - cinema, 1 - home, 2 - shop

const double EPS = 1e-11;

struct Point {
    double x, y;
    Point() {}
    Point(double a, double b) {x = a; y = b;}
};

double dist(double x1, double y1, double x2, double y2) {
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

void getIsectPoints(double r, double a, double b, double c, vector<Point> &res) {
    double k = a * a + b * b;
    double x0 = -a * c / k, y0 = -b * c / k;
    double d = x0 * x0 + y0 * y0;
    if (abs(sqrt(d) - r) < EPS) {
        res.pb(Point(x0, y0));
    } else if (d < r * r) {
        double d1 = sqrt((r * r - d) / k);
        res.pb(Point(x0 - b * d1, y0 + a * d1));
        res.pb(Point(x0 + b * d1, y0 - a * d1));
    }
}

void getIsectPoints(double x1, double y1, double r1, double x2, double y2, double r2, vector<Point> &res) {
    //x^2 - 2*x*x2 + x2^2 + y^2 - 2*y*y2 + y2^2 - r2^2 = 0
    x2 -= x1; y2 -= y1;
    getIsectPoints(r1, -2 * x2, -2 * y2, x2 * x2 + y2 * y2 - r2 * r2 + r1 * r1, res);
    foreach(e, res) e->x += x1, e->y += y1;
}

bool sharePoint(double x1, double y1, double r1, double x2, double y2, double r2, double x3, double y3, double r3) {
    vector<Point> res1, res2, res3;
    getIsectPoints(x3, y3, r3, x2, y2, r2, res1);
    getIsectPoints(x1, y1, r1, x3, y3, r3, res2);
    getIsectPoints(x1, y1, r1, x2, y2, r2, res3);
    foreach(e, res1) if (dist(x1, y1, e->x, e->y) < r1 + EPS) return true;
    foreach(e, res2) if (dist(x2, y2, e->x, e->y) < r2 + EPS) return true;
    foreach(e, res3) if (dist(x3, y3, e->x, e->y) < r3 + EPS) return true;
    if (dist(x1, y1, x2, y2) < r2 + EPS && dist(x1, y1, x3, y3) < r3 + EPS) return true;
    if (dist(x2, y2, x1, y1) < r1 + EPS && dist(x2, y2, x3, y3) < r3 + EPS) return true;
    if (dist(x3, y3, x1, y1) < r1 + EPS && dist(x3, y3, x2, y2) < r2 + EPS) return true;
    if (dist(x1, y1, x2, y2) < r1 + EPS && dist(x1, y1, x3, y3) < r1 + EPS) return true;
    if (dist(x2, y2, x1, y1) < r2 + EPS && dist(x2, y2, x3, y3) < r2 + EPS) return true;
    if (dist(x3, y3, x1, y1) < r3 + EPS && dist(x3, y3, x2, y2) < r3 + EPS) return true;
    return false;
}

bool can(double r) {
    return sharePoint(x[0], y[0], r,
                      x[1], y[1], T2 - r,
                      x[2], y[2], t1 + dist(x[0], y[0], x[2], y[2]) - r);
}

int main() {
    cin >> t1 >> t2;
    REP(i, 3) cin >> x[i] >> y[i];
    T1 = t1 + dist(x[0], y[0], x[2], y[2]) + dist(x[2], y[2], x[1], y[1]);
    T2 = t2 + dist(x[0], y[0], x[1], y[1]);
    if (dist(x[0], y[0], x[2], y[2]) + dist(x[2], y[2], x[1], y[1]) - dist(x[0], y[0], x[1], y[1]) < t2 + EPS) {
        cout << setprecision(12) << fixed << min(T1, T2) << endl;
        return 0;
    }
    double l = 0, r = min(t1 + dist(x[0], y[0], x[2], y[2]), T2), mid;
    can(10);
    REP(times, 200) {
        mid = (l + r) / 2;
        if (can(mid))
            l = mid;
        else
            r = mid;
    }
    cout << setprecision(12) << fixed << l << endl;
    return 0;
}