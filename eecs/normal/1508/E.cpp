#include <bits/stdc++.h>
using namespace std;

const int maxn = 300010;
int n, tim, tim2, a[maxn], b[maxn], fa[maxn];
int tid[maxn], ed[maxn], ban[maxn], tid2[maxn];
long long step;
vector<int> G[maxn];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]), b[a[i]] = i;
    }
    for (int i = 1, u, v; i < n; i++) {
        scanf("%d %d", &u, &v);
        G[u].push_back(v), fa[v] = u;
    }
    int id = max(1, a[1] - 1), o = b[id];
    function<void(int, int)> dfs1 = [&](int v, int dep) {
        tid[v] = ++tim;
        if (a[v] < id) step += dep;
        sort(G[v].begin(), G[v].end(), [&](int x, int y) { return a[x] < a[y]; });
        for (int u : G[v]) dfs1(u, dep + 1);
        ed[++tim2] = v;
    };
    function<void(int)> dfs2 = [&](int v) {
        tid2[++tim] = v;
        for (int u : G[v]) if (!ban[u]) dfs2(u);
    };
    dfs1(1, 0);
    for (int i = b[id]; i > 1; i = fa[i]) {
        swap(b[a[i]], b[a[fa[i]]]);
        step++, swap(a[i], a[fa[i]]);
    }
    for (int i = 1; i < id; i++) {
        ban[ed[i]] = 1;
        if (b[i] ^ ed[i]) puts("NO"), exit(0);
    }
    tim = 0, dfs2(1);
    for (int i = id; i <= n; i++) {
        if (b[i] ^ tid2[i - id + 1]) puts("NO"), exit(0);
    }
    bool flag = 0;
    for (int i = ed[id]; i; i = fa[i]) {
        if (i == o) { flag = 1; break; }
    }
    if (!flag) puts("NO"), exit(0);
    printf("YES\n%lld\n", step);
    for (int i = 1; i <= n; i++) {
        printf("%d ", tid[i]);
    }
    return 0;
}