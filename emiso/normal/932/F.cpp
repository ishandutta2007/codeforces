#include  <bits/stdc++.h>

using namespace std;
typedef long long ll;

struct func {
    ll a, b;
    func() {}
    func(ll a, ll b): a(a), b(b) {}
    ll y(ll x) { return a*x + b; }
};

struct li_chao {
    struct node {
        node *l, *r;
        func *f;
        node() {l = r = NULL; f = NULL;}
        ~node() {
            delete l;
            delete r;
            delete f;
        }
    };

    node *root;
    ll L, R;
    li_chao(ll l, ll r) {root = new node(); L = l; R = r;}

    void add_func(node *&t, ll L, ll R, func *f, ll lf, ll rf) {
        ll M = L + (R - L)/2;
        if(t == NULL) t = new node();
        if(f == NULL || rf < L || R < lf) return;

        else if(lf <= L && R <= rf) {
            if(t->f == NULL || f->y(M) < t->f->y(M))
                swap(t->f, f);
            if(L < R) {
                if(f == NULL || f->y(L) >= t->f->y(L))
                    add_func(t->r, M+1, R, f, lf, rf);
                else
                    add_func(t->l, L, M, f, lf, rf);
            }
        }
        else {
            add_func(t->l, L, M, f, lf, rf);
            add_func(t->r, M+1, R, f, lf, rf);
        }
    }

    ll query(node *t, ll L, ll R, ll x) {
        ll M = L + (R - L)/2;
        if(t == NULL) return LLONG_MAX;
        ll ret = (t->f == NULL) ? LLONG_MAX : t->f->y(x);
        if(L < R) {
            if(x <= M) ret = min(ret, query(t->l, L,   M, x));
            else       ret = min(ret, query(t->r, M+1, R, x));
        }
        return ret;
    }

    void add_func(func *f) {
        add_func(root, L, R, f, L, R);
    }

    void add_func(func *f, ll l, ll r) {
        add_func(root, L, R, f, l, r);
    }

    ll query(ll x) {
        return query(root, L, R, x);
    }

    ~li_chao() {
        delete root;
    }
};

const ll MN = 100010;
ll a[MN], b[MN], n, dp[MN];
int u, v;
vector<int> adj[MN];
li_chao *L;


// Small to Large Optimization ------------------

int sz[MN], st[MN], ft[MN], ver[MN], t = 1;

void calc(int node, int parent) {
    sz[node] = 1;
    ver[t] = node;
    st[node] = t++;
    for(int v : adj[node]) {
        if(v == parent) continue;
        calc(v, node);
        sz[node] += sz[v];
    }
    ft[node] = t;
}

void dfs(int node, int parent, int keep) {
    int big_child = -1, max_sz = -1;

    for(int v : adj[node]) {
        if(v != parent && sz[v] > max_sz) {
            max_sz = sz[v];
            big_child = v;
        }
    }

    for(int v : adj[node])
        if(v != parent && v != big_child)
            dfs(v, node, 0);

    if(big_child != -1)
        dfs(big_child, node, 1);

    int isLeaf = 1;
    for(int v : adj[node]) {
        if(v != parent) isLeaf = 0;
        if(v == parent || v == big_child) continue;
        for(int T = st[v]; T < ft[v]; T++) {
            int X = ver[T]; 
            L->add_func(new func(b[X], dp[X]));
        }
    }

    dp[node] = isLeaf ? 0 : L->query(a[node]);
    L->add_func(new func(b[node], dp[node]));

    if(!keep) {
        delete L;
        L = new li_chao(-MN, MN);
    }
}

int main() {
    scanf("%lld", &n);

    for(int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
    }
    for(int i = 1; i <= n; i++) {
        scanf("%lld", &b[i]);
    }

    for(int i = 1; i < n; i++) {
        scanf("%d %d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    L = new li_chao(-MN, MN);
    calc(1, -1);
    dfs(1, -1, 0);

    for(int i = 1; i <= n; i++)
        printf("%lld ", dp[i]);
    return 0;
}