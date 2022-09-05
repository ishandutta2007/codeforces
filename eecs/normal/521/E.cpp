#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010;
int n, m, dep[maxn], fa[maxn];
vector<int> G[maxn];
pair<int, int> cov[maxn];

vector<int> operator + (vector<int> V1, vector<int> V2) {
    for (int x : V2) V1.push_back(x);
    return V1;
}

int main() {
    scanf("%d %d", &n, &m);
    while (m--) {
        int u, v;
        scanf("%d %d", &u, &v);
        G[u].push_back(v), G[v].push_back(u);
    }
    auto print = [&](vector<int> V) {
        printf("%d", V.size());
        for (int x : V) printf(" %d", x);
        putchar('\n');
    };
    auto path = [&](int u, int v) {
        bool flag = 0;
        if (dep[u] < dep[v]) swap(u, v), flag = 1;
        vector<int> V;
        for (; u ^ v; u = fa[u]) V.push_back(u);
        V.push_back(u);
        if (flag) reverse(V.begin(), V.end());
        return V;
    };
    auto solve = [&](int v, int a, int b, int c, int d) {
        if (dep[b] < dep[d]) swap(a, c), swap(b, d);
        // v -> b; v -> a - b; v -> c - d -> b
        puts("YES");
        print(path(v, b));
        print(path(v, a) + vector<int>{b});
        print(path(v, c) + path(d, b));
    };
    function<void(int, int)> dfs = [&](int v, int f) {
        fa[v] = f, dep[v] = dep[f] + 1;
        for (int u : G[v]) if (u ^ f) {
            if (!dep[u]) { dfs(u, v); continue; }
            if (dep[u] > dep[v]) continue;
            for (int i = v; i ^ u; i = fa[i]) {
                if (!cov[i].first) cov[i] = {v, u};
                else solve(i, cov[i].first, cov[i].second, v, u), exit(0);
            }
        }
    };
    for (int i = 1; i <= n; i++) {
        if (!dep[i]) dfs(i, 0);
    }
    puts("NO");
    return 0;
}