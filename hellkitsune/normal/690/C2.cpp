#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> g[100 * 1005];
int dist[100 * 1005];

void dfs(int v, int d) {
    dist[v] = d;
    for (int to : g[v]) if (dist[to] == -1) {
        dfs(to, d + 1);
    }
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i) {
        int from, to;
        scanf("%d%d", &from, &to), --from, --to;
        g[from].push_back(to);
        g[to].push_back(from);
    }
    memset(dist, -1, sizeof dist);
    dfs(0, 0);
    int best = 0;
    for (int i = 1; i < n; ++i) if (dist[i] > dist[best]) {
        best = i;
    }
    memset(dist, -1, sizeof dist);
    dfs(best, 0);
    best = 0;
    for (int i = 1; i < n; ++i) if (dist[i] > dist[best]) {
        best = i;
    }
    cout << dist[best] << endl;
    return 0;
}