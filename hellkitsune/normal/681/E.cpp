#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int xx, yy, v, t;
int n;
int x[100000], y[100000], r[100000];

const double PI = atan2(0, -1);

LL dist2(int x, int y) {
    return (LL)x * x + (LL)y * y;
}

double dist(double x, double y) {
    return sqrt(x * x + y * y);
}

struct S {
    double ang;
    bool st;
    S(double ang, bool st) : ang(ang), st(st) {}
    inline bool operator < (const S &rhs) const {
        return ang < rhs.ang;
    }
};

double span(int i, double bestAng) {
    double lo = 0, hi = PI / 2, mid;
    REP(times, 25) {
        mid = 0.5 * (lo + hi);
        double ang = bestAng + mid;
        if (times == 24) {
            ang += PI / 2;
            while (abs(ang - PI - bestAng) < abs(ang - bestAng)) {
                ang -= PI;
            }
            while (abs(ang + PI - bestAng) < abs(ang - bestAng)) {
                ang += PI;
            }
            return abs(ang - bestAng);
        }
        double a = -sin(ang);
        double b = cos(ang);
        double c = -(a * xx + b * yy);
        double di = abs(a * x[i] + b * y[i] + c);
        if (di > r[i]) {
            hi = mid;
        } else {
            lo = mid;
        }
    }
    return 123412341234;
}

vector<S> ev;

int main() {
    //freopen("input.txt", "r", stdin);
    scanf("%d%d%d%d", &xx, &yy, &v, &t);
    scanf("%d", &n);
    REP(i, n) scanf("%d%d%d", x + i, y + i, r + i);
    REP(i, n) if (dist2(x[i] - xx, y[i] - yy) <= (LL)r[i] * r[i]) {
        cout << 1 << endl;
        return 0;
    }
    double canDist = (double)v * t;
    REP(i, n) {
        double bestAng = atan2(yy - y[i], xx - x[i]);
        double lo = 0, hi = span(i, bestAng), mid;
        bool ok = false;
        REP(times, 25) {
            mid = 0.5 * (lo + hi);
            double ang = bestAng + mid;
            double nx = cos(ang) * r[i] + x[i];
            double ny = sin(ang) * r[i] + y[i];
            if (dist(nx - xx, ny - yy) <= canDist) {
                lo = mid;
                ok = true;
            } else {
                hi = mid;
            }
        }
        if (ok) {
            double ang = bestAng + lo;
            double nx = cos(ang) * r[i] + x[i];
            double ny = sin(ang) * r[i] + y[i];
            double from = atan2(ny - yy, nx - xx);
            ang = bestAng - lo;
            nx = cos(ang) * r[i] + x[i];
            ny = sin(ang) * r[i] + y[i];
            double to = atan2(ny - yy, nx - xx);
            //printf("%.12f %.12f\n", from, to);
            if (to < from - PI / 2) {
                ev.pb(S(from, 1));
                ev.pb(S(PI, 0));
                ev.pb(S(-PI, 1));
                ev.pb(S(to, 0));
                //assert(PI - from + to + PI < PI + 1e-9);
            } else {
                ev.pb(S(from, 1));
                ev.pb(S(to, 0));
                //assert(to - from < PI + 1e-9);
            }
        }
    }
    sort(ev.begin(), ev.end());
    double sum = 0;
    double pre = -PI;
    int deg = 0;
    for (S e : ev) {
        if (deg) sum += e.ang - pre;
        if (e.st) ++deg;
        else --deg;
        pre = e.ang;
    }
    printf("%.12f\n", sum / (2 * PI));
    return 0;
}