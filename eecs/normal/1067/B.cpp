#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010;
int n, K, rt, pre[maxn];
vector<int> G[maxn];

int main() {
    scanf("%d %d", &n, &K);
    for (int i = 1, u, v; i < n; i++) {
        scanf("%d %d", &u, &v);
        G[u].push_back(v), G[v].push_back(u);
    }
    auto bfs = [&](int s) {
        static int d[maxn];
        queue<int> Q;
        memset(d, -1, sizeof(d));
        Q.push(s), d[s] = 0;
        while (!Q.empty()) {
            int v = Q.front(); Q.pop();
            for (int u : G[v]) if (!~d[u]) {
                Q.push(u), d[u] = d[v] + 1, pre[u] = v;
            }
        }
        return max_element(d + 1, d + n + 1) - d;
    };
    int s = bfs(1), t = bfs(s);
    vector<int> V;
    for (int i = t; ; i = pre[i]) {
        V.push_back(i);
        if (i == s) break;
    }
    rt = V[V.size() / 2];
    function<bool(int, int, int)> chk = [&](int v, int fa, int k) {
        if (fa) G[v].erase(find(G[v].begin(), G[v].end(), fa));
        if (!k) return G[v].empty();
        if (G[v].size() < 3) return false;
        bool flag = 1;
        for (int u : G[v]) flag &= chk(u, v, k - 1);
        return flag;
    };
    puts(chk(rt, 0, K) ? "Yes" : "No");
    return 0;
}