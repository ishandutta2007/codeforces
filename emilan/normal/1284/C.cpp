#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using ii = pair<int, int>;
using vii = vector<ii>;

#define rep(i, n)   for (int i = 0; i < (n); i++)
#define sz(x)       (int)x.size()
#define eb          emplace_back
#define pb          push_back
#define all(x)      x.begin(), x.end()
#define rall(x)     x.rbegin(), x.rend()
#define fi          first
#define se          second

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
#ifdef LOCAL
    freopen("io\\in.txt", "r", stdin);
    freopen("io\\out.txt", "w", stdout);
#endif

    int n, m;
    cin >> n >> m;

    vector<ll> f(n + 1);
    f[0] = f[1] = 1;
    for (int i = 2; i <= n; i++) {
        f[i] = f[i - 1] * i % m;
    }

    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = (ans + f[i] * f[n - i] % m * (n - i + 1) % m * (n - i + 1)) % m;
    }

    cout << ans;

    return 0;
}