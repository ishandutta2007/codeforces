#include <iostream>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <cstdio>

#define pb push_back
#define mp make_pair
#define x first
#define y second

using namespace std;

const int base = 1000000007;

void dfs(vector<int>& order, const vector<vector<int> >& a, int v){
    order.pb(v);
    for (int i = 0; i < a[v].size(); i++){
        dfs(order, a, a[v][i]);
    }
    order.pb(v);
}

void add(vector<pair<int, int> >& tree, int v, int l, int r, int l1, int r1, pair<int, int> p){
    if (l == l1 && r == r1){
        tree[v].x = (tree[v].x + p.x) % base;
        tree[v].y = (tree[v].y + p.y) % base;
        return;
    }
    if (l >= r1 || l1 >= r){
        return;
    }
    int m = (l + r) / 2;
    if (r1 <= m){
        add(tree, v * 2 + 1, l, m, l1, r1, p);
    } else
    if (l1 >= m){
        add(tree, v * 2 + 2, m, r, l1, r1, p);
    } else {
        add(tree, v * 2 + 1, l, m, l1, m, p);
        add(tree, v * 2 + 2, m, r, m, r1, p);
    }
}

pair<int, int> get(const vector<pair<int, int> >& tree, int v){
    pair<int, int> ans;
    while (v > 0){
        ans.x = (ans.x + tree[v].x) % base;
        ans.y = (ans.y + tree[v].y) % base;
        v = (v - 1) / 2;
    }
    ans.x = (ans.x + tree[v].x) % base;
    ans.y = (ans.y + tree[v].y) % base;
    return ans;
}

int main(){

    int n;
    scanf("%d", &n);
    vector<vector<int> > a(n);
    for (int i = 0; i < n - 1; i++){
        int x;
        scanf("%d", &x);
        a[x - 1].pb(i + 1);
    }
    vector<int> order;
    dfs(order, a, 0);
    vector<int> fl(n);
    fl[0] = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < a[i].size(); j++){
            fl[a[i][j]] = fl[i] + 1;
        }
    }
    vector<int> tin(n, -1), tout(n, -1);
    for (int i = 0; i < order.size(); i++){
        if (tin[order[i]] == -1) tin[order[i]] = i; else
        tout[order[i]] = i;
    }
    
    int N = 1;
    while (N < n) N *= 2;
    N *= 2;
    vector<pair<int, int> > tree(N + N);
        
    int q;
    cin >> q;
    for (int i = 0; i < q; i++){
        int tp;
        scanf("%d", &tp);
        if (tp == 1){
            int v, x, k;
            scanf("%d%d%d", &v, &x, &k);
            v -= 1;
            x = (1ll * x + 1ll * k * fl[v]) % base;
            add(tree, 0, 0, N, tin[v], tout[v] + 1, mp(x, k));
        } else {
            int v;
            scanf("%d", &v);
            pair<int, int> p = get(tree, tin[v - 1] + N - 1);
            printf("%d\n", (int)((1ll * p.x - 1ll * p.y * fl[v - 1] + 1ll * base * base) % base));
        }
    }

    return 0;
}