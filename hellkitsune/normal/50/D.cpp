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

int n, k, xx, yy;
double e;
int x[100], y[100];
double dist[100];
double d[105];

int main() {
    scanf("%d%d%lf%d%d", &n, &k, &e, &xx, &yy);
    e *= 0.001;
    REP(i, n) scanf("%d%d", x + i, y + i);
    REP(i, n) dist[i] = (x[i] - xx) * (x[i] - xx) + (y[i] - yy) * (y[i] - yy);
    double lo = 0, hi = 10000, mid;
    REP(timer, 200) {
        mid = (lo + hi) / 2;
        double sureThing = 0;
        REP(i, n + 1) d[i] = 0;
        d[0] = 1;
        REP(i, n) if (dist[i] <= mid * mid) {
            ++sureThing;
        } else {
            double p = exp(1 - dist[i] / (mid * mid));
            for (int i = n; i > 0; --i) {
                d[i] += d[i - 1] * p;
                d[i - 1] *= 1 - p;
            }
        }
        double win = 0;
        REP(i, n + 1) if (sureThing + i >= k) {
            win += d[i];
        }
        if (1 - win > e)
            lo = mid;
        else
            hi = mid;
    }
    printf("%.12f\n", lo);
    return 0;
}