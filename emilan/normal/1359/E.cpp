#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define vt          vector
#define sz(x)       (int)(x).size()
#define all(x)      (x).begin(), (x).end()
#define rall(x)     (x).rbegin(), (x).rend()
#define fi          first
#define se          second

const int mod = 998244353;
ll f[500001];

ll iv(ll a, ll b = mod) {
    return a > 1 ? b - iv(b % a, a) * b / a : 1;
}

void solve(int tc) {
    int n, k;
    cin >> n >> k;

    f[0] = 1;
    for (int i = 1; i <= n; i++) f[i] = f[i - 1] * i % mod;

    ll ans = 0, cur;
    for (int i = 1; (cur = n / i - 1) >= k - 1; i++) {
        ans = (ans + 
                f[cur] * iv(f[k - 1]) % mod * iv(f[cur - k + 1])) % mod;
    }
    cout << ans;
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int tcs = 1;
    for (int tc = 1; tc <= tcs; tc++) solve(tc);
}