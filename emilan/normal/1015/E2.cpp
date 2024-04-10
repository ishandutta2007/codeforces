#include <bits/stdc++.h>
using namespace std;

#define vt          vector
#define sz(x)       int((x).size())
#define all(x)      (x).begin(), (x).end()
#define rall(x)     (x).rbegin(), (x).rend()
#define fi          first
#define se          second

using ll = long long;
using pii = pair<int, int>;

const int maxn = 1002;
int u[maxn][maxn],
    d[maxn][maxn],
    l[maxn][maxn],
    r[maxn][maxn],
    s[maxn][maxn];

struct Tri {
    int x, y, z;
};

void solve() {
    int n, m;
    cin >> n >> m;
    vt<string> v(n);
    for (auto &i : v) cin >> i;

    memset(u, -1, sizeof(u));
    memset(d, -1, sizeof(d));
    memset(l, -1, sizeof(l));
    memset(r, -1, sizeof(r));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (v[i][j] == '*') {
                u[i + 1][j + 1] = u[i][j + 1] + 1;
                l[i + 1][j + 1] = l[i + 1][j] + 1;
            }
        }
    }

    for (int i = n - 1; i >= 0; i--) {
        for (int j = m - 1; j >= 0; j--) {
            if (v[i][j] == '*') {
                d[i + 1][j + 1] = d[i + 2][j + 1] + 1;
                r[i + 1][j + 1] = r[i + 1][j + 2] + 1;
            }
        }
    }

    vt<Tri> ans;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (v[i][j] == '*' &&
                    u[i + 1][j + 1] &&
                    d[i + 1][j + 1] &&
                    l[i + 1][j + 1] &&
                    r[i + 1][j + 1]) {
                v[i][j]++;
                s[i][j] = min({
                    u[i + 1][j + 1],
                    d[i + 1][j + 1],
                    l[i + 1][j + 1],
                    r[i + 1][j + 1]
                });

                ans.push_back({i + 1, j + 1, s[i][j]});
            }
        }
    }

    for (int i = 0; i < n; i++) {
        int cur = 0;
        for (int j = 0; j < m; j++) {
            if (s[i][j]) cur = max(cur, s[i][j] + 1);
            else if (v[i][j] == '.') cur = 0;

            if (cur) v[i][j]++, cur--;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int cur = 0, j = m - 1; j >= 0; j--) {
            if (s[i][j]) cur = max(cur, s[i][j] + 1);
            else if (v[i][j] == '.') cur = 0;

            if (cur) v[i][j]++, cur--;
        }
    }

    for (int j = 0; j < m; j++) {
        int cur = 0;
        for (int i = 0; i < n; i++) {
            if (s[i][j]) cur = max(cur, s[i][j] + 1);
            else if (v[i][j] == '.') cur = 0;

            if (cur) v[i][j]++, cur--;
        }
    }

    for (int j = 0; j < m; j++) {
        int cur = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (s[i][j]) cur = max(cur, s[i][j] + 1);
            else if (v[i][j] == '.') cur = 0;

            if (cur) v[i][j]++, cur--;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (v[i][j] == '*') return void(cout << -1);
        }
    }

    cout << sz(ans) << '\n';
    for (Tri &i : ans) cout << i.x << ' ' << i.y << ' ' << i.z << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int tcs = 1;
    for (int tc = 1; tc <= tcs; tc++) {
        // cout << "Case " << tc << ": ";
        solve();
    }
}