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
    while (tcs--) {
        int n, m, k;
        cin >> n >> m >> k;
        vi a(n);
        rep(i, n) cin >> a[i];

        int ans = 1;
        int k1 = min(m - 1, k);
        rep(i, k1 + 1) {
            int l1 = i, r1 = n - k1 + i - 1;
            int mn = 1 << 30;
            rep(j, m - k1) {
                int l = l1 + j, r = r1 - (m - k1) + j + 1;
                int cur = 0;
                if (l < n) cur = a[l];
                if (r >= 0) cur = max(cur, a[r]);
                mn = min(cur, mn);
            }
            ans = max(mn, ans);
        }

        cout << ans << '\n';
    }

    return 0;
}