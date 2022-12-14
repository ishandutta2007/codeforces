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

    int tcs;
    cin >> tcs;
    rep(tc, tcs) {
        ll l, r, m;
        cin >> l >> r >> m;
        ll d = r - l;

        for (int i = l; i <= r; i++) {
            ll div = m / i;
            if (m - div * i <= d && div != 0) {
                cout << i << ' ' << m - div * i + l << ' ' << l << '\n';
                break;
            } else if ((div + 1) * i - m <= d) {
                cout << i << ' ' << l << ' ' << (div + 1) * i - m + l << '\n';
                break;
            }
        }
    }

    return 0;
}