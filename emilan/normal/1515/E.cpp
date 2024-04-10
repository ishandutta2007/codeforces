#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int N = 401;
ll dp[2][N][N];
ll inv[N], fact[N];

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int n;
    ll M;
    cin >> n >> M;

    inv[1] = fact[0] = 1;
    for (int i = 2; i < N; i++) {
        inv[i] = M - M / i * inv[M % i] % M;
    }
    for (int i = 1; i < N; i++) {
        fact[i] = fact[i - 1] * i % M;
    }

    dp[1][1][1] = 1;
    for (int i = 1, t = 1; i < n; i++, t ^= 1) {
        for (int j = n - 1; j > 0; j--) {
            for (int k = 1; k < n; k++) {
                ll &x = dp[t ^ 1][j + 1][k + 1];
                x = (x + dp[t][j][k] * 2 * inv[k + 1]) % M;

                ll &y = dp[t][j + 1][1];
                y = (y + dp[t][j][k]) % M;

                dp[t][j][k] = 0;
            }
        }
    }

    ll ans = 0;
    for (int j = 1; j <= n; j++) {
        for (int k = 0; k <= n; k++) {
            ans = (ans + dp[n & 1][j][k] * fact[j]) % M;
        }
    }
    cout << ans;
}