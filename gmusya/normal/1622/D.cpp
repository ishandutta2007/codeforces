#include <iostream>
#include <vector>
#include <string>

using namespace std;

using ll = long long;

const int MAX_N = 10000;

const ll MOD = 998244353;

ll fact[MAX_N + 1], inv_fact[MAX_N + 1];

ll BinPow(ll a, ll p) {
    if (!p) {
        return 1;
    }
    if (p & 1) {
        return BinPow(a, p - 1) * a % MOD;
    } else {
        ll x = BinPow(a, p / 2);
        return x * x % MOD;
    }
}

ll Inv(ll x) {
    return BinPow(x, MOD - 2);
}

ll CNK(int n, int k) {
    if (n < 0 || k < 0 || n - k < 0) {
        return 0;
    }
    return fact[n] * inv_fact[k] % MOD * inv_fact[n - k] % MOD;
}

void Init() {
    fact[0] = 1;
    for (int i = 1; i <= MAX_N; ++i) {
        fact[i] = fact[i - 1] * i % MOD;
    }
    inv_fact[MAX_N] = Inv(fact[MAX_N]);
    for (int i = MAX_N - 1; i >= 0; --i) {
        inv_fact[i] = inv_fact[i + 1] * (i + 1) % MOD;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    Init();
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    s = "0" + s + "0";
    n += 2;
    vector<int> cnt(n + 1);
    for (int i = 1; i <= n; ++i) {
        cnt[i] = cnt[i - 1] + (s[i - 1] == '1');
    }
    if (k == 0 || cnt[n] < k) {
        cout << 1;
        return 0;
    }
    ll ans = 1;
    for (int l = 1; l <= n; ++l) {
        for (int r = l + 3; r <= n; ++r) {
            int tmp = cnt[r - 1] - cnt[l];
            if (tmp > k) {
                continue;
            }
            int qwe = (s[l] == '0') + (s[r - 2] == '0');
            ll cur = CNK(r - l - 3, tmp - qwe);
            ans += cur;
        }
    }
    cout << ans % MOD;
    return 0;
}