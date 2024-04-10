#include <bits/stdc++.h>

using namespace std;
#define int long long

const int MAXN = 2e5 + 7;

bool xored[MAXN * 10];
int tree[MAXN * 10];
int color[MAXN];
vector <int> e;
vector <int> g[MAXN];

int l[MAXN], r[MAXN];

bool used1[MAXN];
void build(int u){
    used1[u] = true;
    l[u] = e.size();
    e.push_back(u);
    for (int v: g[u]){
        if (!used1[v]){
            build(v);
        }
    }
    r[u] = e.size() - 1;
}

void tbuild(int v, int tl, int tr){
    if (tl == tr){
        tree[v] = color[e[tl]];
        return;
    }

    int m = (tl + tr) / 2;
    tbuild(v * 2 + 1, tl, m);
    tbuild(v * 2 + 2, m + 1, tr);
    tree[v] = tree[v * 2 + 1] + tree[v * 2 + 2];
}

void push(int v, int tl, int tr, int m){
    if (xored[v]){
        xored[v * 2 + 1] ^= 1;
        int len1 = m - tl + 1;
        tree[v * 2 + 1] = len1 - tree[v * 2 + 1];

        xored[v * 2 + 2] ^= 1;
        int len2 = tr - m;
        tree[v * 2 + 2] = len2 - tree[v * 2 + 2];

        xored[v] = false;
    }
}

void upd(int v, int tl, int tr, int l, int r){
    if (tl > r || l > tr) return;
    if (tl >= l && tr <= r){
        int len = tr - tl + 1;
        tree[v] = len - tree[v];
        xored[v] ^= 1;
        return;
    }

    int m = (tl + tr) / 2;
    push(v, tl, tr, m);
    upd(v * 2 + 1, tl, m, l, r);
    upd(v * 2 + 2, m + 1, tr, l, r);
    tree[v] = tree[v * 2 + 1] + tree[v * 2 + 2];
}

int get(int v, int tl, int tr, int l, int r){
    if (tl > r || l > tr) return 0;
    if (tl >= l && tr <= r) return tree[v];
    int m = (tl + tr) / 2;
    push(v, tl, tr, m);
    return get(v * 2 + 1, tl, m, l, r) + get(v * 2 + 2, m + 1, tr, l, r);
}

signed main(){
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);

    int n;
    cin >> n;
    for (int i = 1; i < n; ++i){
        int v;
        cin >> v;
        g[v - 1].push_back(i);
        g[i].push_back(v - 1);
    }

    for (int i = 0; i < n; ++i){
        cin >> color[i];
    }

    build(0);
    tbuild(0, 0, e.size() - 1);

    int q;
    cin >> q;
    for (int i = 0; i < q; ++i){
        string type;
        int u;
        cin >> type >> u;
        if (type == "pow"){
            upd(0, 0, e.size() - 1, l[u - 1], r[u - 1]);
        }
        else{
            cout << get(0, 0, e.size() - 1, l[u - 1], r[u - 1]) << '\n';
        }
    }

    return 0;
}