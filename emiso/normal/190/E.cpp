#include <bits/stdc++.h>

using namespace std;

struct union_find {
    vector<int> parent, rank_;
    union_find(int n) {
        init(n);
    }
    void init(int n) {
        parent.resize(n + 1); rank_.resize(n + 1);
        for(int i = 0; i <= n; i++)
            parent[i] = i, rank_[i] = 1;
    }
    int find(int node) {
        if(node == parent[node]) return node;
        return parent[node] = find(parent[node]);
    }
    bool join(int a, int b) {
        a = find(a); b = find(b);
        if(a == b) return false;
        if(rank_[a] < rank_[b]) swap(a, b);
        parent[b] = a;
        rank_[a] += rank_[b];
        return true;
    }
};

int n, m, ok[4*500050];
union_find* dsu;
vector<int> adj[500050], ans[4*500050];

int find(int id, int l, int r, int x) {
    if(l == r) return id;
    int m = (l + r) / 2;
    if(x <= m) return find(id*2, l, m, x);
    else return find(id*2+1, m+1, r, x);
}

void expand(int id, int l, int r) {
    if(ok[id]) return;
    ok[id] = 1;

    if(l == r) return;
    dsu->join(id, id*2);
    dsu->join(id, id*2+1);

    int m = (l + r) / 2;
    expand(id*2, l, m);
    expand(id*2+1, m+1, r);
}

void upd(int id, int l, int r, int u, int lq, int rq) {
    if(rq < l || r < lq) return;
    if(lq <= l && r <= rq) {
        dsu->join(id, u);
        expand(id, l, r);
        return;
    }
    int m = (l + r) / 2;
    upd(id*2,   l,   m, u, lq, rq);
    upd(id*2+1, m+1, r, u, lq, rq);
}

int main() {
    scanf("%d %d", &n, &m);
    dsu = new union_find(4*n);

    for(int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        adj[min(a, b)].push_back(max(a, b));
    }

    for(int i = 1; i <= n; i++) {
        sort(adj[i].begin(), adj[i].end());
        int u = find(1, 1, n, i), last = i-1;
        for(int x : adj[i]) {
            if(last + 1 <= x - 1)
                upd(1, 1, n, u, last + 1, x - 1);
            last = x;
        }
        if(last + 1 <= n)
            upd(1, 1, n, u, last + 1, n);
    }

    int sz = 0;
    for(int i = 1; i <= n; i++) {
        int tmp = dsu->find(find(1, 1, n, i));
        if(ans[tmp].empty()) sz++;
        ans[tmp].push_back(i);
    }

    printf("%d\n", sz);
    for(int i = 0; i < 4*500050; i++) {
        if(ans[i].empty()) continue;
        printf("%d", ans[i].size());
        for(int x : ans[i]) printf(" %d", x);
        puts("");
    }
    return 0;
}