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

    vii adj{{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

    int tcs;
    cin >> tcs;
    while (tcs--) {
        int n, m;
        cin >> n >> m;
        vector<string> v(n);
        rep(i, n) cin >> v[i];

        bool ok = true;
        function<void(int, int)> dfs = [&](int x, int y) {
            for (auto& i : adj) {
                int rx = x + i.fi, ry = y + i.se;
                if (rx < 0 || ry < 0 || rx == n || ry == m) continue;

                char& t = v[rx][ry];
                if (t == 'G') ok = false;
                else if (t == '.') t = '#';
                else if (t == 'B') {
                    t = 'N';
                    dfs(rx, ry);
                }
            }
        };

        int good = 0;
        rep(i, n) rep(j, m) {
            if (v[i][j] == 'B') {
                v[i][j] == 'N';
                dfs(i, j);
            } else if (v[i][j] == 'G') good++;
        }

        if (!ok || (v.back().back() == '#' && good)) cout << "No";
        else {
            function<void(int, int)> dfs2 = [&](int x, int y) {
                for (auto& i : adj) {
                    int rx = x + i.fi, ry = y + i.se;
                    if (rx < 0 || ry < 0 || rx == n || ry == m) continue;

                    char& t = v[rx][ry];
                    if (t == 'G') good--;
                    if (t != '#') {
                        t = '#';
                        dfs2(rx, ry);
                    }
                }
            };
            dfs2(n - 1, m - 1);
            cout << (good ? "No" : "Yes");
        }
        cout << '\n';
    }

    return 0;
}