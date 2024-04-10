#include <bits/stdc++.h>

using namespace std;

#define MN 100100
int sz[MN], st[MN], ft[MN], ver[MN], color[MN], cnt[MN], t = 1;
vector<int> adj[MN];

int ans[MN];
vector<pair<int, int>> qs[MN];

template<typename T>
struct fenwick_tree {
    vector<T> a;
    fenwick_tree(int n) { a.resize(n + 1); }
    void upd(int idx, T delta) {
        for(; idx < a.size(); idx+=(idx&-idx)) a[idx] += delta;
    }
    T query(int idx) {
        T ret = 0;
        for(; idx; idx -= (idx & -idx)) ret += a[idx];
        return ret;
    }
};
fenwick_tree<int> bit(MN);

void calc(int node, int parent) {
    sz[ver[t] = node] = 1;
    st[node] = t++;
    for(int v : adj[node]) {
        if(v == parent) continue;
        calc(v, node);
        sz[node] += sz[v];
    }
    ft[node] = t;
}
void dfs(int node, int par, int keep) {
    int big = -1, maxi = -1;
    for(int v : adj[node]) if(v != par && sz[v] > maxi) maxi = sz[big = v];
    for(int v : adj[node]) if(v != par && v != big) dfs(v, node, 0);
    if(big != -1) dfs(big, node, 1);
    for(int v : adj[node]) {
        if(v == par || v == big) continue;
        for(int T = st[v]; T < ft[v]; T++) {
            if(cnt[color[ver[T]]])
                bit.upd(cnt[color[ver[T]]], -1);
            cnt[color[ver[T]]]++;
            bit.upd(cnt[color[ver[T]]], +1);
        }
    }
    if(cnt[color[node]])
        bit.upd(cnt[color[node]], -1);
    cnt[color[node]]++;
    bit.upd(cnt[color[node]], +1);

    for(auto query : qs[node]) {
        ans[query.second] = bit.query(MN) - bit.query(query.first);
    }

    if(!keep) for(int T = st[node]; T < ft[node]; T++) {
        bit.upd(cnt[color[ver[T]]], -1);
        cnt[color[ver[T]]]--;
        if(cnt[color[ver[T]]])
            bit.upd(cnt[color[ver[T]]], +1);
    }
}

void solve(int root) {calc(root, -1); dfs(root, -1, 0);}

int n, m;

int main() {
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++)
        scanf("%d", &color[i]);
    for(int i = 1, u, v; i < n; i++) {
        scanf("%d %d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i = 0, v, x; i < m; i++) {
        scanf("%d %d", &v, &x);
        qs[v].emplace_back(x-1, i);
    }
    solve(1);
    for(int i = 0; i < m; i++)
        printf("%d\n", ans[i]);
    return 0;
}