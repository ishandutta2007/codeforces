#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = int64_t;
using ld = long double;
using pii = pair<int, int>;

constexpr int mod = 998244353;
inline int binpow(int x, int deg) {
    int ans = 1;
    while (deg > 0) {
        if (deg & 1)
            ans = ans * ll(x) % mod;
        deg >>= 1;
        x = x * ll(x) % mod;
    }
    return ans;
}
inline int invv(int x) {
    return binpow(x, mod - 2);
}

int inv[200200];
int d[200200], pref[200200];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    inv[1] = 1;
    for (int i = 2; i < 200200; ++i)
        inv[i] = inv[mod % i] * (ll)(mod - mod / i) % mod;

    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        cin >> d[i];
    sort(d + 1, d + n + 1);
    for (int i = 1; i <= n; ++i)
        pref[i] = (pref[i - 1] + d[i]) % mod;

    while (m--) {
        int a, b;
        cin >> a >> b;
        int first_big = lower_bound(d + 1, d + n + 1, b) - d;
        int cnt = n + 1 - first_big;
        if (cnt < a) {
            cout << "0\n";
            continue;
        }
        int ans = (pref[n] + mod - pref[first_big - 1]) * ll(cnt - a) % mod * inv[cnt] % mod;
        int ans2 = pref[first_big - 1] * ll(cnt + 1 - a) % mod * inv[cnt + 1] % mod;
        ans = (ans + ans2) % mod;
        cout << ans << '\n';
    }
}