#pragma GCC optimize("O3")

#include <iostream>
#include <vector>

using namespace std;

using ll = long long;

const ll MOD = 1e9 + 7;
const ll MAX_POW = 250 * 250;

ll N, K;
ll fact[MAX_POW + 1], inv_fact[MAX_POW + 1];
ll powers[MAX_POW + 1];

ll BinPow(ll a, ll p) {
    if (!p) {
        return 1;
    }
    if (p & 1) {
        return BinPow(a, p - 1) * a % MOD;
    } else {
        ll tmp = BinPow(a, p / 2);
        return tmp * tmp % MOD;
    }
}

ll Inv(ll x) {
    return BinPow(x, MOD - 2);
}

void Init() {
    fact[0] = 1;
    for (int i = 1; i <= MAX_POW; ++i) {
        fact[i] = fact[i - 1] * i % MOD;
    }
    inv_fact[MAX_POW] = Inv(fact[MAX_POW]);
    for (int i = MAX_POW - 1; i >= 0; --i) {
        inv_fact[i] = inv_fact[i + 1] * (i + 1) % MOD;
    }
    powers[0] = 1;
    for (int i = 1; i <= MAX_POW; ++i) {
        powers[i] = powers[i - 1] * (K - 1) % MOD;
    }
}

ll CNK(ll n, ll k) {
    if (n < 0 || k < 0 || n - k < 0) {
        return 0;
    }
    ll res = fact[n];
    res *= inv_fact[k];
    res %= MOD;
    res *= inv_fact[n - k];
    res %= MOD;
    return res;
}

int main() {
    cin >> N >> K;
    Init();
    vector<vector<ll>> dp(N + 1, vector<ll>(N + 1));
    for (int i = 1; i <= N; ++i) {
        dp[1][i] = dp[i][1] = 1;
    }
    vector<vector<ll>> c(N + 1, vector<ll>(N + 1));
    for (int n = 0; n <= N; ++n) {
        for (int k = 0; k <= N; ++k) {
            for (int i = 1; i <= n; ++i) {
                c[n][k] += CNK(n, i) * CNK(i, k) % MOD * powers[n - i];
                c[n][k] %= MOD;
            }
        }
    }
    for (int h = 2; h <= N; ++h) {
        for (int w = 2; w <= N; ++w) {
            for (int old_w = w; old_w >= 1; --old_w) {
                int n = w;
                int k = w - old_w;
                dp[h][w] += c[n][k] * dp[h - 1][old_w] % MOD * powers[(h - 1) * k];
                dp[h][w] %= MOD;
            }
        }
    }
    cout << dp[N][N];
    return 0;
}