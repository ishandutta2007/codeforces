#include <iostream>
#include <cstdio>

#include <vector>
#include <queue>
#include <set>

#include <cassert>

using namespace std;

const int MAXN = 2e5 + 1000;
const int MAXQ = 2e5 + 1000;

#define is ==

typedef deque<int> dq;
struct NODE {
    NODE * l, *r;
    int v, c;
    int lz;
    NODE() {
        l = nullptr;
        r = nullptr;
    }
};
struct ST {
    NODE * h;
    int s;
    ST() {h = nullptr, s = -1;}
    void init(const int& n) {init(h = new NODE(), 0, s = n);}
    void init(NODE * n, int nl, int nr) {
        n->v = n->lz = 0, n->c = nr - nl;
        if(nr - nl > 1) {
            int m = nl + ((nr - nl)>>1);
            init(n->l = new NODE(), nl, m), init(n->r = new NODE(), m, nr);
        }
    }
    ST(const int& v) {init(h = new NODE(), 0, s = v);}
    void prop(NODE * n, int nl, int nr) {
        if(n->lz == 0) return;
        n->v += n->lz;
        if(nr - nl > 1) {
            n->l->lz += n->lz;
            n->r->lz += n->lz;
        }
        n->lz = 0;
    }
    void upd(int gl, int gr, int v) {upd(h, 0, s, gl, gr, v);}
    void upd(NODE * n, int nl, int nr, int gl, int gr, int v) {
        prop(n, nl, nr);
        if(gr <= gl or nr <= gl or gr <= nl) return;
        if(gl <= nl and nr <= gr) {
            n->lz += v;
            prop(n, nl, nr);
            return;
        }
        if(nr - nl > 1) {
            int m = nl + ((nr - nl)>>1);
            if(gl < m) upd(n->l, nl, m, gl, gr, v); else prop(n->l, nl, m);
            if(m < gr) upd(n->r, m, nr, gl, gr, v); else prop(n->r, m, nr);
            
            n->v = min(n->l->v, n->r->v), n->c = 0;
            if(n->l->v == n->v) n->c += n->l->c;
            if(n->r->v == n->v) n->c += n->r->c;
            
            assert(n->c);
            return;
        }
        assert(false);
    }
    int qry() {prop(h, 0, s); return h->v is 0 ? h->c : 0;}
};

int N, Q;
typedef vector<int> vi;
#define pb push_back

vi adj[MAXN];

int loc[MAXN][2];
int par[MAXN][25];
int d[MAXN];

void dfs(const int& n, int& c, const int& p = -1, int dv = 0) {
    loc[n][0] = c++;
    d[n] = dv;
    par[n][0] = p;
    for(int i = 1;(1 << i) <= N;i++) if(par[n][i-1] != -1 and par[par[n][i-1]][i-1] != -1) par[n][i] = par[par[n][i-1]][i-1];
    for(int i = 0;i < adj[n].size();i++) if(adj[n][i] != p) dfs(adj[n][i], c, n, dv + 1);
    loc[n][1] = c;
}

int log2(int n) {
    int r = 1;
    while(n>>=1) r++;
    return r;
}
int mu(int a, int df) {
    assert(d[a] > df);
    for(int i = log2(d[a] - df);i >= 0;i--) if(par[a][i] != -1 and d[par[a][i]] > df) a = par[a][i];
    return a;
}

typedef set<int> si;
#define IT iterator
si e[MAXN];

int main() {
    scanf("%d%d", &N, &Q);
    
    for(int i = 0, a, b;i < N - 1;i++) {
        scanf("%d%d", &a, &b);
        a--, b--;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    
    for(int i = 0;i <= N;i++) for(int j = 0; (1<<j) <= N;j++) par[i][j] = -1;
    
    ST st;
    int ct = 0;
    dfs(0, ct);
    assert(ct == N);
    
    st.init(ct);
    
    //for(int i = 0;i < N;i++) cerr << i << " " << loc[i][0] << " " << loc[i][1] << "\n";
    //for(int i = 0;i < N;i++) cerr << d[i] << "\n";
    
    for(int i = 0, a, b, t;i < Q;i++) {
        scanf("%d%d", &a, &b);
        a--, b--;
        if(a > b) swap(a, b);
        si::IT it;
        
        int uv = 0;
        
        if((it = e[a].find(b)) != e[a].end()) uv = -1, e[a].erase(it);
        else uv = 1, e[a].insert(b);
        
        assert(loc[a][0] != loc[b][0]);
        if(loc[a][0] > loc[b][0]) swap(a, b);
        if(loc[b][1] <= loc[a][1]) t = mu(b, d[a]), st.upd(loc[t][0], loc[t][1], uv), st.upd(loc[b][0], loc[b][1], -uv);
        else st.upd(0, ct, uv), st.upd(loc[a][0], loc[a][1], -uv), st.upd(loc[b][0], loc[b][1], -uv);
        
        printf("%d\n", st.qry());
    }
    
    return 0;
}