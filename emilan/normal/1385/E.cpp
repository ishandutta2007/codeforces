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

    int tcs;
    cin >> tcs;
    while (tcs--) {
        int n, m;
        cin >> n >> m;
        vi in(n);
        vvi to(n);
        vii ret;
        vector<set<int>> uni(n);
        rep(i, m) {
            int t, x, y;
            cin >> t >> x >> y;
            x--, y--;
            if (t) {
                in[y]++;
                to[x].pb(y);
                ret.eb(x, y);
            } else {
                uni[x].insert(y);
                uni[y].insert(x);
            }
        }

        int cnt = 0;
        queue<int> gud;
        rep(i, n) if (!in[i]) gud.push(i);
        while (!gud.empty()) {
            int cur = gud.front();
            gud.pop();

            cnt++;

            for (int i : uni[cur]) {
                uni[i].erase(cur);

                ret.eb(cur, i);
            }

            for (int i : to[cur]) {
                in[i]--;
                if (!in[i]) gud.push(i);
            }
        }

        if (cnt != n) cout << "NO\n";
        else {
            cout << "YES\n";
            for (auto& i : ret) cout << i.fi + 1 << ' ' << i.se + 1 << '\n';
        }
    }

    return 0;
}