#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for (cin >> t; t; t -= 1) {
        vector par(21, vector<pair<int, int>>(360));
        vector D(20, vector<int>(360)), R(21, vector<int>(360));
        int n;
        cin >> n;
        for (int i = 0; i < n; i += 1) {
            string s;
            cin >> s;
            if (s == "C") {
                int r, t1, t2;
                cin >> r >> t1 >> t2;
                for (int j = t1; j != t2; j = (j + 1) % 360)
                    D[r - 1][j] = 1;
            }
            else {
                int t, r1, r2;
                cin >> r1 >> r2 >> t;
                for (int j = r1; j < r2; j += 1)
                    R[j][(t + 359) % 360] = 1;
            }
        }
        for (int i = 0; i < 21; i += 1)
            for (int j = 0; j < 360; j += 1)
                par[i][j] = {i, j};
        function<pair<int, int>(pair<int, int>)> f = [&](pair<int, int> p) {
            auto [x, y] = p;
            return par[x][y] == p ? p : par[x][y] = f(par[x][y]);
        };
        auto merge = [&](pair<int, int> p, pair<int, int> q) {
            p = f(p);
            q = f(q);
            if (p != q) {
                auto [x, y] = p;
                par[x][y] = q;
            }
        };
        for (int i = 0; i < 20; i += 1)
            for (int j = 0; j < 360; j += 1)
                if (not D[i][j]) merge({i, j}, {i + 1, j});
        for (int i = 0; i <= 20; i += 1)
            for (int j = 0; j < 360; j += 1)
                if (not R[i][j]) merge({i, j}, {i, (j + 1) % 360});
        cout << (f({0, 0}) == f({20, 0}) ? "YES\n" : "NO\n");
    }
}