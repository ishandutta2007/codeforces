#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010;
int n, m, h[maxn], sg[maxn], xors[maxn];
bool vis[maxn];
vector<int> G[maxn];

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &h[i]);
    }
    while (m--) {
        int u, v;
        scanf("%d %d", &u, &v);
        G[u].push_back(v);
    }
    function<void(int)> calc = [&](int u) {
        if (vis[u]) return;
        set<int> S;
        for (int v : G[u]) calc(v), S.insert(sg[v]);
        vis[u] = 1;
        while (S.count(sg[u])) sg[u]++;
    };
    for (int i = 1; i <= n; i++) {
        calc(i), xors[sg[i]] ^= h[i];
    }
    if (count(xors, xors + n, 0) == n) puts("LOSE"), exit(0);
    for (int i = n - 1; ~i; i--) if (xors[i]) {
        for (int j = 1; j <= n; j++) if (sg[j] == i && h[j] > (h[j] ^ xors[i])) {
            h[j] ^= xors[i];
            memset(vis, 0, sizeof(vis));
            for (int k : G[j]) if (!vis[sg[k]]) {
                h[k] ^= xors[sg[k]], vis[sg[k]] = 1;
            }
            break;
        }
        break;
    }
    puts("WIN");
    for (int i = 1; i <= n; i++) {
        printf("%d ", h[i]);
    }
    return 0;
}