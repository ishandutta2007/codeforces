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
        int n;
        cin >> n;
        vi a(n);
        rep(i, n) cin >> a[i];

        int mx = 0;
        vvi p(201, vi(n));
        vvi pos(201);
        rep(i, 201) {
            int cur = 0;
            rep(j, n) {
                if (a[j] == i) {
                    cur++;
                    pos[i].pb(j);
                }
                p[i][j] = cur;
            }
            mx = max(mx, cur);
        }

        rep(i, 201) {
            int l = 0, r = sz(pos[i]) - 1, j = 0;
            while (l < r) {
                j++;

                int cnt = 0;
                rep(k, 201) {
                    cnt = max(cnt, p[k][pos[i][r] - 1] -
                                   p[k][pos[i][l]]);
                }

                mx = max(mx, cnt + j * 2);

                l++, r--;
            }
        }

        cout << mx << '\n';
    }

    return 0;
}