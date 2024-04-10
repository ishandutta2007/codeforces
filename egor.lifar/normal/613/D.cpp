#include <iostream>
#include <sstream>
#include <cmath>
#include <algorithm>
#include <string>
#include <string.h>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <cstring>
#include <queue>
#include <bitset>
#include <queue>
#include <unordered_map>
#include <vector>
#include <stdio.h>
#include <cstdlib>
#define inf 1000000000


using namespace std;


void gn(int &x) {
    char c;
    while((c = getchar()) <'0' || c > '9');
    x = c - '0';
    while((c = getchar()) >= '0' && c <= '9') x = x * 10 + c - '0';
}
struct node {
    int v, next, w;
}e[222222]; int etot = 0; int g[111111];


void ae(int u,int v,int w = 0) {
    e[etot].v = v; e[etot].next = g[u]; e[etot].w = w; g[u] = etot++;
}


int tin[111111], tout[111111], pre[20][111111], h[111111]; int ind = 0;


void dfs(int u) {
    tin[u] = ++ind;
    for (int i = g[u]; ~i; i = e[i].next) {
        if (e[i].v != pre[0][u]) {
            pre[0][e[i].v] = u;
            h[e[i].v] = h[u] + 1;
            dfs(e[i].v);
        }
    }
    tout[u] = ++ind;
}


int lca(int a,int b) {
    if (h[a] > h[b]) {
        swap(a, b);
    }
    for (int i = 0; h[b] - h[a]; i++) {
        if ((h[b] - h[a]) & (1 << i)) {
            b = pre[i][b];
        }
    }
    if (a == b) {
        return a;
    }
    for (int i = 18; i >= 0; i--)  {
        if (pre[i][a] != pre[i][b]) {
            a = pre[i][a];
            b = pre[i][b];
        }
    }
    return pre[0][a];
}


int n,m;
int u[111111];
int List[444444];


int cmp(int x, int y) {
    return tin[x] < tin[y];
}


int stk[111111], top;


int in(int u,int v) {
    return tin[v] >= tin[u] && tout[v] <= tout[u];
}


int ifa[111111];
int mark[111111];
int f[111111][2];


void dp(int u) {
    for (int i = g[u]; ~i; i = e[i].next) {
        dp(e[i].v);
        if (f[e[i].v][0] >= inf && f[e[i].v][1] >= inf) {
            f[u][0] = f[u][1] = inf;
            return;
        }
    }
    if (!mark[u]) {
        long long su = 0;
        long long don = 0;
        long long mi = 2 * inf;
        int deg = 0;
        for (int i = g[u]; ~i; i = e[i].next) {
            deg++;
            long long x0 = min(f[e[i].v][0], e[i].w > 1 ? 1 + min(f[e[i].v][0], f[e[i].v][1]): inf);
            don += x0;
            long long x1 = f[e[i].v][1];
            su += x1;
            mi = min(mi, x1 - x0);
        }
        if (deg == 0) {
            f[u][0] = f[u][1] = 0;
        } else { 
            f[u][0] = min(1 + su, don);
            f[u][1] = min(1LL * f[u][0], don + mi);
        }
    } else {
        f[u][0] = inf;
        int su = 0;
        for (int i = g[u]; ~i; i = e[i].next) {
            int xx = f[e[i].v][0];
            if (e[i].w > 1) {
                xx = min(xx, 1 + min(f[e[i].v][0], f[e[i].v][1]));
            }
            if (xx >= inf) {
                f[u][1] = inf;
                return;
            }
            su += xx;
        }
        f[u][1] = su;
    }
}


int main() {
    memset(g, -1, sizeof(g));
    gn(n);
    for (int i = 1; i < n; i++) {
        int u, v;
        gn(u);gn(v);
        ae(u, v);
        ae(v, u);
    }
    dfs(1);
    for (int i = 1; i <= 18; i++) {
        for (int u = 1; u <= n; u++){
            pre[i][u] = pre[i - 1][pre[i - 1][u]];
        }
    }
    int que; gn(que);
    memset(g,-1, sizeof(g));
    etot = 0;
    while (que--) {
        int k;
        gn(k);
        int to = 0;
        for (int i = 1; i <= k; i++) {
            gn(u[i]), List[++to] = u[i];
        }
        if (k == 1) {
            printf("0\n");
            continue;
        }
        sort(List + 1, List + 1 + to, cmp);
        for (int i = 1; i < k; i++) {
            List[++to] = lca(List[i], List[i + 1]);
        }
        sort(List + 1, List + 1 + to, cmp);
        to = unique(List + 1, List + 1 + to) - List - 1;
        top = 0;
        List[++to] = 0;
        int rt;
        for (int i = 1; i <= to; i++) {
            g[List[i]] = -1;
        }
        for (int i = 1; i <= to; i++) {
            mark[List[i]] = 0;
            while (top && (List[i] == 0 || !in(stk[top], List[i]))){
                top--;
            }
            if (List[i] == 0) {
                continue;
            }
            ifa[List[i]] = stk[top];
            if (stk[top] == 0) {
                rt = List[i];
            } else ae(ifa[List[i]], List[i], h[List[i]] - h[ifa[List[i]]]);
            stk[++top] = List[i];
        }
        for (int i = 1; i <= k; i++) {
            mark[u[i]] = 1;
        }
        dp(rt);
        int x = min(f[rt][0], f[rt][1]);
        printf("%d\n", x >= inf ? -1: x);
    }
    return 0;
}