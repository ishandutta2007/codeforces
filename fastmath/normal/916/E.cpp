#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#include <string>
#include <random>
#include <time.h>

using namespace std;
#define int long long

const int MOD = 1e16 + 7;
const int MAXN = 2e5 + 7;

int n, q;

int a[MAXN];
vector <int> g[MAXN];

int dp[MAXN][20];
int tree1[MAXN * 4], tree2[MAXN * 4], add2[MAXN * 4];

int tin[MAXN];
int h[MAXN];
int l[MAXN], r[MAXN];

vector <int> eiler1, eiler2;
void dfs(int u, int parent, int d){
    dp[u][0] = parent;
    for (int i = 1; i < 20; ++i){
        dp[u][i] = dp[dp[u][i - 1]][i - 1];
    }

    h[u] = d;
    tin[u] = eiler1.size();
    eiler1.push_back(u);
    l[u] = eiler2.size();
    eiler2.push_back(u);
    for (int v: g[u]){
        if (v == parent) continue;
        dfs(v, u, d + 1);
        eiler1.push_back(u);
    }
    r[u] = eiler2.size() - 1;
}

int mymin(int u, int v){
    if (u == -1) return v;
    if (v == -1) return u;

    if (h[u] < h[v]) return u;
    else return v;
}

bool is_anc(int u, int v){
    return l[u] <= l[v] && r[v] <= r[u];    
}

int lca1(int u, int v){
    for (int i = 19; i >= 0; --i){
        if (!is_anc(dp[u][i], v)) u = dp[u][i];
    }
    return u;
}
 
void build1(int v, int tl, int tr){
    if (tl == tr){
        tree1[v] = eiler1[tl];
        return;
    }

    int m = (tl + tr) / 2;
    build1(v * 2 + 1, tl, m);
    build1(v * 2 + 2, m + 1, tr);
    tree1[v] = mymin(tree1[v * 2 + 1], tree1[v * 2 + 2]);
}

int getmin(int v, int tl, int tr, int l, int r){
    if (tr < l || r < tl) return -1;
    if (l <= tl && tr <= r) return tree1[v];
    int m = (tl + tr) / 2;
    return mymin(getmin(v * 2 + 1, tl, m, l, r), getmin(v * 2 + 2, m + 1, tr, l, r));
}

int lca(int u, int v){
    return getmin(0, 0, eiler1.size() - 1, min(tin[u], tin[v]), max(tin[u], tin[v]));
}

int root = 0;
int I_love_Elena_Vladimirovna(int u, int v){
    return lca(u, v) ^ lca(u, root) ^ lca(v, root);
}

void push(int v, int tl, int tr, int m){
    add2[v * 2 + 1] += add2[v];
    tree2[v * 2 + 1] += add2[v] * (m - tl + 1);

    add2[v * 2 + 2] += add2[v];
    tree2[v * 2 + 2] += add2[v] * (tr - m);

    add2[v] = 0;
}

void build2(int v, int tl, int tr){
    if (tl == tr){
        tree2[v] = a[eiler2[tl]];
        return;
    }

    int m = (tl + tr) / 2;
    build2(v * 2 + 1, tl, m);
    build2(v * 2 + 2, m + 1, tr);
    tree2[v] = tree2[v * 2 + 1] + tree2[v * 2 + 2];
}

void upd2(int v, int tl, int tr, int l, int r, int x){
    if (tr < l || r < tl) return;
    if (l <= tl && tr <= r){
        add2[v] += x;
        tree2[v] += x * (tr - tl + 1);
        return;
    }

    int m = (tl + tr) / 2;
    push(v, tl, tr, m);
    upd2(v * 2 + 1, tl, m, l, r, x);
    upd2(v * 2 + 2, m + 1, tr, l, r, x);
    tree2[v] = tree2[v * 2 + 1] + tree2[v * 2 + 2];
}

int getsum(int v, int tl, int tr, int l, int r){
    if (tr < l || r < tl) return 0;
    if (l <= tl && tr <= r) return tree2[v];
    int m = (tl + tr) / 2;
    push(v, tl, tr, m);
    return getsum(v * 2 + 1, tl, m, l, r) + getsum(v * 2 + 2, m + 1, tr, l, r);
}

void upd_query(int u, int x){
    if (u == root) {
         upd2(0, 0, n - 1, 0, n - 1, x);
    }
    else if (lca(u, root) != u) {
         upd2(0, 0, n - 1, l[u], r[u], x);
    }
    else {
        int bad = lca1(root, u);
        upd2(0, 0, n - 1, 0, n - 1, x);
        upd2(0, 0, n - 1, l[bad], r[bad], -x);
    }
}

int get_query(int u){
    if (u == root){
        return getsum(0, 0, n - 1, 0, n - 1);
    }
    else if (lca(u, root) != u){
        return getsum(0, 0, n - 1, l[u], r[u]);
    }
    else{
        int bad = lca1(root, u);
        return getsum(0, 0, n - 1, 0, n - 1) - getsum(0, 0, n - 1, l[bad], r[bad]);
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    cin >> n >> q;

    for (int i = 0; i < n; ++i){
        cin >> a[i];
    }

    for (int i = 0; i < n - 1; ++i){
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(0, 0, 0);
    build1(0, 0, eiler1.size() - 1);
    build2(0, 0, n - 1);

    
    for (int i = 0; i < q; ++i){
        int t;
        cin >> t;

        if (t == 1){
            cin >> root;
            --root;
        }
        else if (t == 2){
            int u, v, x;
            cin >> u >> v >> x;
            upd_query(I_love_Elena_Vladimirovna(u - 1, v - 1), x);
        }
        else{
            int u;
            cin >> u;
            cout << get_query(u - 1) << '\n';
        }
    }
    

    return 0;
}