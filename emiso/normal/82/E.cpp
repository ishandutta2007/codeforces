#include <bits/stdc++.h>

#define EPS 1e-10

using namespace std;
typedef double T;

int cmp(T x, T y = 0) {
    return (x <= y + EPS) ? (x + EPS < y) ? -1 : 0 : 1;
}

struct point {
    T x, y;

    point(T x = 0, T y = 0): x(x), y(y) {}

    point operator + (point b) { return point(x + b.x, y + b.y); }
    point operator - (point b) { return point(x - b.x, y - b.y); }
    bool operator < (const point b) const { return tie(x,y) < tie(b.x, b.y); }
};
typedef pair<point, point> segm;

inline T distPoints(point a) {
    return sqrt(a.x * a.x + a.y * a.y);
}

/** Dot product **/
inline T escalar(point a, point b) {
    return a.x * b.x + a.y * b.y;
}

/** Cross product **/
inline T vetorial(point a, point b) {
    return a.x * b.y - a.y * b.x;
}

/** Counter-clockwise **/
int ccw(point p, point q, point o) {
    return cmp(vetorial(p - o, q - o));
}

T angle(point p, point q, point o) {
    point u = p - q, v = o - q;
    return atan2(vetorial(u, v), escalar(u, v));
}

/** Area of polygon **/
T polygon_area(vector <point> &points) {
    if(points.size() < 3) return 0;
    T area = vetorial(points.back(), points[0]);
    for(int i=1; i < (int)points.size(); i++)
        area += vetorial(points[i-1], points[i]);

    return abs(area) / 2;
}

struct line {
    T a, b, c;

    line(T a, T b, T c): a(a), b(b), c(c) {}

    line(point p1, point p2):
        a(p1.y - p2.y),
        b(p2.x - p1.x),
        c(p1.x*p2.y - p2.x*p1.y) {}
};

/** Distance from point to line (defined by two other points) **/
inline T point_line(point a, point l1, point l2) {
    return abs(vetorial(l2 - l1, a - l1)) / abs(distPoints(l2 - l1));
}

/** Distance from point to line **/
inline T point_line(point a, line l) {
    return abs(l.a*a.x + l.b*a.y + l.c) / sqrt(l.a*l.a + l.b*l.b);
}

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

/** Distance between two lines **/
T distLines(line a, line b) {
    if(!parallel(a,b)) return 0;
    if(a.a == 0) return point_line(point(0, -a.c/a.b), b);
    return point_line(point(-a.c/a.a, 0), b);
}

/**Intersection between two lines **/
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
    lc = -a.a * b.x - a.b * b.y;
    return line(la, lb, lc);
}

void print(vector<point> &pol) {
    for(point P : pol) {
        printf("%f %f\n", P.x, P.y);
    } puts("");
}

void print(point p) {
    printf("%.2f %.2f\n", p.x, p.y);
}

vector<vector<point> > traps;

void create_traps(int l, int r, int h, int f) {
    if(l < 0 && r > 0) {
        create_traps(l, 0, h, f);
        create_traps(0, r, h, f);
        return;
    }

    if(h > 0) swap(l, r);

    line axis(point(l, -h), point(r, -h));
    line inter_l(point(0, f), point(l, h));
    line inter_r(point(0, f), point(r, h));

    vector<point> p;
    p.push_back(point(l, h));
    p.push_back(point(r, h));
    p.push_back(intersection(axis, inter_r));
    p.push_back(intersection(axis, inter_l));

    traps.push_back(p);
}

T traps_intersec(vector<point> t1, vector<point> t2) {
    for(int i=0;i<t1.size();i++) {
        vector<point> c;
        point v1 = t1[i];
        point v2 = t1[(i+1)%t1.size()];

        line H(v1, v2);
        for(int j=0;j<t2.size();j++) {
            point v3 = t2[j];
            point v4 = t2[(j+1)%t2.size()];

            point x = intersection(H, line(v3, v4));
            if(ccw(v2, v3, v1) >= 0) {
                c.push_back(v3);
                if(ccw(v2, v4, v1) < 0)
                    c.push_back(x);
            }
            else {
                if(ccw(v2, v4, v1) >= 0)
                    c.push_back(x);
            }
        }
        t2 = c;
    }

    //printf("%f\n",polygon_area(t2));
    return polygon_area(t2);
}

int main() {
    int n, h, f, l, r;
    scanf("%d %d %d", &n, &h, &f);
    for(int i=0;i<n;i++) {
        scanf("%d %d", &l, &r);
        create_traps(l, r, h, f);
        create_traps(l, r, -h, -f);
    }

    T ans = 0;
    for(int i=0;i<traps.size();i++) {
        ans += polygon_area(traps[i]);
        for(int j=i+1;j<traps.size();j++) {
            ans -= traps_intersec(traps[i], traps[j]);
        }
    }
    cout << setprecision(12) << ans << endl;

    return 0;
}