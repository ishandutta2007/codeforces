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

int h, w, n;
int f[200005], rf[200005];
const int MOD = 1e9 + 7;
int r[2001], c[2001], ord[2001], nr[2001], nc[2001];
int d[2001];

int C(int n, int k) {
    return (LL)f[n] * rf[k] % MOD * rf[n - k] % MOD;
}

inline bool cmp(const int &lhs, const int &rhs) {
    if (r[lhs] != r[rhs]) return r[lhs] < r[rhs];
    return c[lhs] < c[rhs];
}

int binPow(LL x, int p) {
    LL ret = 1;
    while (p) {
        if (p & 1) ret = ret * x % MOD;
        p >>= 1;
        x = x * x % MOD;
    }
    return (int)ret;
}

int main() {
    f[0] = 1;
    REP(i, 200004) f[i + 1] = (LL)f[i] * (i + 1) % MOD;
    REP(i, 200005) rf[i] = binPow(f[i], MOD - 2);
    scanf("%d%d%d", &h, &w, &n);
    REP(i, n) scanf("%d%d", r + i, c + i), --r[i], --c[i];
    REP(i, n) ord[i] = i;
    sort(ord, ord + n, cmp);
    REP(i, n) nr[i] = r[ord[i]], nc[i] = c[ord[i]];
    REP(i, n) r[i] = nr[i], c[i] = nc[i];
    REP(i, n) {
        d[i] = C(r[i] + c[i], r[i]);
        REP(j, i) if (r[j] <= r[i] && c[j] <= c[i]) {
            d[i] = (d[i] - (LL)d[j] * C(r[i] + c[i] - r[j] - c[j], r[i] - r[j])) % MOD;
        }
        if (d[i] < 0) d[i] += MOD;
    }
    int ans = C(h + w - 2, h - 1);
    REP(i, n) ans = (ans - (LL)d[i] * C(h + w - 2 - r[i] - c[i], h - 1 - r[i])) % MOD;
    if (ans < 0) ans += MOD;
    printf("%d\n", ans);
    return 0;
}