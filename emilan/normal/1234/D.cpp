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

    string s;
    int q;
    cin >> s >> q;

    map<char, set<int>> m;
    rep(i, sz(s)) m[s[i]].insert(i);

    while (q--) {
        int t;
        cin >> t;

        if (t == 1) {
            int p;
            char c;
            cin >> p >> c;
            p--;
            m[s[p]].erase(p);
            m[c].insert(p);
            s[p] = c;
        } else {
            int l, r;
            cin >> l >> r;
            l--, r--;

            int cnt = 0;
            rep(i, 26) {
                char c = 'a' + i;
                auto it = m[c].lower_bound(l);
                if (it != m[c].end() && *it <= r) cnt++;
            }
            cout << cnt << '\n';
        }
    }

    return 0;
}