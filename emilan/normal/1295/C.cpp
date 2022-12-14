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
        string s, t;
        cin >> s >> t;
        map<char, vi> v;
        rep(i, sz(s)) v[s[i]].pb(i);

        int cnt = 1, i = -1;
        for (char c : t) {
            if (v[c].empty()) {
                cnt = -1;
                break;
            }

            auto it = upper_bound(all(v[c]), i);
            if (it == v[c].end()) {
                it = v[c].begin();
                cnt++;
            }
            i = *it;
        }

        cout << cnt << '\n';
    }

    return 0;
}