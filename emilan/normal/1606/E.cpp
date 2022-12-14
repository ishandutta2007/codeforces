#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll MOD = 998244353;
const int N = 501;

// dp[n][max_hp]
ll dp[N][N];

ll inv[N], fact[N], finv[N];

void comb_init() {
    inv[1] = fact[0] = finv[0] = 1;
    for (int i = 2; i < N; i++) {
        inv[i] = MOD - MOD / i * inv[MOD % i] % MOD;
    }
    for (int i = 1; i < N; i++) {
        fact[i] = fact[i - 1] * i % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

ll P(int n, int r) {
    return 0 <= r && r <= n ? fact[n] * finv[n - r] % MOD : 0;
}

ll C(int n, int r) {
    return 0 <= r && r <= n ? fact[n] * finv[n - r] % MOD * finv[r] % MOD : 0;
}

ll H(int n, int r) {
    return C(n + r - 1, r);
}

ll mod_pow(ll b, int e) {
    ll r = 1;
    for (; e; e /= 2, b = b * b % MOD) {
        if (e & 1) r = r * b % MOD;
    }
    return r;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, x;
    cin >> n >> x;

    comb_init();

    for (int u = 2; u <= n; u++) {
        for (int h = 1; h <= u - 1; h++) {
            dp[u][h] = mod_pow(h, u) - mod_pow(h - 1, u);
            if (dp[u][h] < 0) dp[u][h] += MOD;
        }
    }

    for (int u = 2; u <= n; u++) {
        for (int v = u; v <= n; v++) {
            for (int h = 1, nh = v; nh <= x; h++, nh++) {
                if (u == v) dp[v][nh] = (dp[v][nh] + dp[u][h]) % MOD;
                else {
                    dp[v][nh] = (dp[v][nh]
                        + dp[u][h] * C(v, u) % MOD * mod_pow(v - 1, u - v)
                    ) % MOD;
                }
            }
        }
    }

    ll sum = accumulate(dp[n] + 1, dp[n] + x + 1, 0ll) % MOD;
    cout << sum << '\n';
}