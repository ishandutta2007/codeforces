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

        map<char, int> m;
        for (int i = sz(s) - 1; i > 0; i--) {
            if (!m.count(s[i])) m[s[i]] = i;
        }

        rep(i, sz(s)) {
            for (auto& j : m) {
                if (i < j.se && s[i] > j.fi) {
                    swap(s[i], s[j.se]);
                    goto A;
                }
            }
        }
        A:

        if (s < t) cout << s;
        else cout << "---";
        cout << '\n';
    }

    return 0;
}