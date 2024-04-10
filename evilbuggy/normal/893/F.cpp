#include <bits/stdc++.h>
using namespace std;

const int maxn = 100005;
const int lgn = 20;
const int inf = 2e9;

vector<int> g[maxn];
int st[maxn], en[maxn], vert[2*maxn], d[maxn], sz[maxn], root[maxn], a[maxn];
int tree[maxn*lgn*lgn][2], val[maxn*lgn*lgn];
int n, tptr = 1, ptr = 1;

void dfs(int v, int p, int _dep = 1){
    vert[tptr] = v;
    st[v] = tptr++;
    d[v] = _dep;
    sz[v] = 1;
    for(int i = 0; i < g[v].size(); i++){
        int u = g[v][i];
        if(u == p)continue;
        dfs(u, v, _dep + 1);
        sz[v] += sz[u];
    }
    vert[tptr] = v;
    en[v] = tptr++;
}

int update(int v, int l, int r, int ind, int x){
    if(l == r){
        val[ptr] = min(val[v], x);
        tree[ptr][0] = 0;
        tree[ptr][1] = 0;
        return ptr++;
    }
    int m = (l+r)/2;
    int nv = ptr++;
    tree[nv][0] = tree[v][0];
    tree[nv][1] = tree[v][1];
    if(ind <= m)tree[nv][0] = update(tree[v][0], l, m, ind, x);
    else tree[nv][1] = update(tree[v][1], m+1, r, ind, x);
    val[nv] = min(val[tree[nv][0]], val[tree[nv][1]]);
    return nv;
}

int query(int v, int s, int e, int l, int r){
    if(l <= s && e <= r)return val[v];
    if(r < s || e < l)return inf;
    int m = (s+e)/2;
    return min(query(tree[v][0], s, m, l, r), query(tree[v][1], m+1, e, l, r));
}

void dsu(int v, int p){
    int bg = -1;
    for(int i = 0; i < g[v].size(); i++){
        int u = g[v][i];
        if(u != p){
            if(bg == -1 || sz[bg] < sz[u]){
                bg = u;
            }
            dsu(u, v);
        }
    }
    if(bg == -1){
        root[v] = update(root[0], 1, n, d[v], a[v]);
        return;
    }
    int trt = root[bg];
    trt = update(trt, 1, n, d[v], a[v]);
    for(int i = 0; i < g[v].size(); i++){
        int u = g[v][i];
        if(u == bg || u == p)continue;
        for(int j = st[u]; j < en[u]; j++){
            int w = vert[j];
            if(st[w] == j){
                trt = update(trt, 1, n, d[w], a[w]);
            }
        }
    }
    root[v] = trt;
}

int main(){

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int rt, u, v;
    cin>>n>>rt;

    for(int i = 1; i <= n; i++){
        cin>>a[i];
    }

    for(int i = 0; i < n-1; i++){
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    root[0] = 0;
    tree[0][0] = tree[0][1] = 0;
    val[0] = inf;
    dfs(rt, 0);
    dsu(rt, 0);
    int m, x, k, p, q, last = 0;
    cin>>m;
    while(m--){
        cin>>p>>q;
        x = (p + last)%n + 1;
        k = (q + last)%n;
        last = query(root[x], 1, n, d[x], d[x] + k);
        cout<<last<<endl;
    }

}