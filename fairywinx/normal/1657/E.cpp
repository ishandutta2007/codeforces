#include <bits/stdc++.h>

#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define SOLVE int t; cin >> t; while (t--) solve();

using namespace std;

const int mod = 998244353;
const int N = 555;
int fact[N];
int _fact[N];
int _val[N];

int powm(int a, int b) {
    if (b == 0) {
        return 1;
    }
    if (b % 2 == 1) {
        return 1ll * powm(a, b - 1) * a % mod;
    }
    int z = powm(a, b / 2);
    return 1ll * z * z % mod;
}

int C(int n, int k) {
    return (1ll * fact[n] * _fact[n - k] % mod) * 1ll * fact[k] % mod;
}

void solve() {
    int n, k;
    cin >> n >> k;
    fact[0] = _fact[0] = 1;
    for (int i = 1; i <= n; ++i) {
        fact[i] = 1ll * fact[i - 1] * i % mod;
        _fact[i] = powm(fact[i], mod - 2);
        _val[i] = powm(i, mod - 2);
    }
    vector<vector<vector<int>>> dp(n, vector<vector<int>> (k + 1, vector<int> (n + 1)));
    vector<vector<int>> pref(n, vector<int> (k + 1));
    for (int i = 1; i <= k; ++i) {
        pref[1][i] = i;
        dp[1][i][1] = 1;
    }
    for (int i = 2; i < n; ++i) {
        for (int j = 1; j <= k; ++j) {
            int sum = 0;
            dp[i][j][1] = 1ll * pref[i - 1][j - 1] * C(i, 1) % mod;
            for (int cnt = 2; cnt <= i; ++cnt) {
                dp[i][j][cnt] = (1ll * dp[i - 1][j][cnt - 1] * i % mod) * 1ll * _val[cnt] % mod;
            }
            pref[i][j] = pref[i][j - 1];
            for (int cnt = 1; cnt <= i; ++cnt) {
                dp[i][j][cnt] = 1ll * dp[i][j][cnt] * powm((k - j + 1), i - 1) % mod;
                pref[i][j] += dp[i][j][cnt];
                if (pref[i][j] >= mod)
                    pref[i][j] -= mod;
            }
        }
    }
    cout << pref[n - 1][k] << '\n';
}

signed main() {
    #ifndef LOCAL
        ios_base::sync_with_stdio(0);
        cin.tie(0);
    #endif
    #ifdef DEBUG
        freopen("main/in.txt", "r", stdin);
    #endif

    // SOLVE
    solve();
}