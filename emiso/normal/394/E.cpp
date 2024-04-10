#include <bits/stdc++.h>

#define EPSG 1e-6

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

struct line {
    T a, b, c;

    line(T a, T b, T c): a(a), b(b), c(c) {}

    line(point p1, point p2):
        a(p1.y - p2.y),
        b(p2.x - p1.x),
        c(p1.x*p2.y - p2.x*p1.y) {}
};

inline T distPoints(point a) {
    return sqrt(a.x * a.x + a.y * a.y);
}
inline T vetorial(point a, point b) {
    return a.x * b.y - a.y * b.x;
}
int ccw(point p, point q, point o) {
	return cmp(vetorial(p - o, q - o));
}

/// 0 - Border / 1 - Outside / -1 - Inside
int point_inside_polygon(point p, vector<point> &poly) {
    int n = poly.size(), windingNumber = 0;

    for(int i = 0; i < n; i++) {
        if(distPoints(p - poly[i]) < EPS) return 0;
        int j = (i + 1) % n;

        if(cmp(poly[i].y, p.y) == 0 && cmp(poly[j].y, p.y) == 0) {
            if(cmp(min(poly[i].x, poly[j].x), p.x) <= 0 &&
                cmp(p.x, max(poly[i].x, poly[j].x)) <= 0) return 0;
        }
        else {
            bool below = (cmp(poly[i].y, p.y) == -1);
            if(below !=  (cmp(poly[j].y, p.y) == -1)) {
                int orientation = ccw(p, poly[j], poly[i]);
                if(orientation == 0) return 0;
                if(below == (orientation > 0)) windingNumber += below ? 1 : -1;
            }
        }
    }

    return (windingNumber == 0) ? 1 : -1;
}

int n, m;
vector<point> gen, poly;
T sx, sy, sx2, sy2, ans;

T ea, eb, ec;

T get(point p) {
    return p.x * p.x * n - 2.0 * sx * p.x + sx2 + p.y * p.y * n - 2.0 * sy * p.y + sy2;
}

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        gen.emplace_back(x, y, i);
        sx += x;
        sy += y;
        sx2 += 1LL*x*x;
        sy2 += 1LL*y*y;
    }

    scanf("%d", &m);
    for(int i = 0; i < m; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        poly.emplace_back(x, y, i);
    }

    point b(sx / n, sy / n);
    if(point_inside_polygon(b, poly) <= 0) {
        ans = get(b);
    } else {
        ans = DBL_MAX;
        for(int i = 0; i < m; i++) {
            int j = (i + 1) % m;
            point p = poly[i], q = poly[j], tmp = b;
            if(cmp(p.x, q.x) == 0) {
                tmp.x = p.x;
                if(tmp.y < min(p.y, q.y)) tmp.y = min(p.y, q.y);
                if(tmp.y > max(p.y, q.y)) tmp.y = max(p.y, q.y);
            } else {
                line l(p, q);
                T a = -l.a/l.b, b = -l.c/l.b;
                ea = a*a*n + n;
                eb = -2.0*sx + 2.0*a*b*n -2.0*sy*a;
                tmp.x = -eb/(2.0*ea);
                if(tmp.x < min(p.x, q.x)) tmp.x = min(p.x, q.x);
                if(tmp.x > max(p.x, q.x)) tmp.x = max(p.x, q.x);
                tmp.y = a*tmp.x + b;
            }
            ans = min(ans, get(tmp));
        }
    }
    printf("%.9f\n", ans);
    return 0;
}