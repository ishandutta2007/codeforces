#include <iostream>
#include <sstream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <string.h>
#include <set>
#include <map>
#include <cmath>
#include <cassert>
#include <queue>


using namespace std;
const int MaxN = 200 * 1000 + 7;
vector<int> g[MaxN];
bool used[MaxN];
int tin[MaxN], tout[MaxN];
int timer = 1;
int p[MaxN][20];
int h[MaxN];


void dfs(int v, int par, int curh) {
    used[v] = true;
    p[v][0] = par;
    h[v] = curh;
    tin[v] = timer;
    timer++;
    for(int i = 1; i < 20; i++) {
        p[v][i] = p[p[v][i - 1]][i - 1];
    }
    for (int i = 0; i < (int)g[v].size(); i++) {
        int to=g[v][i];
        if(!used[to]) {
            dfs(to, v, curh + 1);
        }
    }
    tout[v] = timer;
    timer++;
}

bool predok(int u, int v) {
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int findLCA(int u, int v) {
    if (predok(u,v)) {
        return u;
    }
    if (predok(v,u)) {
        return v;
    }
    for (int i = 19; i >= 0; i--) {
        if(!predok(p[u][i], v)) {
            u = p[u][i];
        }
    }
    return p[u][0];
} 

int dist(int u,int v) {
    return h[u] + h[v] - 2 * h[findLCA(u, v)];
}


int n;
int inp[MaxN];


int main() {
    scanf("%d", &n);
    for (int i = 2; i <= n; i++) {
        scanf("%d", &inp[i]);
        g[i].push_back(inp[i]);
        g[inp[i]].push_back(i);
    }
    dfs(1, 1, 1);
    int u = 1, v = 1, res = 0;
    for (int i = 2; i <= n; i++) {
        if (dist(i, u) > res) {
            res = dist(i,u);
            v = i;
        }
        if (dist(i,v) > res) {
            res = dist(i,v);
            u = i;
        }
        printf("%d\n", res);
    }
    return 0;
}