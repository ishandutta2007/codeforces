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

    int n;
    cin >> n;
    vector<string> v(n);
    rep(i, n) cin >> v[i];

    vector<set<int>> from(26), to(26);
    rep(i, n - 1) {
        int j, mx = min(sz(v[i]), sz(v[i + 1]));
        for (j = 0; j < mx; j++) {
            int f = v[i][j] - 'a', t = v[i + 1][j] - 'a';
            if (f != t) {
                to[f].insert(t);
                from[t].insert(f);
                break;
            }
        }

        if (j == mx && sz(v[i]) > sz(v[i + 1])) {
            return cout << "Impossible", 0;
        }
    }

    vi ans;
    vector<bool> ok(26);
    rep(i, 26) {
        rep(j, 26) {
            if (!from[j].empty() || ok[j]) continue;

            ok[j] = true;
            ans.pb(j);
            for (int k : to[j]) {
                from[k].erase(j);
            }
        }
    }

    if (sz(ans) != 26) cout << "Impossible";
    else for (int i : ans) cout << char('a' + i);

    return 0;
}