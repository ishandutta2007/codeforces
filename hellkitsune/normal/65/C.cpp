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
typedef long double Double;

int n;
int x[10005], y[10005], z[10005];
Double t[10005];
int vp, vs;
int px, py, pz;
const Double EPS = 1e-15;

inline Double dist(Double dx, Double dy, Double dz) {
    return sqrt(dx * dx + dy * dy + dz * dz);
}

int main() {
    scanf("%d", &n), ++n;
    REP(i, n) scanf("%d%d%d", x + i, y + i, z + i);
    scanf("%d%d", &vp, &vs);
    scanf("%d%d%d", &px, &py, &pz);
    t[0] = 0;
    for (int i = 1; i < n; ++i) {
        t[i] = t[i - 1] + dist(x[i] - x[i - 1], y[i] - y[i - 1], z[i] - z[i - 1]);
    }
    Double v = (Double)vp / vs;
    for (int i = 1; i < n; ++i) if (dist(x[i] - px, y[i] - py, z[i] - pz) < t[i] * v + EPS) {
        printf("YES\n");
        Double lo = 0, hi = 1, mid;
        REP(times, 200) {
            mid = (lo + hi) * 0.5;
            Double xx = x[i - 1] + mid * (x[i] - x[i - 1]);
            Double yy = y[i - 1] + mid * (y[i] - y[i - 1]);
            Double zz = z[i - 1] + mid * (z[i] - z[i - 1]);
            Double tt = t[i - 1] + mid * (t[i] - t[i - 1]);
            if (dist(xx - px, yy - py, zz - pz) < tt * v + EPS)
                hi = mid;
            else
                lo = mid;
        }
        Double xx = x[i - 1] + lo * (x[i] - x[i - 1]);
        Double yy = y[i - 1] + lo * (y[i] - y[i - 1]);
        Double zz = z[i - 1] + lo * (z[i] - z[i - 1]);
        Double tt = t[i - 1] + mid * (t[i] - t[i - 1]);
        printf("%.12f\n%.12f %.12f %.12f\n", (double)tt / vs, (double)xx, (double)yy, (double)zz);
        return 0;
    }
    printf("NO\n");
    return 0;
}