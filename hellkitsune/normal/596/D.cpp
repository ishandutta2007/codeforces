#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, h;
double p, q, hp, hq;
int _x[2002], l[2000], r[2000], *x = _x + 1;
double d[2][2][2000][2000] = {};
const double EPS = 1e-22;

int main() {
    scanf("%d%d%lf", &n, &h, &p);
    q = 1 - p, hp = 0.5 * p, hq = 0.5 * q;
    REP(i, n) scanf("%d", x + i);
    sort(x, x + n);
    x[-1] = -1e9, x[n] = 1e9;
    l[0] = 0;
    for (int i = 1; i < n; ++i) {
        if (x[i] - h < x[i - 1]) l[i] = l[i - 1];
        else l[i] = i;
    }
    r[n - 1] = n - 1;
    for (int i = n - 2; i >= 0; --i) {
        if (x[i] + h > x[i + 1]) r[i] = r[i + 1];
        else r[i] = i;
    }
    d[0][0][0][n - 1] = 1;
    double ans = 0;
    REP(lo, n) for (int hi = n - 1; hi >= lo; --hi) REP(i, 2) REP(j, 2) if (d[i][j][lo][hi] > EPS) {
        double val = d[i][j][lo][hi];
        if (i) ans += val * hp * max(0, min(h, x[lo] - x[lo - 1] - h));
        else ans += val * hp * min(h, x[lo] - x[lo - 1]);
        if (j) ans += val * hq * max(0, min(h, x[hi + 1] - x[hi] - h));
        else ans += val * hq * min(h, x[hi + 1] - x[hi]);
        if (lo != hi) {
            d[0][j][lo + 1][hi] += val * hp;
            d[i][0][lo][hi - 1] += val * hq;
        }
        int newInd = max(l[hi], lo);
        if (newInd == lo) {
            if (i) ans += val * hp * (x[hi] - x[lo] + max(0, min(h, x[lo] - x[lo - 1] - h)));
            else ans += val * hp * (x[hi] - x[lo] + min(h, x[lo] - x[lo - 1]));
        } else {
            ans += val * hp * (x[hi] - x[newInd] + h);
            d[i][1][lo][newInd - 1] += val * hp;
        }
        newInd = min(r[lo], hi);
        if (newInd == hi) {
            if (j) ans += val * hq * (x[hi] - x[lo] + max(0, min(h, x[hi + 1] - x[hi] - h)));
            else ans += val * hq * (x[hi] - x[lo] + min(h, x[hi + 1] - x[hi]));
        } else {
            ans += val * hq * (x[newInd] - x[lo] + h);
            d[1][j][newInd + 1][hi] += val * hq;
        }
    }
    printf("%.12f\n", ans);
    return 0;
}