#include <bits/stdc++.h>

using namespace std;

#define MN 200100

template<typename T>
struct segtree {
    T tree[4*MN];
    char clear_[4*MN];

    segtree() {
        memset(tree, 0, sizeof tree);
        memset(clear_, 0, sizeof clear_);
    }

    T identity() { return 0; }

    T merge(T a, T b) { return max(a, b); }

    void do_lazy(int id, int l, int r) {
        if(clear_[id]) {
            tree[id] = 0;
            if(l != r) {
                clear_[id*2]   = 1;
                clear_[id*2+1] = 1;
            }
            clear_[id] = 0;
        }
    }

    T query(int id, int l, int r, int lq, int rq) {
        do_lazy(id, l, r);
        if(r < lq || rq < l) return identity();
        if(lq <= l && r <= rq) return tree[id];
        int m = (l + r) / 2;
        return merge(query(id*2,   l,   m, lq, rq),
                     query(id*2+1, m+1, r, lq, rq));
    }

    void update(int id, int l, int r, int pos, T val) {
        do_lazy(id, l, r);
        if(r < pos || pos < l || l > r) return;
        if(l == r) {
            if(val == 0) tree[id] = 0;
            else tree[id] = max(tree[id], val);
            return;
        }
        int m = (l + r) / 2;
        update(id*2,   l,   m, pos, val);
        update(id*2+1, m+1, r, pos, val);
        tree[id] = merge(tree[id*2], tree[id*2+1]);
    }
};

vector<int> adj[200020];
int n, d[200020], k, ans[200020];
int visited[200020], dist[200020];

segtree<int> st;

void dfs_dist(int u, int dep = 0, int pai = -1) {
    if(visited[u]) return;
    dist[u] = d[u] - dep;
    for(int v : adj[u])
        if(v != pai)
            dfs_dist(v, dep + 1, u);
}

void dfs_upd(int u, int pai, int mini, int val) {
    if(visited[u]) return;
    mini = min(mini, dist[u]);
    if(mini > 0) st.update(1, 1, n, mini, d[u] * val);//, printf("put %d %d | %d %d\n", mini, dist[u] * val, u, pai);
    for(int v : adj[u])
        if(v != pai)
            dfs_upd(v, u, mini, val);
}

void dfs_ans(int u, int pai, int dep, int val) {
    if(visited[u]) return;
    val = min(val, d[u]);
    if(val > 0) ans[u] = max(ans[u], st.query(1, 1, n, dep + 1, n));
    for(int v : adj[u])
        if(v != pai)
            dfs_ans(v, u, dep + 1, val - 1);
}

void cmon(int r) {
    dfs_dist(r);

    if(dist[r]) st.update(1, 1, n, dist[r], d[r]);
    for(int i = 0; i < adj[r].size(); i++) {
        dfs_ans(adj[r][i], r, 1, dist[r] - 1);
        dfs_upd(adj[r][i], r, dist[r], 1);
    }
    st.clear_[1] = 1;

    for(int i = adj[r].size() - 1; i >= 0; i--) {
        dfs_ans(adj[r][i], r, 1, dist[r] - 1);
        dfs_upd(adj[r][i], r, dist[r], 1);
    }
    if(dist[r]) ans[r] = max(ans[r], st.query(1, 1, n, 1, n));
    st.clear_[1] = 1;
}

struct centroid_tree {
    int root;
    int siz[MN];

    centroid_tree () {
        //init();
        //build_tree();
    }

    int get_centroid(int u, int p = 0) {
        siz[u] = 1;
        for (int v : adj[u])
            if (v != p && !visited[v]) {
                get_centroid(v, u);
                siz[u] += siz[v];
            }
        if (p) return 0;

        int par = 0, aux = u, nxt = 0;
        while (1) {
            for (int v : adj[aux])
                if (!visited[v] && v != par && siz[v] > siz[u] / 2)
                    nxt = v;

            if (!nxt) {
                cmon(aux);
                return aux;
            }
            else { par = aux; aux = nxt; nxt = 0; }
        }
    }

    void build_tree(int u = 0) {
        if (u == 0) {
            u = root = get_centroid(1);
            visited[u] = 1;
        }

        for (int v : adj[u])
            if (!visited[v]) {
                int x = get_centroid(v);
                visited[x] = 1;
                build_tree(x);
            }
    }
} ct;

int main() {
    scanf("%d", &n);
    for(int i = 1; i < n; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    scanf("%d", &k);

    queue<int> q;
    fill(d, d + n + 1, 1234567);
    for(int i = 0; i < k; i++) {
        int a;
        scanf("%d", &a);
        q.push(a);
        d[a] = 0;
    }
    while(!q.empty()) {
        int u = q.front(); q.pop();
        for(int v : adj[u]) {
            if(d[v] > d[u] + 1) {
                d[v] = d[u] + 1;
                q.push(v);
            }
        }
    }

    ct.build_tree();
    for(int i = 1; i <= n; i++)
        printf("%d ", max(ans[i], d[i]));

    return 0;
}