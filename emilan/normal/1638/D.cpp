#include <bits/stdc++.h>

using namespace std;

#define REP(i, n)   for (int i = 0; (i) < n; (i)++)
#define SZ(a)       int(size(a))
#define ALL(a)      begin(a), end(a)
#define RALL(a)     rbegin(a), rend(a)

using uint = unsigned;
using ll = long long;
using ull = unsigned long long;
using i128 = __int128_t;
using u128 = __uint128_t;
using ld = long double;
using pii = pair<int, int>;

using A3 = array<int, 3>;

vector<A3> solve() {
    int n, m;
    cin >> n >> m;
    vector a(n, vector<int>(m));
    for (auto &v : a) {
        for (auto &x : v) cin >> x;
    }

    auto check = [&](int i, int j) {
        int color = 0;
        REP(di, 2) REP(dj, 2) if (int c = a[i + di][j + dj]; c != 0) {
            if (color != 0 && color != c) return false;
            color = c;
        }
        return true;
    };

    auto in_bounds = [&](int i, int j) {
        return 0 <= i && i < n - 1 && 0 <= j && j < m - 1;
    };

    vector<A3> ans;
    auto paint = [&](int i, int j) {
        int color = 0;
        REP(di, 2) REP(dj, 2) if (int &c = a[i + di][j + dj]; c != 0) {
            color = c;
            c = 0;
        }
        if (color != 0) ans.push_back({i, j, color});
    };

    queue<pii> q;
    vector vis(n - 1, vector<bool>(m - 1));
    REP(i, n - 1) REP(j, m - 1) {
        if (check(i, j)) {
            paint(i, j);
            q.emplace(i, j);
            vis[i][j] = true;
        }
    }

    while (!q.empty()) {
        auto [i, j] = q.front();
        q.pop();

        for (int ni = i - 1; ni <= i + 1; ni++) {
            for (int nj = j - 1; nj <= j + 1; nj++) {
                if (in_bounds(ni, nj) && !vis[ni][nj] && check(ni, nj)) {
                    paint(ni, nj);
                    q.emplace(ni, nj);
                    vis[ni][nj] = true;
                }
            }
        }
    }

    if (any_of(ALL(vis), [](const auto &v) { return count(ALL(v), false); })) {
        return {};
    } else {
        return vector(RALL(ans));
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    auto ans = solve();
    if (ans.empty()) cout << "-1\n";
    else {
        cout << SZ(ans) << '\n';
        for (auto [i, j, c] : ans) {
            cout << i + 1 << ' ' << j + 1 << ' ' << c << '\n';
        }
    }
}