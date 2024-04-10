#include <iostream>
#include <cstdio>
#include <algorithm>
#include <numeric>
#include <climits>
#include <sstream>
#include <cstring>
#include <cassert>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>
#include <map>
#include <set>

#define INF (INT_MAX/2)
#define MAXN 200000

typedef long long lint;

using namespace std;

struct tree {
        int nodes[4*MAXN];

        int build_tree(int n, int l, int r) {
                if (l == r) return nodes[n] = 0;
                return nodes[n] = build_tree(2*n+1, l, (l+r)/2) + build_tree(2*n+2, (l+r)/2+1, r);
        }

        int query(int pos, int n, int l, int r) {
                if (l == r) return nodes[n];
                else {
                        int m = (l+r)/2;
                        if (pos <= m) return nodes[n] + query(pos, 2*n+1, l, m);
                        else return nodes[n] + query(pos, 2*n+2, m+1, r);
                }
        }

        void update(int a, int b, int delta, int n, int l, int r) {
                if (a > r || b < l) {}
                else if (a <= l && r <= b) nodes[n] += delta;
                else {
                        int m = (l+r)/2;
                        update(a, b, delta, 2*n+1, l, m);
                        update(a, b, delta, 2*n+2, m+1, r);
                }
        }
} trees[2];

vector <int> adj[MAXN];
int n, depth[MAXN], preord[MAXN], lastord[MAXN], initval[MAXN];

int dfs(int v, int parent, int nextord, int d) {
        depth[v] = d;
        preord[v] = nextord++;

        trees[d%2].update(preord[v], preord[v], initval[v], 0, 0, n-1);

        for (int i = 0; i < (int)adj[v].size(); i++) {
                int v2 = adj[v][i];
                if (v2 == parent) continue;
                nextord = dfs(v2, v, nextord, d+1);
        }

        lastord[v] = nextord-1;

        return nextord;
}

int main(int argc, char ** argv) {
        int m;

        scanf("%d %d", &n, &m);

        for (int i = 0; i < n; i++) scanf("%d", &initval[i]);

        for (int i = 0; i < n-1; i++) {
                int a, b;
                scanf("%d %d", &a, &b), a--, b--;
                adj[a].push_back(b);
                adj[b].push_back(a);
        }

        for (int par = 0; par < 2; par++) trees[par].build_tree(0, 0, n-1);
        dfs(0, -1, 0, 0);

        for (int q = 0; q < m; q++) {
                int op;
                scanf("%d", &op);

                if (op == 1) {
                        int v, val;
                        scanf("%d %d", &v, &val); v--;
                        trees[depth[v]%2].update(preord[v], lastord[v], val, 0, 0, n-1);
                        trees[1-depth[v]%2].update(preord[v], lastord[v], -val, 0, 0, n-1);
                } else {
                        int v;
                        scanf("%d", &v); v--;
                        printf("%d\n", trees[depth[v]%2].query(preord[v], 0, 0, n-1));
                }
        }

        return 0;
}