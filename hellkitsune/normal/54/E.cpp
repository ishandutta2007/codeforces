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

int n;
int x[80010], y[80010];
const double PI = atan2(0, -1);
double sum[80010];

bool cw(int a, int b, int c) {
    return LL(x[b] - x[a]) * (y[c] - y[a]) - LL(x[c] - x[a]) * (y[b] - y[a]) < 0;
}

double getS(double x, double y, double xx, double yy) {
    return x * yy - xx * y;
}

int main() {
    double ans = 1e100;
    scanf("%d", &n);
    REP(i, n) scanf("%d%d", x + i, y + i);
    REP(zzz, 2) {
        if (cw(0, 1, 2)) {
            reverse(x, x + n);
            reverse(y, y + n);
        }
        REP(i, n + 10) x[n + i] = x[i], y[n + i] = y[i];
        sum[0] = 0;
        for (int i = 1; i < 2 * n + 10; ++i) {
            sum[i] = sum[i - 1] + getS(x[i - 1], y[i - 1], x[i], y[i]);
        }
        int j = 0;
        REP(i, n) {
            double ang = atan2(y[i + 1] - y[i], x[i + 1] - x[i]);
            if (j <= i) ++j;
            while (true) {
                double delta = atan2(y[j + 1] - y[j], x[j + 1] - x[j]) - ang;
                if (delta < 0) delta += 2 * PI;
                if (delta >= 0.5 * PI) break;
                ++j;
            }
            bool flag = j < n;
            if (flag) j += n;
            ang = -ang;
            double si = sin(ang);
            double co = cos(ang);
            int best = -1;
            double bestxx = 0, bestyy = 0;
            for (int k = j - 3; k <= j + 3; ++k) {
                double xx = co * x[k] - si * y[k];
                double yy = si * x[k] + co * y[k];
                if (best == -1 || xx > bestxx) {
                    best = k;
                    bestxx = xx;
                    bestyy = yy;
                }
            }
            while (best < i) best += n;
            while (best - n > i) best -= n;
            double s = sum[best] - sum[i];
            double vx = co * x[i] - si * y[i];
            double vy = si * x[i] + co * y[i];
            double cur = getS(vx, vy, bestxx, vy) + getS(bestxx, vy, bestxx, bestyy) - s;
            cur = abs(cur * 0.5);
            ans = min(ans, cur);
            if (flag) j -= n;
        }
        REP(i, n) swap(x[i], y[i]);
    }
    printf("%.12f\n", ans);
    return 0;
}