#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000010;
int n, m, fa[maxn], f[maxn], d[maxn];
vector<int> G[maxn];

int id(int x, int y) {
    return (x - 1) * m + y;
}

int find(int x) {
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}

void unite(int x, int y) {
    fa[find(x)] = find(y);
}

int main() {
    scanf("%d %d", &n, &m);
    iota(fa + 1, fa + n * m + 1, 1);
    auto a = vector<vector<int>>(n + 1, vector<int>(m + 1));
    vector<pair<int, int>> E;
    for (int i = 1; i <= n; i++) {
        vector<int> V;
        for (int j = 1; j <= m; j++) {
            scanf("%d", &a[i][j]), V.push_back(j);
        }
        sort(V.begin(), V.end(), [&](int x, int y) { return a[i][x] < a[i][y]; });
        for (int j = 1; j < V.size(); j++) {
            if (a[i][V[j - 1]] == a[i][V[j]]) unite(id(i, V[j - 1]), id(i, V[j]));
            else E.emplace_back(id(i, V[j - 1]), id(i, V[j]));
        }
    }
    for (int i = 1; i <= m; i++) {
        vector<int> V;
        for (int j = 1; j <= n; j++) {
            V.push_back(j);
        }
        sort(V.begin(), V.end(), [&](int x, int y) { return a[x][i] < a[y][i]; });
        for (int j = 1; j < V.size(); j++) {
            if (a[V[j - 1]][i] == a[V[j]][i]) unite(id(V[j - 1], i), id(V[j], i));
            else E.emplace_back(id(V[j - 1], i), id(V[j], i));
        }
    }
    for (auto e : E) {
        int u = find(e.first), v = find(e.second);
        G[u].push_back(v), d[v]++;
    }
    queue<int> Q;
    fill(f + 1, f + n * m + 1, 1);
    for (int i = 1; i <= n * m; i++) if (i == find(i)) {
        if (!d[i]) Q.push(i);
    }
    while (!Q.empty()) {
        int v = Q.front(); Q.pop();
        for (int u : G[v]) {
            f[u] = max(f[u], f[v] + 1);
            if (!--d[u]) Q.push(u);
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            printf("%d%c", f[find(id(i, j))], " \n"[j == m]);
        }
    }
    return 0;
}