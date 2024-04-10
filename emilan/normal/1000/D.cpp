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

const int N = 1e3 + 1;
const ll mod = 998244353;
ll C[N][N], dp[N];

void solve() {
    int n;
    cin >> n;
    vt<int> a(n);
    for (int &x : a) cin >> x;

    C[0][0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            C[i + 1][j] = (C[i + 1][j] + C[i][j]) % mod;
            C[i + 1][j + 1] = (C[i + 1][j + 1] + C[i][j]) % mod;
        }
    }

    fill_n(dp, n - 1, 1);
    for (int i = 0; i < n; i++) {
        if (a[i] < 1) continue;

        for (int j = a[i] + 1; i + j <= n; j++) {
            dp[i + j] = (dp[i + j] + dp[i] * C[j - 1][a[i]]) % mod;
        }
    }

    cout << dp[n];
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int tcs = 1;
    for (int tc = 1; tc <= tcs; tc++) {
        solve();
    }
}