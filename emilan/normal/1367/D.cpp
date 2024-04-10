#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using ii = pair<int, int>;
using vii = vector<ii>;

#define rep(i, n)   for (int i = 0; i < (n); i++)
#define sz(x)       (int)(x).size()
#define eb          emplace_back
#define pb          push_back
#define all(x)      (x).begin(), (x).end()
#define rall(x)     (x).rbegin(), (x).rend()
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
        string s;
        int m;
        cin >> s >> m;
        vi a(m);
        rep(i, m) cin >> a[i];

        vvi res;
        for (;;) {
            vi zero;
            rep(i, m) {
                if (a[i] == 0) {
                    zero.pb(i);
                    a[i] = -1;
                }
            }

            if (zero.empty()) break;

            res.pb({});
            for (int i : zero) {
                 res.back().pb(i);
                 rep(j, m) a[j] -= abs(i - j);
            }
        }

        string ans(m, '\0');
        map<char, int, greater<int>> f;
        for (char c : s) f[c]++;

        int i = 0;
        for (auto& j : f) {
            if (j.se < sz(res[i])) continue;

            for (int k : res[i]) ans[k] = j.fi;
            i++;
            if (i == sz(res)) break;
        }

        cout << ans << '\n';
    }

    return 0;
}