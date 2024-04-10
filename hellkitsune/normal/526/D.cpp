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

int n, k;
char s[1000005];
LL MOD = 1e15 + 37, MUL = 1009;
LL h[1000005];
int ans[1000005] = {};
LL mu[1000005], tmp[1000005];

inline LL mul(LL a, LL b) {
    LL ret = 0;
    while (true) {
        ret += (a & 1023ll) * b;
        a >>= 10;
        if (a) b = (b << 10) % MOD;
        else break;
    }
    return ret % MOD;
}

inline LL calc(int from, int to) {
    return (h[from] - mul(h[to], mu[to - from]) + MOD) % MOD;
}

int main() {
    mu[0] = 1;
    for (int i = 1; i < 1000005; ++i)
        mu[i] = (mu[i - 1] * MUL) % MOD;
    scanf("%d%d%s", &n, &k, s);
    //REP(i, n) s[i] = 'a' + (i % 26);
    if (k == 1) {
        REP(i, n) printf("1");
        printf("\n");
        return 0;
    }
    h[n] = 0;
    for (int i = n - 1; i >= 0; --i)
        h[i] = (h[i + 1] * MUL + s[i]) % MOD;
    tmp[0] = 0;
    for (int d = 1; d * k <= n; ++d) {
        bool flag = true;
        LL hh = tmp[d] = calc(0, d);
        for (int i = 1; i < k; ++i) if (calc(i * d, d + i * d) != hh) {
            flag = false;
            break;
        }
        if (!flag) continue;
        int lo = 0, hi = min(d, n - d * k), mid;
        if (calc(d * k, d * k + hi) == tmp[hi]) lo = hi;
        while (lo < hi) {
            mid = (lo + hi + 1) >> 1;
            if (tmp[mid] != calc(d * k, d * k + mid))
                hi = mid - 1;
            else
                lo = mid;
        }
        ++ans[d * k - 1];
        --ans[d * k + lo];
    }
    int bala = 0;
    REP(i, n) {
        bala += ans[i];
        if (bala > 0) printf("1");
        else printf("0");
    }
    printf("\n");
    return 0;
}