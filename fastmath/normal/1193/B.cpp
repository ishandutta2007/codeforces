#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define ii pair <int, int>
#define app push_back
#define l first
#define r second
const int N = 1e5 + 7;
const int INF = 1e9 + 7;
mt19937 rnd(228);
struct Node {
    int x, y, dp, mx, add;
    Node *l, *r;
    Node (int x_, int dp_) {
        x = x_; y = rnd(); dp = mx = dp_; add = 0;
        l = r = NULL; 
    }
    Node () {}
};  
int max(Node *t) {
    if (!t) return 0;
    else return t->mx;
}   
void make_add(Node *t, int x) {
    if (t) {
        t->dp += x; t->mx += x; t->add += x;
    }
}   
void push(Node *t) {
    if (t->add) {
        make_add(t->l, t->add); make_add(t->r, t->add); t->add = 0;
    }
}   
void relax(Node *t) {
    t->mx = max(max(max(t->l), max(t->r)), t->dp);
}   
pair <Node*, Node*> split(Node *t, int x) {
    if (!t) return {NULL, NULL};
    push(t);
    if (t->x < x) {
        auto tmp = split(t->r, x);
        t->r = tmp.l; 
        relax(t);
        return {t, tmp.r};
    }   
    else {
        auto tmp = split(t->l, x);
        t->l = tmp.r;
        relax(t);
        return {tmp.l, t};
    }   
}
Node *merge(Node *l, Node *r) {
    if (!l) return r; if (!r) return l;
    push(l); push(r);
    if (l->y < r->y) {
        l->r = merge(l->r, r); relax(l); return l;
    }   
    else {
        r->l = merge(l, r->l); relax(r); return r;
    }   
}   
void insert(Node *&t, Node *e) {
    auto tmp = split(t, e->x);
    t = merge(merge(tmp.l, e), tmp.r);
}  
void print(Node *t, vector <Node*> &ar) {
    if (!t) return;
    push(t);
    print(t->l, ar); ar.app(t); print(t->r, ar);
}   
void debug(Node *t) {
    if (!t) return;
    debug(t->l);
    cout << t->x << ' ' << t->dp << '\n';
    debug(t->r);
}   
Node *dp[N];

vector <int> g[N];
int d[N], c[N], cnt[N];
void dfs(int u) {
    cnt[u] = 1; int mx = -1;
    for (int v : g[u]) {
        dfs(v);
        cnt[u] += cnt[v];
        if (mx == -1 || cnt[mx] < cnt[v]) mx = v;
    }
    if (mx == -1) {
        if (d[u] == -1) dp[u] = NULL;
        else dp[u] = new Node(d[u], c[u]);
        #ifdef HOME
        cout << "debug " << u + 1 << '\n';
        debug(dp[u]);
        cout << '\n';
        #endif
        return;
    }   
    int lmao = c[u];
    if (d[u] != -1) {
        for (int v : g[u]) {
            auto tmp = split(dp[v], d[u] + 1);
            lmao += max(tmp.l);
            dp[v] = merge(tmp.l, tmp.r);
        }   
    }
    swap(dp[u], dp[mx]);
    for (int v : g[u]) {
        if (v == mx) continue;
        vector <Node*> ar;
        print(dp[v], ar);
        reverse(ar.begin(), ar.end());
        vector <int> sub;
        for (auto e : ar) {
            auto tmp = split(dp[u], e->x + 1);
            sub.app(max(tmp.l));
            dp[u] = merge(tmp.l, tmp.r);
        }   
        vector <ii> add; // if x >= first : x += second
        for (auto e : ar) {
            while (add.size() && add.back().second <= e->dp) add.pop_back();
            add.app({e->x, e->dp});
        }   
        int pr = INF;
        for (auto e : add) {
            auto tmp1 = split(dp[u], e.first);
            auto tmp2 = split(tmp1.r, pr);
            make_add(tmp2.l, e.second);
            dp[u] = merge(tmp1.l, merge(tmp2.l, tmp2.r));
            pr = e.first;
        }   
        for (int i = 0; i < ar.size(); ++i) {
            insert(dp[u], new Node(ar[i]->x, sub[i] + ar[i]->dp));
        }   
    }   
    if (d[u] != -1) {
        insert(dp[u], new Node(d[u], lmao));
    }   
    #ifdef HOME
    cout << "debug " << u + 1 << '\n';
    debug(dp[u]);
    cout << '\n';
    #endif
}   
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 1; i < n; ++i) {
        int p; cin >> p; --p; g[p].app(i);
    }   
    for (int i = 0; i < n; ++i) d[i] = c[i] = -1;
    for (int i = 0; i < m; ++i) {   
        int v, dd, ww; cin >> v >> dd >> ww; --v;
        d[v] = dd; c[v] = ww;            
    }
    dfs(0);
    cout << max(dp[0]) << '\n';
}