#include <bits/stdc++.h>
using namespace std;

int T, x[4], y[4], p[4];

int main() {
    scanf("%d", &T);
    while (T--) {
        for (int i = 0; i < 4; i++) {
            scanf("%d %d", &x[i], &y[i]);
        }
        iota(p, p + 4, 0);
        int mn = INT_MAX;
        vector<pair<int, int>> ans(4), tmp(4);
        auto chk = [&](int foo) {
            if (foo < mn) mn = foo, ans = tmp;
        };
        do {
            if (y[p[0]] == y[p[1]] && y[p[2]] == y[p[3]] && y[p[2]] < y[p[0]]) {
                int a = y[p[2]] - y[p[0]];
                vector<int> V = {x[p[0]], x[p[1]] - a, x[p[2]], x[p[3]] - a};
                auto q = minmax_element(V.begin(), V.end());
                int tx = (*q.first + *q.second) / 2, foo = 0;
                for (int x : V) foo = max(foo, abs(x - tx));
                tmp[p[0]] = {tx, y[p[0]]}, tmp[p[1]] = {tx + a, y[p[1]]};
                tmp[p[2]] = {tx, y[p[2]]}, tmp[p[3]] = {tx + a, y[p[3]]};
                chk(foo);
            }
            if (x[p[0]] == x[p[2]] && x[p[1]] == x[p[3]] && x[p[1]] > x[p[0]]) {
                int a = x[p[1]] - x[p[0]];
                vector<int> V = {y[p[0]] - a, y[p[1]] - a, y[p[2]], y[p[3]]};
                auto q = minmax_element(V.begin(), V.end());
                int ty = (*q.first + *q.second) / 2, foo = 0;
                for (int y : V) foo = max(foo, abs(y - ty));
                tmp[p[0]] = {x[p[0]], ty + a}, tmp[p[1]] = {x[p[1]], ty + a};
                tmp[p[2]] = {x[p[2]], ty}, tmp[p[3]] = {x[p[3]], ty};
                chk(foo);
            }
            auto solve = [&](int a, int x0, int y0) {
                int foo = 0;
                auto move = [&](int i, int tx, int ty) {
                    if (tx != x[i] && ty != y[i]) foo = INT_MAX;
                    else foo = max({foo, abs(tx - x[i]), abs(ty - y[i])});
                    tmp[i] = {tx, ty};
                };
                move(p[0], x0, y0 + a), move(p[1], x0 + a, y0 + a);
                move(p[2], x0, y0), move(p[3], x0 + a, y0);
                chk(foo);
            };
            for (int i = 0; i < 4; i++) for (int j = i + 1; j < 4; j++) {
                for (int k : {0, 1}) {
                    int a = !k ? abs(x[p[i]] - x[p[j]]) : abs(y[p[i]] - y[p[j]]);
                    for (int i = 0; i < 4; i++) for (int j = 0; j < 4; j++) if (i ^ j) {
                        int x0 = x[p[i]], y0 = y[p[j]];
                        solve(a, x0, y0);
                        solve(a, x0 - a, y0);
                        solve(a, x0, y0 - a);
                        solve(a, x0 - a, y0 - a);
                    }
                }
            }
        } while (next_permutation(p, p + 4));
        if (mn == INT_MAX) { puts("-1"); continue; }
        printf("%d\n", mn);
        for (auto p : ans) {
            printf("%d %d\n", p.first, p.second);
        }
    }
    return 0;
}