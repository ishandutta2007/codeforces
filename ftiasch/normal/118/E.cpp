// Codeforces Beta Round #89
// Problem E -- Bertown roads
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 111111;
const int M = 666666;

int n, m, a[M], b[M], visit[M],
    edgeCnt, firstEdge[N], to[M], nextEdge[M],
    dfsCnt, dfn[N], low[N];
bool found;

void addEdge (int u, int v) {
    to[edgeCnt] = v;
    nextEdge[edgeCnt] = firstEdge[u];
    firstEdge[u] = edgeCnt ++;
}

void dfs (int u) {
    dfn[u] = low[u] = dfsCnt ++;
    for (int iter = firstEdge[u]; iter != -1; iter = nextEdge[iter]) {
        if (visit[iter >> 1] == -1) {
            visit[iter >> 1] = iter & 1;
            int v = to[iter];
            if (dfn[v] == -1) {
                dfs(v);
                low[u] = min(low[u], low[v]);
                found |= dfn[v] <= low[v];
            } else {
                low[u] = min(low[u], dfn[v]);
            }
        }
    }
}

int main () {
    scanf("%d%d", &n, &m);
    edgeCnt = 0;
    memset(firstEdge, -1, sizeof(firstEdge));
    for (int i = 0; i < m; ++ i) {
        scanf("%d%d", a + i, b + i);
        addEdge(a[i] - 1, b[i] - 1);
        addEdge(b[i] - 1, a[i] - 1);
    }
    memset(visit, -1, sizeof(visit));
    found = false;
    dfsCnt = 0;
    memset(dfn, -1, sizeof(dfn));
    dfs(0);
    if (found) {
        printf("0\n");
    } else {
        for (int i = 0; i < m; ++ i) {
            if (visit[i] == 0) {
                printf("%d %d\n", a[i], b[i]);
            } else {
                printf("%d %d\n", b[i], a[i]);
            }
        }
    }
    return 0;
}