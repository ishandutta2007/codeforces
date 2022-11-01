#include <bits/stdc++.h>

#define EPSG 1e-6
#define INF 1e9

using namespace std;
typedef double T;

T EPS = EPSG;

int cmp(T x, T y = 0) {
	return (x <= y + EPS) ? (x + EPS < y) ? -1 : 0 : 1;
}
struct point {
    T x, y;
    int id;

    point(T x = 0, T y = 0, int id = -1): x(x), y(y), id(id) {}

    point operator + (point b) { return point(x + b.x, y + b.y); }
    point operator - (point b) { return point(x - b.x, y - b.y); }
    point operator * (T c) { return point(x*c, y*c); }
    point operator / (T c) { return point(x/c, y/c); }
    bool operator < (const point b) const {
        return pair<T, T>(x, y) < pair<T, T>(b.x, b.y);
    }
};

typedef pair<point, point> segm;
typedef vector<point> polygon;

inline T distPoints(point a) {
    return sqrt(a.x * a.x + a.y * a.y);
}

inline T escalar(point a, point b) {
    return a.x * b.x + a.y * b.y;
}

inline T vetorial(point a, point b) {
    return a.x * b.y - a.y * b.x;
}

int ccw(point p, point q, point o) {
	return cmp(vetorial(p - o, q - o));
}

T angle(point p, point q, point o) {
	point u = p - q, v = o - q;
	return atan2(vetorial(u, v), escalar(u, v));
}

point rot(point p, double a) {
    return {p.x*cos(a) - p.y*sin(a), p.x*sin(a) + p.y*cos(a)};
}

point perp(point p) {return {-p.y, p.x};}

struct line {
    T a, b, c;

    line(T a, T b, T c): a(a), b(b), c(c) {}

    line(point p1, point p2):
        a(p1.y - p2.y),
        b(p2.x - p1.x),
        c(p1.x*p2.y - p2.x*p1.y) {}
};

inline T point_line(point a, point l1, point l2) {
    return abs(vetorial(l2 - l1, a - l1)) / abs(distPoints(l2 - l1));
}

inline T point_line(point a, line l) {
    return abs(l.a*a.x + l.b*a.y + l.c) / sqrt(l.a*l.a + l.b*l.b);
}

typedef pair<point, point> segm;
inline T point_segment(segm s, point a) {
    if(escalar(s.second - s.first, a - s.first) < 0)
        return distPoints(a - s.first);

    if(escalar(s.first - s.second, a - s.second) < 0)
        return distPoints(a - s.second);

    return point_line(a, s.first, s.second);
}


bool parallel(line a, line b) {
    return abs(a.b * b.a - a.a * b.b) < EPS;
}

T distLines(line a, line b) {
    if(!parallel(a,b)) return 0;
    if(a.a == 0) return point_line(point(0, -a.c/a.b), b);
    return point_line(point(-a.c/a.a, 0), b);
}

point intersection(line a, line b) {
    point ret;
    ret.x = (b.c * a.b - a.c * b.b) / (b.b * a.a - a.b * b.a);
    ret.y = (b.c * a.a - a.c * b.a) / (a.b * b.a - b.b * a.a);
    return ret;
}

bool equal_lines(line a, line b) {
    if(!parallel(a,b)) return false;
    return abs(distLines(a,b)) < EPS;
}

line perpendicular(line a, point b) {
    T la, lb, lc;
    la = a.b;
    lb = -a.a;
    lc = -la * b.x - lb * b.y;
    return line(la, lb, lc);
}

struct circle {
    point center;
    T rad;

    circle(point c, T r): center(c), rad(r) {}

    circle(point p1, point p2) {
        center = (p1 + p2) / 2;
        rad = distPoints(p2 - p1) / 2;
    }

    circle(point p1, point p2, point p3) {
        line l12 (p1, p2);
        line l23 (p2, p3);
        assert(!equal_lines(l12, l23));

        point p12 = (p1 + p2) / 2;
        point p23 = (p2 + p3) / 2;

        center = intersection(perpendicular(l12, p12), perpendicular(l23, p23));
        rad = distPoints(center - p1);
    }
};

vector<point> tangents(circle c1, point p2) {
    point d = p2 - c1.center;
    double dr = c1.rad, d2 = escalar(d, d), h2 = d2-dr*dr;
    assert(cmp(h2) >= 0 && cmp(d2) != 0);
    vector<point> ret({c1.center + (d*dr + perp(d)*sqrt(h2))/d2*dr});
    if(cmp(h2)) ret.push_back(c1.center + (d*dr - perp(d)*sqrt(h2))/d2*dr);
    return ret;
}

double dist(point a, point b, circle c) {
    if(point_segment({a, b}, c.center) < c.rad) {
        auto tg = tangents(c, a);
        auto tg2 = tangents(c, b);
        double ret = DBL_MAX;
        for(point ta : tg) for(point tb : tg2) {
            ret = min(ret, distPoints(ta - a) + abs(angle(ta, c.center, tb))*c.rad + distPoints(b - tb));
        }
        return ret;
    }
    return distPoints(b - a);
}

double x, y, v, vp, r, R;
point a, b;

point spin(point a, double r, double v, double t) {
    double angle = v / r * t;
    return rot(a, angle);
}

int main() {
    scanf("%lf %lf %lf", &x, &y, &vp);
    a = point(x, y);
    R = distPoints(a);
    scanf("%lf %lf %lf %lf", &x, &y, &v, &r);
    b = point(x, y);
    circle c({0, 0}, r);

    double lb = 0, rb = INT_MAX, m;
    for(int it = 100; it; it--) {
        m = (lb + rb) / 2;
        if(dist(spin(a, R, vp, m), b, c) / v <= m) rb = m;
        else lb = m;
    }

    printf("%.9f\n", lb);
    return 0;
}