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
#define foreach(e, x) for (__typeof(x.begin()) e = x.begin(); e != x.end(); ++e)
typedef long long LL;
typedef pair<int, int> PII;

int n;
int h[3000], r[3000], rr[3000];
double bot[3000];

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    REP(i, n) scanf("%d%d%d", h + i, r + i, rr + i);
    double ans = 0;
    REP(i, n) {
        double b = 0;
        REP(j, i) {
            double cur = bot[j];
            if (r[i] >= rr[j]) {
                cur = bot[j] + h[j];
            } else {
                if (r[i] > r[j]) {
                    cur = bot[j] + (r[i] - r[j]) / double(rr[j] - r[j]) * h[j];
                }
                if (rr[i] > rr[j]) {
                    cur = max(cur, bot[j] + h[j] - (rr[j] - r[i]) / double(rr[i] - r[i]) * h[i]);
                } else {
                    cur = max(cur, bot[j] + (rr[i] - r[j]) / double(rr[j] - r[j]) * h[j] - h[i]);
                }
            }
            b = max(b, cur);
        }
        bot[i] = b;
        ans = max(ans, b + h[i]);
    }
    printf("%.12f\n", ans);
    return 0;
}