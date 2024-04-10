#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

const int MOD = int(1e9) + 7;

int k, ipa, ipb, pa, pb;
int d[1005][1005];

int binPow(LL x, int p) {
    LL res = 1;
    while (p) {
        if (p & 1) res = res * x % MOD;
        p >>= 1;
        if (p) x = x * x % MOD;
    }
    return (int)res;
}

inline void modAdd(int &x, int y) {
    x += y;
    if (x >= MOD) x -= MOD;
}

int main() {
    scanf("%d%d%d", &k, &ipa, &ipb);
    pa = (LL)ipa * binPow(ipa + ipb, MOD - 2) % MOD;
    pb = (LL)ipb * binPow(ipa + ipb, MOD - 2) % MOD;
    d[k][1] = 1;
    for (int i = k; i >= 1; --i) {
        for (int j = 1; j < i; ++j) {
            modAdd(d[i][j + 1], (LL)pa * d[i][j] % MOD);
            modAdd(d[i - j][j], (LL)pb * d[i][j] % MOD);
        }
    }
    int ans = 0;
    for (int i = 1; i <= k; ++i) {
        for (int j = i; j <= k; ++j) {
            int cnt = k + j - i;
            modAdd(ans, (LL)d[i][j] * cnt % MOD);
        }
    }
    modAdd(ans, (LL)(ipa + ipb) * binPow(ipb, MOD - 2) % MOD);
    ans -= 1;
    if (ans < 0) ans += MOD;
    cout << ans << endl;
    return 0;
}