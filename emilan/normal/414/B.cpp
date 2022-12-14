#include <bits/stdc++.h>

using namespace std;

#define vt          vector
#define sz(x)       int((x).size())
#define all(x)      (x).begin(), (x).end()
#define rall(x)     (x).rbegin(), (x).rend()
#define fi          first
#define se          second

using ll = long long;
using pii = pair<int, int>;

const int maxn = 2001, maxm = 12, maxp = 2020;
const ll mod = 1e9 + 7;
ll dp[maxn][maxm];
ll len[maxm];
ll inv[maxp], fact[maxp], finv[maxp];

ll C(int n, int r) {
    if (r > n || r < 0) return 0;
    return fact[n] * finv[r] % mod * finv[n - r] % mod;
}

ll H(int n, int r) { return C(n + r - 1, r); }

void solve() {
    int n, k;
    cin >> n >> k;

    len[1] = n;
    for (int i = 1; i <= n; i++) {
        dp[i][1] = 1;
        for (int j = i + i; j <= n; j += i) {
            for (int m = 2; m < maxm; m++) {
                dp[j][m] = (dp[j][m] + dp[i][m - 1]) % mod;
                len[m] = (len[m] + dp[i][m - 1]) % mod;
            }
        }
    }

    ll ans = 0;
    for (int i = 1; i <= min(maxm - 1, k); i++) {
        ans = (ans + H(i, k - i) * len[i]) % mod;
    }

    cout << ans;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    inv[1] = 1;
    for (int i = 2; i < maxn; i++) {
        inv[i] = mod - mod / i * inv[mod % i] % mod;
    }

    fact[0] = finv[0] = 1;
    for (int i = 1; i < maxn; i++) {
        fact[i] = fact[i - 1] * i % mod;
        finv[i] = finv[i - 1] * inv[i] % mod;
    }

    int tcs = 1;
    for (int tc = 1; tc <= tcs; tc++) {
        // cout << "Case " << tc << ": ";
        solve();
    }
}