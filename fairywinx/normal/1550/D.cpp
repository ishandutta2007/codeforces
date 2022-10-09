#include <bits/stdc++.h>

#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define SOLVE int t; cin >> t; while(t--) solve();

using namespace std;

const int mod = 1e9 + 7;
const int N = 2e5 + 228;

int powm(int a, int b) {
    if (b == 0)
        return 1;
    if (b % 2 == 1)
        return 1ll * a * powm(a, b - 1) % mod;
    int z = powm(a, b / 2);
    return 1ll * z * z % mod;
}

int fact[N];
int _fact[N];

int C(int n, int k) {
    return (1ll * fact[n] * _fact[k] % mod) * _fact[n - k] % mod;
}

void solve() {


    int n, l, r;
    cin >> n >> l >> r;
    if (n % 2 == 0) {
        int ind1 = min(r - n, 1 - l);
        long long ans = 1ll * ind1 * C(n, n / 2) % mod;
        for (int d = ind1 + 1;; ++d) {
            int i = max(l + d, 1), j = min(r - d, n);
            if (n / 2 - i + 1 < 0 || j - i + 1 < 0 || j < n / 2)
                break;
            ans = (ans + C(j - i + 1, n / 2 - i + 1)) % mod;
        }
        cout << ans << '\n';
    } else {
        int ind1 = min(r - n, 1 - l);
        long long ans = 2ll * ind1 * C(n, n / 2) % mod;
        for (int d = ind1 + 1;; ++d) {
            int i = max(l + d, 1), j = min(r - d, n);
            // cout << i << ' ' << j << '\n';
            if (n / 2 - i + 1 < 0 || j - i + 1 < 0 || j < n / 2)
                break;
            // cout << C(j - i + 1, n / 2 - i + 1) << '\n';
            ans = (ans + C(j - i + 1, n / 2 - i + 1)) % mod;
        }
        for (int d = ind1 + 1;; ++d) {
            int i = max(l + d, 1), j = min(r - d, n);
            if (n / 2 - i + 1 + 1 < 0 || j - i + 1 < 0 || j < n / 2 + 1)
                break;
            ans = (ans + C(j - i + 1, n / 2 - i + 1 + 1)) % mod;
        }
        cout << ans << '\n';
    }
}

signed main() {
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);

    fact[0] = 1;
    for (int i = 1; i < N; ++i) {
        fact[i] = 1ll * fact[i - 1] * i % mod;
    }
    for (int i = 0; i < N; ++i) {
        _fact[i] = powm(fact[i], mod - 2);
    }

    SOLVE
}