#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, xx, yy;
const LL INF = 1e18;
const double PI = atan2(0, -1);
int x[100001], y[100001];
double actualMin;

void solve(double x, double y, double xx, double yy) {
    double a = y - yy;
    double b = xx - x;
    double c = a * x + b * y;
    double aa = -b;
    double bb = a;
    double cc = 0;
    double det = a * bb - aa * b;
    double ix = (c * bb - cc * b) / det;
    double iy = (a * cc - aa * c) / det;
    if (x > xx) swap(x, xx);
    if (y > yy) swap(y, yy);
    if (ix >= x && ix <= xx && iy >= y && iy <= yy) {
        actualMin = min(actualMin, ix * ix + iy * iy);
    }
}

int main() {
    scanf("%d%d%d", &n, &xx, &yy);
    LL mn = INF, mx = -INF;
    REP(i, n) {
        scanf("%d%d", x + i, y + i);
        LL dist = (LL)(xx - x[i]) * (xx - x[i]) + (LL)(yy - y[i]) * (yy - y[i]);
        mn = min(mn, dist);
        mx = max(mx, dist);
    }
    x[n] = x[0], y[n] = y[0];
    actualMin = mn;
    REP(i, n) solve(x[i] - xx, y[i] - yy, x[i + 1] - xx, y[i + 1] - yy);
    double ans = PI * (mx - actualMin);
    printf("%.12f\n", ans);
    return 0;
}