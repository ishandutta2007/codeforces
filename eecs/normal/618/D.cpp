#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010;
int n, x, y, all, solved[maxn], d[maxn];
vector<int> G[maxn];

int main() {
    scanf("%d %d %d", &n, &x, &y);
    for (int _ = 1, u, v; _ < n; _++) {
        scanf("%d %d", &u, &v);
        G[u].push_back(v), G[v].push_back(u);
    }
    if (x > y) {
        bool flag = 0;
        for (int i = 1; i <= n; i++) {
            if (G[i].size() == n - 1) flag = 1;
        }
        if (n == 2) {
            printf("%d\n", x);
        } else if (n == 3) {
            printf("%d\n", x + y);
        } else if (flag) {
            printf("%lld\n", 1LL * (n - 2) * y + x);
        } else {
            printf("%lld\n", 1LL * (n - 1) * y);
        }
        exit(0);
    }
    function<void(int, int)> dfs = [&](int v, int fa) {
        vector<int> V;
        for (int u : G[v]) if (u ^ fa) {
            dfs(u, v);
            if (!solved[u]) V.push_back(u);
        }
        if (V.size() == 1) {
            d[v] = d[V[0]] + 1;
        } else if (!V.empty()) {
            d[v] = d[V[0]] + d[V[1]] + 2;
            solved[v] = 1, all += d[v];
            for (int i = 2; i < V.size(); i++) all += d[V[i]];
        }
    };
    dfs(1, 0);
    if (!solved[1]) all += d[1];
    printf("%lld\n", 1LL * all * x + 1LL * (n - all - 1) * y);
    return 0;
}