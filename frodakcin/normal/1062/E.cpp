#include <iostream>
#include <cstdio>

#include <vector>

#include <cassert>

using namespace std;

const int MAXN = 1e5 + 100;
const int MAXQ = 1e5 + 100;

typedef vector<int> vi;
#define pb push_back

int N, Q;
vi adj[MAXN];

int d[MAXN];
int p[MAXN][100];

int log2(int v) {
    int r = 1;
    while(v>>=1) r++;
    return r;
}
int mu(int& n, int l) {
    assert(d[n] >= l);
    for(int j = log2(d[n] - l);j >= 0;j--) {
        if(d[n] - (1 << j) >= l) assert((n = p[n][j]) != -1);
    }
    assert(d[n] == l);
    return n;
}
int lca(int a, int b) {
    if(a == b) return a;
    if(d[a] > d[b]) swap(a, b);
    mu(b, d[a]);
    
    if(a == b) return a;
    for(int j = log2(d[a]);j >= 0;j--) {
        if(d[a] - (1 << j) >= 0 and p[a][j] != p[b][j]) assert((a = p[a][j]) != -1 and (b = p[b][j]) != -1);
    }
    assert(p[a][0] != -1 and p[a][0] == p[b][0]);
    return p[a][0];
}

int l[MAXN][2];
int v[MAXN];

void dfsinit(int& ctr, const int& n = 0, const int& de = 0) {
    d[n] = de;
    for(int j = 0;j < 100;j++) if(p[n][j] != -1 and p[p[n][j]][j] != -1) p[n][j+1] = p[p[n][j]][j]; else break;
    for(int i = 0;i < adj[n].size();i++) dfsinit(ctr, adj[n][i], de + 1);
    v[ctr] = n;
    l[n][0] = ctr++;
}

void doL(int * a, int v) {
    for(int i = 0;i < 2;i++) if(l[v][0] < l[a[i]][0]) swap(v, a[i]);
}
void doR(int * a, int v) {
    for(int i = 2;i < 4;i++) if(l[v][0] > l[a[i]][0]) swap(v, a[i]);
}
void comb(int * a, int * v) {
    for(int i = 0;i < 2;i++) doL(a, v[i]);
    for(int i = 2;i < 4;i++) doR(a, v[i]);
}

struct NODE {
    int val[4];
    NODE * l, *r;
    NODE() {l = nullptr; r = nullptr; val[0] = val[1] = N + 1, val[2] = val[3] = N;}
    void ndoL(int v) {doL(val, v);}
    void ndoR(int v) {doR(val, v);}
    void ncomb(NODE& o) {comb(val, o.val);}
};
struct ST {
    NODE * h;
    int s;
    ST(const int& v = 0) {
        s = v;
        h = nullptr;
    }
    void init(NODE * n, int nl, int nr) {
        if(nr - nl > 1) {
            int m = nl + ((nr-nl)>>1);
            init(n->l = new NODE(), nl, m);
            init(n->r = new NODE(), m, nr);
            (*n).ncomb(*(n->l));
            (*n).ncomb(*(n->r));
        } else {
            n->val[0] = n->val[2] = nl;
        }
        /*
        printf("%d %d: ", nl, nr);
        for(int i = 0;i < 4;i++) printf("%d ", n->val[i]);
        printf("\n");
        //*/
    }
    void init() {init(h = new NODE(), 0, s);}
    
    void query(NODE * n, const int& nl, const int& nr, const int& gl, const int& gr, int * v) {
        if(gl >= gr or nl >= gr or gl >= nr) return;
        if(gr >= nr and gl <= nl) {
            comb(v, n->val);
            return;
        }
        if(nr - nl > 1) {
            int m = nl + ((nr - nl)>>1);
            if(nl < m) query(n->l, nl, m, gl, gr, v);
            if(nr > m) query(n->r, m, nr, gl, gr, v);
            return;
        }
        assert(false);
    }
    void query(int gl, int gr, int * v) {query(h, 0, s, gl, gr, v);}
} st;

int main() {
    scanf("%d%d", &N, &Q);
    for(int i = 0;i < N;i++) for(int j = 0;j < 100;j++) p[i][j] = -1;
    d[0] = 0;
    
    for(int i = 1, u;i < N;i++) {
        scanf("%d", &u);
        adj[--u].pb(i);
        p[i][0] = u;
    }
    int ctr = 0;
    dfsinit(ctr);
    assert(ctr == N);
    
    /*
    for(int i = 0;i < N;i++) {
        printf("%d: ", i);
        for(int j = 0;;j++) if(p[i][j] != -1) printf("%d ", p[i][j]); else break;
        printf("\n");
    }
    //*/
    
    l[N][0] = -1;
    l[N+1][0] = N + 100;
    
    st = ST(N);
    st.init();
    
    int v[4];
    for(int i = 0, a, b;i < Q;i++) {
        v[0] = v[1] = N+1, v[2] = v[3] = N;
        
        scanf("%d%d", &a, &b);
        
        st.query(--a, b, v);
        
        /*
        for(int i = 0;i < 4;i++) printf("%d ", v[i]);
        printf("\n");
        */
        
        int A = v[0], B = d[lca(v[1], v[2])], t;
        if((t = d[lca(v[0], v[3])]) > B) A = v[2], B = t;
        printf("%d %d\n", A + 1, B);
        
    }
    
    return 0;
}