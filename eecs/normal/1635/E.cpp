#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010;
int n, m, tot, dir[maxn], pos[maxn], d[maxn];
vector<array<int, 2>> G[maxn];
vector<int> H[maxn];

int main() {
    scanf("%d %d", &n, &m);
    while (m--) {
        int type, i, j;
        scanf("%d %d %d", &type, &i, &j);
        G[i].push_back({j, type}), G[j].push_back({i, type});
    }
    memset(dir, -1, sizeof(dir));
    for (int i = 1; i <= n; i++) if (!~dir[i]) {
        function<void(int)> dfs = [&](int u) {
            for (auto &e : G[u]) {
                int v = e[0];
                if (!~dir[v]) dir[v] = !dir[u], dfs(v);
                if (dir[u] == dir[v]) puts("NO"), exit(0);
            }
        };
        dir[i] = 0, dfs(i);
    }
    for (int i = 1; i <= n; i++) if (dir[i]) {
        for (auto &e : G[i]) {
            int j = e[0];
            if (e[1] == 1) H[i].push_back(j), d[j]++;
            else H[j].push_back(i), d[i]++;
        }
    }
    queue<int> Q;
    for (int i = 1; i <= n; i++) {
        if (!d[i]) Q.push(i);
    }
    while (!Q.empty()) {
        int u = Q.front(); Q.pop(), pos[u] = ++tot;
        for (int v : H[u]) if (!--d[v]) Q.push(v);
    }
    if (count(d + 1, d + n + 1, 0) < n) puts("NO"), exit(0);
    puts("Yes");
    for (int i = 1; i <= n; i++) {
        printf("%c %d\n", dir[i] ? 'L' : 'R', pos[i]);
    }
    return 0;
}