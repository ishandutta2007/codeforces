#include <cstdio>

#include <algorithm>
#include <functional>
#include <queue>

using namespace std;

typedef long long ll;

struct Edge {
    int v;
    Edge* next;
};

const int N = 200010;
const int P = 1e9 + 7;

int n, ans;
int a[N], dep[N], prt[N];
int sum[N][2], cur[2];
bool vis[N];
Edge* g[N];

void addEdge(int u, int v) {
    static Edge pool[N * 2];
    static Edge* p = pool;
    p->v = v;
    p->next = g[u];
    g[u] = p;
    ++p;
}

void dfs(int u) {
    vis[u] = true;
    sum[u][dep[u]] = 1;
    for (Edge* p = g[u]; p; p = p->next)
        if (!vis[p->v]) {
            dep[p->v] = dep[u] ^ 1;
            prt[p->v] = u;
            dfs(p->v);
            sum[u][0] += sum[p->v][0];
            sum[u][1] += sum[p->v][1];
        }
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
        if (a[i] < 0)
            a[i] += P;
    }
    for (int rep = 1; rep < n; ++rep) {
        int u, v;
        scanf("%d%d", &u, &v);
        addEdge(u, v);
        addEdge(v, u);
    }
    dfs(1);
    for (int u = 1; u <= n; ++u) {
        ans = (ans + n * (ll) a[u]) % P;
        for (Edge *p = g[u]; p; p = p->next) {
            if (prt[p->v] != u) {
                cur[0] = sum[1][0] - sum[u][0];
                cur[1] = sum[1][1] - sum[u][1];
            } else {
                cur[0] = sum[p->v][0];
                cur[1] = sum[p->v][1];
            }
            ans = (ans + cur[dep[u]] * (ll) (n - cur[0] - cur[1]) % P * a[u]) % P;
            ans = (ans + (P - cur[!dep[u]]) * (ll) (n - cur[0] - cur[1]) % P * a[u] % P) % P;
        }
    }
    printf("%d\n", ans);
    return 0;
}