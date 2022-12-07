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
int f[200005], rf[200005];
const int MOD = 1e9 + 7;

int c(int n, int k) {
    return (LL)f[n] * rf[k] % MOD * rf[n - k] % MOD;
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

LL ans = 0;

int main() {
    cin >> n;
    if (n == 1) {
        cout << 1 << endl;
        return 0;
    }
    f[0] = 1;
    for (int i = 1; i < 200005; ++i) f[i] = (LL)f[i - 1] * i % MOD;
    REP(i, 200005) rf[i] = binPow(f[i], MOD - 2);
    REP(i, n) {
        ans = (ans + (LL)c(i + n - 2, n - 2) * (n - i)) % MOD;
    }
    ans = 2 * ans - n;
    ans %= MOD;
    if (ans < 0) ans += MOD;
    cout << ans << endl;
    return 0;
}