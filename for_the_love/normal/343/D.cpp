#include <map>
#include <cmath>
#include <queue>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 500111, M = 2*N, LV = 25;
int L[N], R[N], Size[N], Up[N], depth[N], fa[LV][N], n, m, nn, rt; vector<int> adj[N];
int T[4*N], BJ_D[4*N], a, b, c;

inline int Jump_Up(int x, int t){
    for (int lv=0;lv<LV;++lv){
        if (t&1) x = fa[lv][x];
        t >>= 1;
    }
    return x;
}

inline int lca(int a, int b){
    if (depth[a] > depth[b]) a = Jump_Up(a, depth[a] - depth[b]);
    else b = Jump_Up(b, depth[b] - depth[a]);

    if (a == b) return a;
    else {
        for (int lv=LV-1;lv>=0;--lv) if (fa[lv][a] != fa[lv][b])
            a = fa[lv][a], b = fa[lv][b];
        return fa[0][a];
    }
}


inline void dfs(int u = 1){

    Size[u] = 1; for (int i=0;i<adj[u].size();++i){
        int v = adj[u][i]; if (v == fa[0][u]) continue;
        depth[v] = depth[u] + 1, fa[0][v] = u;
        for (int lv=1;lv<LV;++lv) if (!(fa[lv][v] = fa[lv-1][fa[lv-1][v]])) break;
        dfs(v), Size[u] += Size[v];
    }
}

inline void hld(int u = 1, int t = 1){
    L[u] = ++nn, Up[u] = t;
    int h = 0; for (int i=0;i<adj[u].size();++i){
        int v = adj[u][i];
        if (v != fa[0][u] && Size[v] > Size[h])
        h = v;
    }

    if (h){
        hld(h, t);for (int i=0;i<adj[u].size();++i){
            int v = adj[u][i]; if (v != fa[0][u] && v != h)
            hld(v, v);
        }
    }
    R[u] = nn;
}

namespace Segment_Tree{

#define root 1, 1, n
#define lx (x<<1)
#define rx (lx|1)
#define ml (l + r >> 1)
#define mr (ml + 1)
#define xx x, l, r
#define lc lx, l, ml
#define rc rx, mr, r

inline void Upd(int x, int l, int r){
    T[x] = min(T[lx], T[rx]);
}

inline void push_down(int x){
    if (BJ_D[x]){
        T[lx] = T[rx] = T[x];
        BJ_D[lx] = BJ_D[rx] = 1;
        BJ_D[x] = 0;
    }
}

inline void bd(int x, int l, int r){
    if (l == r) T[x] = 0;
    else bd(lc), bd(rc), Upd(xx);
}

inline int q(int x, int l, int r){
    if (r < a || b < l) return 2;
    if (a <= l && r <= b) return T[x];
    push_down(x); return min(q(lc), q(rc));
}

inline void mod(int x, int l, int r){
    if (r < a || b < l) return;
    if (a <= l && r <= b) T[x] = c, BJ_D[x] = 1;
    else {
        push_down(x), mod(lc), mod(rc), Upd(xx);
    }
}

inline void mody(int z, int x){
    while (Up[z] != Up[x]){
        a = L[Up[x]], b = L[x], mod(root);
        x = fa[0][Up[x]];
    }
    a = L[z], b = L[x], mod(root);
}

inline int qy(int l, int r){
    a = l, b = r; return q(root);
}

} using namespace Segment_Tree;

int main(){

    scanf("%d", &n);

    for (int i=0;i<n-1;++i){
        int a, b; scanf("%d %d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(), hld(); bd(root);

    int Q; cin >> Q; while (Q--){
        int x, y, z, t; scanf("%d%d", &t, &x);

        //cout << L[x] << " " << R[x] << endl;
        //cout << t << " " << x << endl;

        switch(t){
            case 1:
                a = L[x], b = R[x], c = 1;
                mod(root);
                break;
            case 2:
                c = 0, z = 1;
                mody(z, x);
                break;
            case 3:
                a = L[x], b = L[x];
                printf("%d\n", q(root));
        }
    }
}