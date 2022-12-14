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

vii adj{{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<string> v(n);
    for (auto& i : v) cin >> i;
    
    vvi d(n, vi(m));
    queue<ii> q;
    rep(i, n) rep(j, m) {
        bool ok = false;
        for (auto& k : adj) {
            int x = i + k.fi, y = j + k.se;
            if (x == -1 || y == -1 || x == n || y == m ||
                v[i][j] != v[x][y]) {
                ok = true;
                break;
            }
        }
        if (ok) {
            d[i][j] = 1;
            q.emplace(i, j);
        }
    }

    ll sum = n * m;
    while (!q.empty()) {
        auto cur = q.front();
        q.pop();

        int step = d[cur.fi][cur.se];

        for (auto& i : adj) {
            int x = cur.fi + i.fi, y = cur.se + i.se;
            if (x == -1 || y == -1 || x == n || y == m) continue;
            if (d[x][y]) continue;

            d[x][y] = step + 1;
            sum += step;
            q.emplace(x, y);
        }
    }

    cout << sum;

    return 0;
}