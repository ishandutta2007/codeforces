#include <vector>
#include <stdio.h>
#include <math.h>
#include <algorithm>

using namespace std;

int w, h, alfa;
double a;
double mod;
double pi = 2*acos(0);

#define all(v) (v).begin(), (v).end()
#define _inline(f...) f() __attribute__((always_inline)); f

const double EPS = 1e-10;

_inline(int cmp)(double x, double y = 0, double tol = EPS) {
    return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

struct point {
    double x, y;
    point(double x = 0, double y = 0): x(x), y(y) {}
    point operator +(point q) { return point(x + q.x, y + q.y); }
    point operator -(point q) { return point(x - q.x, y - q.y); }
    point operator *(double t) { return point(x * t, y * t); }
    point operator /(double t) { return point(x / t, y / t); }
    double operator *(point q) { return x * q.x + y * q.y; }
    double operator %(point q) { return x * q.y - y * q.x; }
    int cmp(point q) const {
        if (int t = ::cmp(x, q.x)) return t;
        return ::cmp(y, q.y);
    }
    bool operator ==(point q) const { return cmp(q) == 0; }
    bool operator !=(point q) const { return cmp(q) != 0; }
    bool operator < (point q) const { return cmp(q) < 0; }
    static point pivot;
};

_inline(int ccw)(point p, point q, point r) {
    return cmp((p - r) % (q - r));
}

typedef vector<point> polygon;
polygon p1, p2;

double poly_area(polygon& T) {
    double s = 0; int n = T.size();
    for (int i = 0; i < n; i++)
        s += T[i] % T[(i+1) % n];
    return s / 2;
}

_inline(double angle)(point p, point q, point r) {
    point u = p - q, v = r - q;
    return atan2(u % v, u * v);
}

bool between(point p, point q, point r) {
    return ccw(p, q, r) == 0 && cmp((p - q) * (r - q)) <= 0;
}

bool seg_intersect(point p, point q, point r, point s) {
    point A = q - p, B = s - r, C = r - p, D = s - q;
    int a = cmp(A % C) + 2 * cmp(A % D);
    int b = cmp(B % C) + 2 * cmp(B % D);
    if (a == 3 || a == -3 || b == 3 || b == -3) return false;
    if (a || b || p == r || p == s || q == r || q == s) return true;
    int t = (p < r) + (p < s) + (q < r) + (q < s);
    return t != 0 && t != 4;
}

int in_poly(point p, polygon& T) {
    double a = 0; int N = T.size();
    for (int i = 0; i < N; i++) {
        if (between(T[i], p, T[(i+1) % N])) return -1;
        a += angle(T[i], p, T[(i+1) % N]);
    }
    return cmp(a) != 0; //talvez aumentar a tolerancia
}

point line_intersect(point p, point q, point r, point s) {
    point a = q - p, b = s - r, c = point(p % q, r % s);
    return point(point(a.x, b.x) % c, point(a.y, b.y) % c) / (a % b);
}

polygon poly_intersect(polygon& P, polygon& Q) {
    int m = Q.size(), n = P.size();
    int a = 0, b = 0, aa = 0, ba = 0, inflag = 0;
    polygon R;
    while ((aa < n || ba < m) && aa < 2*n && ba < 2*m) {
        point p1 = P[a], p2 = P[(a+1) % n], q1 = Q[b], q2 = Q[(b+1) % m];
        point A = p2 - p1, B = q2 - q1;
        int cross = cmp(A % B), ha = ccw(p2, q2, p1), hb = ccw(q2, p2, q1);
        if (cross == 0 && ccw(p1, q1, p2) == 0 && cmp(A * B) < 0) {
            if (between(p1, q1, p2)) R.push_back(q1);
            if (between(p1, q2, p2)) R.push_back(q2);
            if (between(q1, p1, q2)) R.push_back(p1);
            if (between(q1, p2, q2)) R.push_back(p2);
            if (R.size() < 2) return polygon();
            inflag = 1; break;
        } else if (cross != 0 && seg_intersect(p1, p2, q1, q2)) {
            if (inflag == 0) aa = ba = 0;
            R.push_back(line_intersect(p1, p2, q1, q2));
            inflag = (hb > 0) ? 1 : -1;
        }
        if (cross == 0 && hb < 0 && ha < 0) return R;
        bool t = cross == 0 && hb == 0 && ha == 0;
        if (t ? (inflag == 1) : (cross >= 0) ? (ha <= 0) : (hb > 0)) {
            if (inflag == -1) R.push_back(q2);
            ba++; b++; b %= m;
        } else {
            if (inflag == 1) R.push_back(p2);
            aa++; a++; a %= n;
        }
    }
    if (inflag == 0) {
        if (in_poly(P[0], Q)) return P;
        if (in_poly(Q[0], P)) return Q;
    }
    R.erase(unique(all(R)), R.end());
    if (R.size() > 1 && R.front() == R.back()) R.pop_back();
    return R;
}



void add(double ang) {
    p1.push_back(point(mod*cos(ang), mod*sin(ang)));
    p2.push_back(point(mod*cos(ang+a), mod*sin(ang+a)));
}

int main() {
    scanf("%d %d %d", &w, &h, &alfa);

    a = pi/180 * alfa;
    mod = hypot(w/2., h/2.);

    double st = atan(((double)h)/w);
    
    add(st);
    add(pi-st);
    add(pi+st);
    add(2*pi-st);

    polygon inter = poly_intersect(p1,p2);

    double ans = poly_area(inter);
    if (ans < 0) ans = -ans;
    printf("%.15lf", ans);
}