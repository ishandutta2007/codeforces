#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int n, m;

vector <int> dx = {0, 0, -1, 1};
vector <int> dy = {-1, 1, 0, 0};

bool good(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < m;
}

vector <pair <int, int>> wh[10];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int p;
    cin >> n >> m >> p;
    vector <int> s(p);
    for (int i = 0; i < p; ++i) cin >> s[i];
    vector <vector <int>> f(n, vector <int> (m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            char c;
            cin >> c;
            if ('1' <= c && c <= '9') {
                f[i][j] = (c - '0') - 1;
                wh[f[i][j]].emplace_back(i, j);
            }
            else if (c == '.') {
                f[i][j] = -1;
            }
            else {
                f[i][j] = -2;
            }
        }
    }
    vector <bool> st(p);
    int cur = -1;
    while (true) {
        ++cur;
        cur %= p;
        bool ok = false;
        for (int i = 0; i < p; ++i) {
            if (!st[i]) {
                ok = true;
            }
        }
        if (!ok) break;
        if (st[cur]) continue;
        queue <pair <int, int>> q;
        map <pair <int, int>, int> dst;
        for (auto p : wh[cur]) {
            q.push(p);
            dst[p] = 0;
        }
        vector <pair <int, int>> nw;
        while (!q.empty()) {
            auto p = q.front();
            q.pop();
            int x = p.first;
            int y = p.second;
            bool oki = false;
            for (int k = 0; k < 4; ++k) {
                int nx = x + dx[k];
                int ny = y + dy[k];
                if (good(nx, ny) && f[nx][ny] == -1 && !dst.count({nx, ny})) {
                    oki = true;
                    nw.push_back({nx, ny});
                    dst[{nx, ny}] = dst[{x, y}] + 1;
                    f[nx][ny] = cur;
                    if (dst[{nx, ny}] != s[cur]) q.push({nx, ny});
                }
            }
            if (oki) nw.push_back({x, y});
        }
        wh[cur] = nw;
        if (nw.empty()) st[cur] = 1;
    }
    vector <int> cnt(p);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (0 <= f[i][j]) {
                ++cnt[f[i][j]];
            }
        }
    }
    for (int i = 0; i < p; ++i) {
        cout << cnt[i] << ' ';
    }
}