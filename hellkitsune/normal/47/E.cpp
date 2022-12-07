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
#include <cassert>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, m;
double v;
double alp[10000];
double x[100000], y[100000], nx[100000], ny[100000];
int ord[100000];
double from[100000], to[100000];
const double PI = atan2(0, -1);
const double g = 9.8;

bool cmp(const int &lhs, const int &rhs) {
    return x[lhs] < x[rhs];
}

int main() {
    scanf("%d%lf", &n, &v);
    REP(i, n) scanf("%lf", alp + i);
    scanf("%d", &m);
    REP(i, m) scanf("%lf%lf", x + i, y + i);
    REP(i, m) ord[i] = i;
    sort(ord, ord + m, cmp);
    REP(i, m) nx[i] = x[ord[i]], ny[i] = y[ord[i]];
    REP(i, m) x[i] = nx[i], y[i] = ny[i];
    REP(i, m) {
        double lo = 0, hi = 0.26 * PI, mid;
        REP(iter, 50) {
            mid = (lo + hi) / 2;
            double co = cos(mid);
            double si = sin(mid);
            double t = x[i] / (v * co);
            if (t * (v * si - 0.5 * g * t) >= 0)
                hi = mid;
            else
                lo = mid;
        }
        if (lo > 0.25 * PI) {
            m = i;
            break;
        }
        from[i] = lo;
        hi = 0.25 * PI;
        REP(iter, 50) {
            mid = (lo + hi) / 2;
            double co = cos(mid);
            double si = sin(mid);
            double t = x[i] / (v * co);
            if (t * (v * si - 0.5 * g * t) >= y[i])
                hi = mid;
            else
                lo = mid;
        }
        to[i] = lo;
    }
    double mx = -1;
    for (int i = 1; i < m; ++i) {
        mx = max(mx, to[i - 1]);
        from[i] = max(from[i], mx);
    }
    int cnt = 0;
    REP(i, m) if (from[i] <= to[i]) {
        if (cnt != i) {
            x[cnt] = x[i];
            y[cnt] = y[i];
            from[cnt] = from[i];
            to[cnt] = to[i];
        }
        ++cnt;
    }
    m = cnt;
    REP(i, n) {
        int pos = lower_bound(to, to + m, alp[i]) - to;
        double co = cos(alp[i]);
        double si = sin(alp[i]);
        if (pos < m && from[pos] <= alp[i]) {
            double t = x[pos] / (v * co);
            double cy = t * (v * si - 0.5 * g * t);
            printf("%.12f %.12f\n", x[pos], cy);
        } else {
            double t = 2 * v * si / g;
            double cx = v * co * t;
            printf("%.12f 0\n", cx);
        }
    }
    return 0;
}