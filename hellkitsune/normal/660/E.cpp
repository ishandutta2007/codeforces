#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, m;
const int MOD = 1e9 + 7;

int binPow(LL x, int p) {
    LL res = 1;
    while (p) {
        if (p & 1) res = res * x % MOD;
        p >>= 1;
        if (p) x = x * x % MOD;
    }
    return (int)res;
}

int main() {
    cin >> n >> m;
    if (m == 1) {
        cout << n + 1 << endl;
        return 0;
    }
    int ans = 1, x = 0;
    int prob = (LL)(m - 1) * binPow(m, MOD - 2) % MOD;
    int rev = binPow(m, MOD - 2);
    REP(i, n) {
        int pans = ans;
        ans = (2ll * ans - x + MOD) % MOD;
        x = ((LL)x * prob + (LL)rev * pans) % MOD;
    }
    REP(i, n) ans = (LL)ans * m % MOD;
    cout << ans << endl;
    return 0;
}