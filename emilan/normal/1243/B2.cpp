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
        string s, t;
        cin >> n >> s >> t;

        vii ops;
        rep(i, n) {
            if (s[i] != t[i]) {
                for (int j = i + 1; j < n; j++) {
                    if (t[j] == s[i]) {
                        ops.eb(j, j);
                        swap(s[j], t[j]);
                        break;
                    }
                }

                for (int j = i + 1; j < n; j++) {
                    if (s[j] == s[i]) {
                        ops.eb(j, i);
                        swap(s[j], t[i]);
                        break;
                    }
                }
            }
        }
        
        if (s == t) {
            cout << "Yes\n" << sz(ops) << '\n';
            rep(i, sz(ops))
                cout << ops[i].fi + 1 << ' ' << ops[i].se + 1 << '\n';
        } else cout << "No\n";
    }

    return 0;
}