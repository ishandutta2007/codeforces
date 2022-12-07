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

int n, k;
double pr[1000], d[1001], ans = 0;
const double EPS = 1e-20;

LL solve(LL bound) {
    LL ret = 0;
    LL x;
    for (x = 1; x < bound; x *= 10) {
        LL y = x * 2 - 1;
        y = min(y, bound);
        ret += y - x + 1;
    }
    if (x == bound) ++ret;
    return ret;
}

int main() {
    scanf("%d", &n);
    REP(i, n) {
        LL from, to;
        scanf("%I64d%I64d", &from, &to);
        LL cnt = solve(to) - solve(from - 1);
        pr[i] = cnt / double(to - from + 1);
    }
    d[0] = 1;
    REP(i, n) {
        for (int j = i + 1; j > 0; --j) {
            d[j] += d[j - 1] * pr[i];
            d[j - 1] *= 1 - pr[i];
        }
        REP(j, i + 1) if (d[j] < EPS) {
            d[j] = 0;
        }
    }
    scanf("%d", &k);
    REP(i, n + 1) if (i * 100 >= k * n) {
        ans += d[i];
    }
    printf("%.12f\n", ans);
    return 0;
}