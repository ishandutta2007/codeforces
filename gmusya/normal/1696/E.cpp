#include <iostream>
#include <vector>

using namespace std;

using ll = long long;

const int MAXN = 5e5;
const ll MOD = 1e9 + 7;

ll fact[MAXN + 1], inv_fact[MAXN + 1];

ll BinPow(ll a, ll p) {
    if (!p) {
        return 1;
    }
    if (p & 1) {
        return BinPow(a, p - 1) * a % MOD;
    } else {
        ll b = BinPow(a, p / 2);
        return b * b % MOD;
    }
}

ll Inv(ll x) {
    return BinPow(x, MOD - 2);
}

void Init() {
    fact[0] = 1;
    for (int i = 1; i <= MAXN; ++i) {
        fact[i] = fact[i - 1] * i % MOD;
    }
    inv_fact[MAXN] = Inv(fact[MAXN]);
    for (int i = MAXN - 1; i >= 0; --i) {
        inv_fact[i] = inv_fact[i + 1] * (i + 1) % MOD;
    }
}

ll cnk(ll n, ll k) {
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
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    Init();
    int n;
    cin >> n;
    ++n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        --a[i];
    }
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += cnk(a[i] + i + 1, a[i]);
        ans %= MOD;
    }
    cout << ans;
    return 0;
}