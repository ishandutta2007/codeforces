#include <iostream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <string.h>
#include <sstream>
#include <queue>
#include <map>
#include <set>
#include <cstring>
#include <cmath>
#include <unordered_map>
#include <cassert>


using namespace std;
    

const int maxN = 400001;
int sz[maxN];
vector<int> g[maxN];
bool ans[maxN];
int cs[maxN];
int n;


void dfs(int v, int p) {
    sz[v] = 1;
    for (int i = 0; i < g[v].size(); i++) {
        if (g[v][i] != p) {
            dfs(g[v][i], v);
            sz[v] += sz[g[v][i]];
        }
    }
}


int nd;


void dfs2(int v, int p) {
    int ss = sz[v];
    if (sz[v] > sz[p]) {
        ss = n - sz[p];
    }
    ans[v] = (ss >= nd);
    for (int i = 0; i < g[v].size(); i++) {
        if (g[v][i] != p) {
            dfs2(g[v][i], v);
        }
    }
}



int main() {
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        g[a].push_back(b);
        g[b].push_back(a);
    }
    sz[0] = n + 1;
    dfs(1, 1);
    int root = 0;
    for (int i = 1; i <= n; i++) {
        if (2 * sz[i] < n) {
            continue;
        }
        if (sz[i] < sz[root])  {
            root = i;
        } 
    }
    ans[root] = true;
    int m1 = 0, m2 = 0;
    for (int i = 0; i < g[root].size(); i++) {
        int v = g[root][i];
        if (sz[v] < sz[root]) {
            cs[v] = sz[v];
        } else {
            cs[v]= n - sz[root];
        }
        if (m2 < cs[v]) {
            m2 = cs[v];
        }
        if (m1 < m2) {
            swap(m1, m2);
        }
    }
    ans[root] = true;
    for (int i = 0; i < g[root].size(); i++) {
        int v = g[root][i];
        if (n - cs[v] > n / 2) {
            nd = n - n / 2;
            if (cs[v] == m1) {
                nd -= m2;
            } else {
                nd -= m1;
            }
        } else {
            nd = 0;
        }
        dfs2(v, root);
    }
    for (int i = 1; i <= n; i++) {
        if (ans[i]) {
            printf("1 ");
        } else {
            printf("0 ");
        }
    }
    printf("\n");
    return 0;
}