#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <map>
#include <unordered_map>
#include <cmath>
#include <iostream>
using namespace std;
const int N = 1010;
vector<int>g[N], d, e[N];
int n;
int deep[N], fa[N], mxsz[N], sz[N];
bool bz[N];
int ask(int x, int y) {
    printf("? %d %d\n", x, y);
    fflush(stdout);
    scanf("%d", &x);
    return x;
}
void dfs(int x) {
    sz[x] = 1;
    mxsz[x] = 0;
    deep[x] ++;
    for (auto u:e[x])
        if (bz[u] && fa[x] != u) {
            fa[u] = x;
            deep[u] = deep[x];
            dfs(u);
            sz[x] += sz[u];
            mxsz[x] = max(mxsz[x], sz[u]);
        }
}
void dfs1(int x) {
    d.push_back(x);
    for (auto u:e[x])
        if (u!=fa[x])
            dfs1(u);
}
int dfs2(int x) {
    int v = x;
    for (auto u:e[x])
        if (u!=fa[x]) {
            int y = dfs2(u);
            if (deep[y] > deep[v])
                v = y;
        }
    return v;
}
int main() {
    scanf("%d", &n);
    for (int i = 1; i < n ; i ++) {
        int x, y;
        scanf("%d %d", &x, &y);
        g[x].push_back(y);
        g[y].push_back(x);
        d.push_back(i);
    }
    d.push_back(n);
    if (n == 1) {
        printf("! 1\n");
        fflush(stdout);
        return 0;
    }
    while (d.size() > 1) {
        if (d.size() == 2) {
            printf("! %d\n", ask(d[0], d[1]));
            fflush(stdout);
            return 0;
        }
        memset(bz, 0, sizeof(bz));
        for (auto u:d) {
            bz[u] = 1;
            e[u].clear();
        }
        for (auto u:d)
            for (auto v:g[u])
                if (bz[v])
                    e[u].push_back(v);
        fa[d[0]] = 0;
        dfs(d[0]);
        int st = d[0];
        for (auto u:d)
            if (max(mxsz[u], (int)d.size() - sz[u]) < max(mxsz[st], (int)d.size() - sz[st])) st = u;
        fa[st] = 0;
        deep[st] = 0;
        dfs(st);
        vector<int>tmp;
        for (auto u:e[st])
            tmp.push_back(dfs2(u));
        int sig = 0;
        for (int i = 0; i + 1 < tmp.size(); i += 2)
        {
            int p = ask(tmp[i], tmp[i + 1]);
            if (p == st) continue;
            if (p == tmp[i] || p ==tmp[i + 1]){
                printf("! %d\n", p);
                return 0;
            }
            int x = tmp[i], y =tmp[i + 1];
            while (deep[x] > deep[p]) {
                x = fa[x];
            }
            int lasty = y;
            while (deep[y] > deep[p]) {
                y = fa[y];
            }
            if (x == p) sig = e[st][i];
            else
                sig = e[st][i+1];
            break;
        }
        if (!sig && !(e[st].size() & 1)){
            printf("! %d\n",st);
            return 0;
        }
        if (!sig) sig = e[st][e[st].size() - 1];
        d.clear();
        d.push_back(st);
        dfs1(sig);
    }
    printf("! %d\n", d[0]);
    return 0;
}