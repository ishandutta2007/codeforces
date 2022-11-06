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
#define MAXN 300010

typedef long long lint;

using namespace std;

const lint mod = 1000000007;

vector <int> child[MAXN];
int ord[MAXN], lastord[MAXN], nextord;
int depth[MAXN];

void dfs(int v, int d)
{
        ord[v] = nextord++;
        depth[v] = d;

        for (int i = 0; i < (int)child[v].size(); i++) {
                int v2 = child[v][i];
                dfs(v2, d+1);
        }

        lastord[v] = nextord-1;
}

struct node {
        int v0, v1;
        node operator + (const node& o) const {
                return (node){((v0+o.v0)%mod+mod)%mod, ((v1+o.v1)%mod+mod)%mod};
        }
} tree[4*MAXN];

void add(int &v, int x) {
        v += x;
        v = (v%mod + mod)%mod;
}

void update(int a, int b, int d0, int d1, int n, int l, int r)
{
        if (a > r || b < l) return;
        if (a <= l && r <= b) {
                add(tree[n].v0, d0);
                add(tree[n].v1, d1);
        } else {
                int m = (l+r)/2;
                update(a, b, d0, d1, 2*n+1, l, m);
                update(a, b, d0, d1, 2*n+2, m+1, r);
        }
}

struct node query(int pos, int n, int l, int r)
{
        if (l == r) return tree[n];
        else {
                int m = (l+r)/2;
                if (pos <= m) return tree[n] + query(pos, 2*n+1, l, m);
                else return tree[n] + query(pos, 2*n+2, m+1, r);
        }
}

int main(int argc, char ** argv)
{
        int n;

        scanf("%d", &n);

        for (int i = 1; i < n; i++) {
                int p;
                scanf("%d", &p); p--;
                child[p].push_back(i);
        }

        nextord = 0;
        dfs(0, 0);

        memset(tree, 0, sizeof(tree));

        int nq;

        scanf("%d", &nq);

        for (int q = 0; q < nq; q++) {
                int op;
                scanf("%d", &op);
                if (op == 1) {
                        int v, x, k;
                        scanf("%d %d %d", &v, &x, &k); v--;
                        int o = ord[v], lo = lastord[v];

                        int d1 = k;
                        lint lose = (lint)k * (lint)depth[v] % (lint)mod;
                        lint d0 = ((x + lose)%mod + mod)%mod;

                        update(o, lo, d0, d1, 0, 0, n-1);
                } else {
                        int v;
                        scanf("%d", &v); v--;
                        int o = ord[v], lo = lastord[v];

                        node no = query(o, 0, 0, n-1);

                        lint ret = (((lint)no.v0 - (lint)no.v1 * (lint)depth[v] % mod) + mod)%mod;
                        printf("%d\n", (int)ret);
                }
        }

        return 0;
}