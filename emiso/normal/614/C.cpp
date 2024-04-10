#include <bits/stdc++.h>

using namespace std;
typedef double T;

struct point {
    T x, y;

    point(T x, T y): x(x), y(y) {}

    point operator + (point b) {
        return point(x + b.x, y + b.y);
    }
    point operator - (point b) {
        return point(x - b.x, y - b.y);
    }
};

typedef pair<point, point> segm;

inline T distPoints(point a) {
    return sqrt(a.x * a.x + a.y * a.y);
}

inline T escalar(point a, point b) {
    return a.x * b.x + a.y * b.y;
}

inline T vetorial(point a, point b) {
    return a.x * b.y - a.y * b.x;
}

struct line {
    T a, b, c;

    line(point p1, point p2):
        a(p1.y - p2.y),
        b(p2.x - p1.x),
        c(p1.x*p2.y - p2.x*p1.y) {}
};

inline T point_line(point a, point l1, point l2) {
    return abs(vetorial(l2 - l1, a - l1)) / abs(distPoints(l2 - l1));
}

inline T point_segment(segm s, point a) {
    if(escalar(s.second - s.first, a - s.first) < 0)
        return distPoints(a - s.first);

    if(escalar(s.first - s.second, a - s.second) < 0)
        return distPoints(a - s.second);

    return point_line(a, s.first, s.second);
}

inline T area_circle(T rad) {
    return acos(-1)*rad*rad;
}

int main() {
    int n;
    double x,y, minr = 99999999, maxr = -1;
    vector<point> points;

    scanf("%d %lf %lf", &n, &x, &y);
    point p(x,y);

    scanf("%lf %lf", &x, &y);
    points.push_back(point (x, y));
    maxr = distPoints(p - points.back());

    for(int i=1; i<n;i++) {
        scanf("%lf %lf", &x, &y);
        points.push_back(point(x,y));

        maxr = max(maxr, distPoints(points.back() - p));

        segm s = make_pair(points[points.size()-2], points.back());
        minr = min(minr, point_segment(s, p));
    }

    segm s = make_pair(points[0], points.back());
    minr = min(minr, point_segment(s, p));

    printf("%.18f\n",area_circle(maxr) - area_circle(minr));

    return 0;
}