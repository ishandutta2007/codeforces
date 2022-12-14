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

const ll mod = 1e9 + 7;
const int maxn = 1e3;
ll inv[maxn], fact[maxn], finv[maxn];

ll C(int n, int r) {
    return fact[n] * finv[n - r] % mod * finv[r] % mod;
}

void solve() {
    int k;
    cin >> k;

    ll ans = 1;
    int sum = 0;
    while (k--) {
        int x;
        cin >> x;

        sum += x;
        ans = ans * C(sum - 1, x - 1) % mod;
    }

    cout << ans;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    inv[1] = fact[0] = fact[1] = finv[0] = finv[1] = 1;
    for (int i = 2; i < maxn; i++) {
        fact[i] = fact[i - 1] * i % mod;
        inv[i] = mod - mod / i * inv[mod % i] % mod;
        finv[i] = finv[i - 1] * inv[i] % mod;
    }

    int tcs = 1;
    for (int tc = 1; tc <= tcs; tc++) {
        // cout << "Case " << tc << ": ";
        solve();
    }
}