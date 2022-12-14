#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;

#define rep(i, n)   for (int i = 0; i < (n); i++)
#define sz(x)       (int)(x).size()
#define all(x)      (x).begin(), (x).end()
#define rall(x)     (x).rbegin(), (x).rend()
#define fi          first
#define se          second

int const mod = 998244353;

ll iv(ll a, ll b) {
    return a > 1 ? b - iv(b % a, a) * b / a : 1;
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;
    
    ll ans = m;
    rep(i, k) ans = ans * (m - 1) % mod;
    for (int i = 1; i <= k; i++) {
        ans = ans * (n - i) % mod * iv(i, mod) % mod;
    }
    cout << ans;
}