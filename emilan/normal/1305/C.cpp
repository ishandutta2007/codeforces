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
    
    if (n > m) {
        cout << 0;
        return 0;
    }

    vi a(n);
    rep(i, n) cin >> a[i];
    ll ret = 1;
    rep(i, n) {
        for (int j = i + 1; j < n; j++) {
            ret = ret * abs(a[i] - a[j]) % m;
        }
    }
    cout << ret;

    return 0;
}