#include <bits/stdc++.h>

#define MN 1001000
#define w1 while(1)
#define debug(a) cerr << a << endl
#define pb push_back
#define mp make_pair

using namespace std;
typedef long long ll;

#define EPS 1e-9

using namespace std;
typedef double T;

int cmp(double x, double y = 0) {
	return (x <= y + EPS) ? (x + EPS < y) ? -1 : 0 : 1;
}

struct point {
    T x, y;

    point(T x = 0, T y = 0): x(x), y(y) {}

    point operator + (point b) { return point(x + b.x, y + b.y); }
    point operator - (point b) { return point(x - b.x, y - b.y); }
    bool operator < (const point b) const { return pair<T, T>(x, y) < pair<T, T>(b.x, b.y); }
};
typedef pair<point, point> segm;

point mid_point(point a, point b) {
    return point((a.x + b.x) / 2, (a.y + b.y) / 2);
}

inline T distPoints(point a) {
    return sqrt(a.x * a.x + a.y * a.y);
}

struct line {
    T a, b, c;

    line(T a = 0, T b = 0, T c = 0): a(a), b(b), c(c) {}

    line(point p1, point p2):
        a(p1.y - p2.y),
        b(p2.x - p1.x),
        c(p1.x*p2.y - p2.x*p1.y) {}
};

struct circle {
    point center;
    T rad;

    circle(point c, T r): center(c), rad(r) {}

    circle(point p1, point p2) {
        center = mid_point(p1, p2);
        rad = distPoints(p2 - p1) / 2;
    }
};

double R, xc, yc, xp, yp;
line l;
point center, fafa, target, fc;

pair<point, point> intersec() {
    double x0 = -l.a*l.c/(l.a*l.a + l.b*l.b), y0 = -l.b*l.c/(l.a*l.a + l.b*l.b);

    double d = R*R - l.c*l.c/(l.a*l.a+l.b*l.b);
    double mult = sqrt (d / (l.a*l.a+l.b*l.b));
    double ax, ay, bx, by;
    ax = x0 + l.b * mult;
    bx = x0 - l.b * mult;
    ay = y0 - l.a * mult;
    by = y0 + l.a * mult;

    return make_pair(point(ax, ay), point(bx, by));
}

int main() {
    scanf("%lf %lf %lf %lf %lf", &R, &xc, &yc, &xp, &yp);

    center = point(xc, yc);
    fafa = point(xp, yp);
    fc = fafa - center;

    if(cmp(distPoints(fafa - center), R) >= 0) {
        printf("%.12f %.12f %.12f\n", xc, yc, R - EPS);
        return 0;
    }

    if(cmp(distPoints(fafa - center)) == 0) {
        circle circ(center, (center + point(R, 0)));
        printf("%.12f %.12f %.12f\n", circ.center.x, circ.center.y, circ.rad - EPS);
        return 0;
    }

    l = line(fc, point(0, 0));
    pair<point, point> ppp = intersec();

    if(cmp(distPoints((ppp.first + center) - fafa), R) >= 0)
         target = (ppp.first + center);
    else target = (ppp.second + center);

    circle circ(target, fafa);
    printf("%.12f %.12f %.12f\n", circ.center.x, circ.center.y, circ.rad - EPS);
    return 0;
}