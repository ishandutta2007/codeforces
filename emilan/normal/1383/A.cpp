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
        int n;
        string a, b;
        cin >> n >> a >> b;

        set<pair<char, char>> s;
        bool ok = true;
        rep(i, n) {
            if (a[i] > b[i]) {
                ok = false;
                break;
            } else if (a[i] < b[i]) s.emplace(a[i], b[i]);
        }

        if (ok) {
            int mv = 0;
            while (!s.empty()) {
                char c = s.begin()->fi;
                char t = s.begin()->se;
                auto it = s.begin();
                while (it != s.end() && it->fi == c) {
                    auto it2 = it;
                    it++;
                    if (t != it2->se) s.emplace(t, it2->se);
                    s.erase(it2);
                }

                mv++;
            }

            cout << mv;
        } else cout << -1;
        cout << '\n';
    }

    return 0;
}