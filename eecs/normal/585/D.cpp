#include <bits/stdc++.h>
using namespace std;

int n, x[30], y[30], z[30], tmp[30];
string str[30];
map<pair<int, int>, pair<int, int>> mp;
tuple<int, int, int> ans(INT_MIN, 0, 0);

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d %d %d", &x[i], &y[i], &z[i]);
    }
    int m = (n + 1) / 2;
    function<void(int, int, int, int, int)> dfs1 = [&](int i, int a, int b, int c, int S) {
        if (i > m) {
            auto p = make_pair(b - a, c - a), q = make_pair(a, S);
            if (!mp.count(p) || mp[p] < q) mp[p] = q;
            return;
        }
        dfs1(i + 1, a + x[i], b + y[i], c, S * 3);
        dfs1(i + 1, a + x[i], b, c + z[i], S * 3 + 1);
        dfs1(i + 1, a, b + y[i], c + z[i], S * 3 + 2);
    };
    dfs1(1, 0, 0, 0, 0);
    function<void(int, int, int, int, int)> dfs2 = [&](int i, int a, int b, int c, int S) {
        if (i > n) {
            auto p = make_pair(a - b, a - c);
            if (mp.count(p)) ans = max(ans, make_tuple(mp[p].first + a, mp[p].second, S));
            return;
        }
        dfs2(i + 1, a + x[i], b + y[i], c, S * 3);
        dfs2(i + 1, a + x[i], b, c + z[i], S * 3 + 1);
        dfs2(i + 1, a, b + y[i], c + z[i], S * 3 + 2);
    };
    dfs2(m + 1, 0, 0, 0, 0);
    if (get<0>(ans) == INT_MIN) puts("Impossible"), exit(0);
    for (int i = m, j = get<1>(ans); i; i--, j /= 3) {
        if (j % 3 == 0) str[i] = "LM";
        if (j % 3 == 1) str[i] = "LW";
        if (j % 3 == 2) str[i] = "MW";
    }
    for (int i = n, j = get<2>(ans); i > m; i--, j /= 3) {
        if (j % 3 == 0) str[i] = "LM";
        if (j % 3 == 1) str[i] = "LW";
        if (j % 3 == 2) str[i] = "MW";
    }
    for (int i = 1; i <= n; i++) {
        printf("%s\n", str[i].c_str());
    }
    return 0;
}