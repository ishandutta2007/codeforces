#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010;
int n, cur, a[maxn];
bool vis[maxn];
vector<int> G[maxn];
queue<int> Q;

int main() {
    scanf("%d", &n);
    for (int i = 1, u, v; i < n; i++) {
        scanf("%d %d", &u, &v);
        G[u].push_back(v), G[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    if (a[1] ^ 1) puts("NO"), exit(0);
    Q.push(a[cur = 1]), vis[a[1]] = 1;
    while (!Q.empty()) {
        int u = Q.front(); Q.pop();
        int sz = 0;
        for (int v : G[u]) if (!vis[v]) sz++;
        sort(G[u].begin(), G[u].end());
        for (int i = cur + 1; i <= cur + sz; i++) {
            if (vis[a[i]]) puts("NO"), exit(0);
            if (!binary_search(G[u].begin(), G[u].end(), a[i])) puts("NO"), exit(0);
            Q.push(a[i]), vis[a[i]] = 1;
        }
        cur += sz;
    }
    puts("YES");
    return 0;
}