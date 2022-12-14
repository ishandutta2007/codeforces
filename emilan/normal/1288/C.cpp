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

const int mod(1000000007);

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
#ifdef LOCAL
    freopen("io\\in.txt", "r", stdin);
    freopen("io\\out.txt", "w", stdout);
#endif

    int n, m;
    cin >> n >> m;

    vector<ll> iv(2 * m + 1);
    iv[1] = 1;
    for (int i = 2; i < sz(iv); i++) {
        iv[i] = (mod - mod / i * iv[mod % i] % mod) % mod;
    }

    ll ans = 1;
    for (int i = 1; i <= 2 * m; i++) {
        ans = ans * (n + 2 * m - i) % mod * iv[i] % mod;
    }

    cout << ans;

    return 0;
}