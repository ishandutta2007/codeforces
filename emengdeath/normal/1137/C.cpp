#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
using namespace std;
int n, m, D;
int f[100001][51];
vector<int>g[100001], e[100001];
int fa[100001], du[100001], d[100001];
char s[100001][52];
int stack[100001], dfn[100001], low[1000001];
bool bz[100001][52];
bool instack[100001];
void tarjan(int x) {
    static int tot = 0;
    dfn[x] = low[x] = ++tot, instack[stack[++stack[0]] = x] = 1;
    for (auto u:e[x])
        if (!dfn[u]) {
            tarjan(u);
            low[x] = min(low[x], low[u]);
        } else
            if (instack[u])
                low[x] = min(low[x], dfn[u]);
    if (low[x] == dfn[x]) {
        do {
            instack[stack[stack[0]]] = 0;
            g[x].push_back(stack[stack[0]]);
            fa[stack[stack[0] --]] = x;
        }while (stack[stack[0] + 1] != x);
    }

}
inline int value(int x ,int y){
    return s[x][y] - '0';
}
void update(int x, int y, int step) {
    for (int i = 0; i < D; i ++)
        f[y][(i + step) % D] = max(f[y][(i + step) % D], f[x][i]);// + value(y, (i + step) %  D));
}
void work(int x) {
    static int d[5000001][2];
    int F[51] = {0}, FV[51] = {0};
  //  bool bzFV[51] = {0};
    int l = 0, r = 1;
    d[1][0] = x;
    d[1][1] = 0;
    bz[x][0] = 1;
    while (l <= r) {
        ++l;
        for (auto u:e[d[l][0]])
            if (fa[u] == x) {
                if (!bz[u][(d[l][1] + 1) %D])
                {
                    bz[u][(d[l][1] + 1) % D] = 1;
                    d[++r][0] = u;
                    d[r][1] = (d[l][1] + 1) % D;
                }
            }
    }
    for (int i = 0; i < D ; i ++){
        for (auto u:g[x]) {
            for (int j = 0; j < D; j++)
                if (bz[u][j] && value(u, (j + i) % D)) {
                    F[i]++;
                    break;
                }
        }
    }
    for (auto u:g[x])
        for (int j = 0; j < D ; j++)
            if (bz[u][j])
            for (int k = 0; k < D ; k ++)
                if (f[u][k])
                FV[(k + j) %D] = max(FV[(k+ j) % D], F[(k+ j) % D] + f[u][k]);
    for (auto u:g[x])
        for (int j = 0; j < D ; j ++)
            if (bz[u][j])
                for (int k = 0; k < D ; k ++)
                    if (FV[k])
                    f[u][(j + k) % D] = max(f[u][(j + k) % D], FV[k]);
}
int main(){
    scanf("%d %d %d", &n, &m, &D);
    for (int i = 1; i <= m ; i ++) {
        int x, y;
        scanf("%d %d", &x, &y);
        e[x].push_back(y);
    }
    for (int i = 1; i <= n ; i ++)
        scanf("%s", s[i]);
    tarjan(1);
    f[1][0] = 1;
    for (int i = 1; i <= n ; i++)
        if (g[i].size())
            for (auto u:g[i])
                for (auto v:e[u])
                    if (fa[v] != i)
                        du[fa[v]] ++;
    int l = 0, r = 1;
    d[1] = 1;
    while (l < r) {
        ++ l;
        work(d[l]);
        for (auto u:g[d[l]])
            for (auto v:e[u])
                if (fa[v] != d[l])
                {
                    update(u, v, 1);
                    if (!(--du[fa[v]]))
                        d[++r] = fa[v];
                }
    }
    int ans = 0;
    for (int i = 1; i <= n; i ++)
        for (int j = 0; j < D; j ++)
            ans = max(ans, f[i][j]);
    printf("%d\n", ans - 1);
    return 0;
}