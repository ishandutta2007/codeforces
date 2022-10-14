//optimization attempt of https://codeforces.com/contest/1479/submission/106848288

#ifdef ONLINE_JUDGE
#include <bits/stdc++.h>
#else
#include <iostream>
#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>
#include <unordered_map>
#endif
#pragma GCC optimize("Ofast,unroll-loops,fast-math,inline,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,avx,avx2,abm,mmx,popcnt")


using namespace std;

typedef long long ll;
typedef long double ldb;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/trie_policy.hpp>
using namespace __gnu_pbds;

const int LOG = 19;
const int MAXM = 3e5 + 228;
gp_hash_table<ll, int> hsh;
int cur = 2;

int arr[MAXM];
vector<int> g[MAXM];


struct node {
    node *l, *r;
    int val;

    node() {
        l = r = NULL;
        val = 0;
    }
};

node *byval[7000000];

node *merge(node *a, node *b) {
    ll pp = a->val * 1000000009LL + b->val;
    if (hsh.find(pp) == hsh.end()) {
        hsh[pp] = cur++;
        node *n = new node();
        n->l = a;
        n->r = b;
        n->val = hsh[pp];
        byval[hsh[pp]] = n;
        return n;
    }
    return byval[hsh[pp]];
}


int MAXN = 1;

node *update(node *n, int l, int r, int ind) {
    if (ind < l) {
        return n;
    }
    if (ind >= r) {
        return n;
    }
    if (l + 1 == r) {
        return byval[n->val ^ 1];
    }
    int m = (l + r) / 2;
    return merge(update(n->l, l, m, ind), update(n->r, m, r, ind));
}



int depth[MAXM];
int up[MAXM][LOG];

void dfsLCA(int v, int p = -1) {
    if (p == -1) {
        p = v;
    }
    depth[v] = depth[p] + 1;
    up[v][0] = p;
    for (int i = 1; i < LOG; i++) {
        up[v][i] = up[up[v][i - 1]][i - 1];
    }
    for (int u : g[v]) {
        if (u != p) {
            dfsLCA(u, v);
        }
    }
}

int go(int v, int d) {
    for (int i = 0; i < LOG; i++) {
        if (d & (1 << i)) {
            v = up[v][i];
        }
    }
    return v;
}

int lca(int u, int v) {
    if (depth[v] > depth[u])
        swap(u, v);
    u = go(u, depth[u] - depth[v]);
    if (u == v)
        return u;
    for (int i = LOG - 1; i >= 0; i--) {
        if (up[v][i] != up[u][i]) {
            v = up[v][i];
            u = up[u][i];
        }
    }
    return up[v][0];
}

node *tt[MAXM];

void dfs(int v, node *n, int p) {
    n = update(n, 0, MAXN, arr[v]);
    tt[v] = n;
    for (int u : g[v]) {
        if (u != p) {
            dfs(u, n, v);
        }
    }
}

int query(node *a, node *b, int l, int r, int ql, int qr) {
    if (ql <= l && r <= qr) {
        if (a->val == b->val) {
            return -2;
        }
        if (l + 1 == r) {
            return l;
        }
        int m = (l + r) / 2;
        int a1 = query(a->l, b->l, l, m, ql, qr);
        if (a1 != -2) {
            return a1;
        }
        int a2 = query(a->r, b->r, m, r, ql, qr);
        return a2;
    }
    if (ql >= r || qr <= l) {
        return -2;
    }
    int m = (l + r) / 2;
    int a1 = query(a->l, b->l, l, m, ql, qr);
    if (a1 != -2)
        return a1;
    int a2 = query(a->r, b->r, m, r, ql, qr);
    return a2;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        arr[i]--;
    }
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfsLCA(0);
    node *tree = new node();
    byval[0] = tree;
    byval[1] = new node();
    byval[1]->val = 1;
    while (MAXN < n) {
        MAXN *= 2;
        tree = merge(tree, tree);
    }
    dfs(0, tree, -1);
    while (q--) {
        int u, v, l, r;
        cin >> u >> v >> l >> r;
        u--;
        v--;
        l--;
        node *a = tt[u];
        node *b = tt[v];
        int c = lca(u, v);
        a = update(a, 0, MAXN, arr[c]);
        int ans = query(a, b, 0, MAXN, l, r);
        ans++;
        cout << ans << '\n';
    }
}