#include <iostream>
#include <cstdio>

#include <vector>

#include <cassert>

using namespace std;

const int MAXN = 1e5 + 1000;
const int MAXQ = 1e5 + 1000;

typedef long long ll;
#define tll(x) static_cast<ll>(x)

int a[MAXN], b[MAXN];
struct ST {
    int l[MAXN * 3];
    int r[MAXN * 3];
    ll v[MAXN * 3];
    ll lz[MAXN * 3];
    int NXT;
    int sz;
    
    ST(const int& s) {
        NXT = 0;
        sz = s;
    }
    int nn() {
        l[NXT] = r[NXT] = -1;
        v[NXT] = lz[NXT] = 0LL;
        return NXT++;
    }
    void init(int n, int nl, int nr) {
        assert(nl < nr);
        if(nr - nl == 1) {
            v[n] = tll(a[nl]);
        } else {
            int m = nl + ((nr - nl)>>1);
            init(l[n] = nn(), nl, m);
            init(r[n] = nn(), m, nr);
            v[n] = v[l[n]] + v[r[n]];
        }
    }
    void init() {init(nn(), 0, sz);}
    void prop(int n, int nl, int nr) {
        if(lz[n] == 0) return;
        if(nr - nl > 1) {
            lz[l[n]] += lz[n];
            lz[r[n]] += lz[n];
        }
        v[n] += tll(nr - nl) * lz[n];
        lz[n] = 0;
    }
    void upd(int n, int nl, int nr, int gl, int gr, int d) {
        if(gl >= gr) return;
        ll prv = v[n];
        if(gl <= nl and gr >= nr) {
            lz[n] += d;
            prop(n, nl, nr);
            return;
        }
        if(nr - nl > 1) {
            int m = nl + ((nr - nl)>>1);
            prop(n, nl, nr);
            if(gl < m) upd(l[n], nl, m, gl, gr, d); else prop(l[n], nl, m);
            if(gr > m) upd(r[n], m, nr, gl, gr, d); else prop(r[n], m, nr);
            v[n] = v[l[n]] + v[r[n]];
            return;
        }
        assert(false);
    }
    void upd(int gl, int gr, int d) {upd(0, 0, sz, gl, gr, d);}
    ll qry(int n, int nl, int nr, int gl, int gr) {
        if(gl >= gr) return 0LL;
        prop(n, nl, nr);
        if(gl <= nl and gr >= nr) {
            return v[n];
        }
        if(nr - nl > 1) {
            int m = nl + ((nr - nl)>>1);
            
            ll re = 0;
            if(gl < m) re += qry(l[n], nl, m, gl, gr);
            if(gr > m) re += qry(r[n], m, nr, gl, gr);
            return re;
        }
        assert(false);
        return -1LL;
    }
    ll qry(int gl, int gr) {return qry(0, 0, sz, gl, gr);}
} st(-1);

int N, Q;

typedef vector<int> vi;
#define pb push_back

vi adj[MAXN];
int ord[MAXN][2];

bool enc(const int& u, const int& v) {
    //assert(u != v);
    return ord[u][0] <= ord[v][0] and not (ord[u][1] < ord[v][1]);
}

int log2(int v) {
    int r = 1;
    while(v>>=1) r++;
    return r;
}

int p[MAXN][100];
int d[MAXN];

void dfsinit(const int& n = 1, const int& pa = -1, int * cur = new int(0), const int& de = 0) {
    p[n][0] = pa;
    d[n] = de;
    for(int i = 0;i < 100;i++) if(p[n][i] != -1 and p[p[n][i]][i] != -1) p[n][i + 1] = p[p[n][i]][i];
    
    ord[n][0] = (*cur)++;
    for(int i = 0;i < adj[n].size();i++) if(adj[n][i] != pa) dfsinit(adj[n][i], n, cur, de + 1);
    ord[n][1] = *cur;
    
    //cerr << n << " " << ord[n][0] << " " << ord[n][1] << "\n";
}
int MU(int n, const int& l) {
    assert(d[n] >= l);
    for(int i = log2(d[n] - l);i >= 0;i--) {
        if(d[n] - (1 << i) >= l) assert((n = p[n][i]) != -1);
    }
    assert(d[n] == l);
    return n;
}
int lca(int a, int b) {
    if(d[a] > d[b]) swap(a, b);
    b = MU(b, d[a]);
    if(a == b) return a;
    
    for(int i = log2(d[a]);i >= 0;i--) {
        if(d[a] >= (1 << i)) if(p[a][i] != p[b][i]) assert((a = p[a][i]) != -1 and (b = p[b][i]) != -1);
    }
    assert(a != b and p[a][0] != -1 and p[a][0] == p[b][0]);
    return p[a][0];
}

int root;

void qry2() {
    int u, v, x;
    scanf("%d%d%d", &u, &v, &x);
    
    if(u == root or v == root) {
        st.upd(0, N, x);
        return;
    }
    if(enc(root, u) xor enc(root, v)) {
        st.upd(0, N, x);
        return;
    }
    int cn = lca(u, v);
    if(enc(root, u) and enc(root, v)) {
        if(cn == root) st.upd(0, N, x);
        else st.upd(ord[cn][0], ord[cn][1], x);
        return;
    }
    
    int nr = root;
    for(int i = log2(d[nr]);i >= 0;i--) if(d[nr] >= (1 << i) and not enc(p[nr][i], u) and not enc(p[nr][i], v)) nr = p[nr][i];
    if(d[nr] - 1 >= d[cn]) {
        st.upd(0, ord[nr][0], x);
        st.upd(ord[nr][1], N, x);
    } else st.upd(ord[cn][0], ord[cn][1], x);
    
}
void qry3() {
    int u;
    scanf("%d", &u);
    
    if(u == root) {
        printf("%lld\n", st.qry(0, N));
        return;
    }
    if(enc(u, root)) {
        int nr = MU(root, d[u] + 1);
        printf("%lld\n", st.qry(0, ord[nr][0]) + st.qry(ord[nr][1], N));
        return;
    }
    
    printf("%lld\n", st.qry(ord[u][0], ord[u][1]));
}

int main() {
    root = 1;
    
    for(int i = 0;i <= N;i++) for(int j = 0;j < 100;j++) p[i][j] = -1;
    
    scanf("%d%d", &N, &Q);
    for(int i = 1;i <= N;i++) scanf("%d", b + i);
    for(int i = 0, u, v;i < N - 1;i++) {
        scanf("%d%d", &u, &v);
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfsinit();
    
    for(int i = 1;i <= N;i++) a[ord[i][0]] = b[i];
    
    st = ST(N);
    st.init();
    
    int type;
    while(Q--) {
        scanf("%d", &type);
        if(type == 1) scanf("%d", &root);
        if(type == 2) qry2();
        if(type == 3) qry3();
    }
    
    return 0;
}