#include <iostream>
#include <cstdio>

#include <algorithm>

#include <cassert>

using namespace std;

const int MAXN = 1e5 + 100;
const int MAXNL2 = 20;
const int NODES = MAXN * MAXNL2;

int maxv(int a, int b, int c) {
    int r = a;
    if(r < b) r = b;
    if(r < c) r = c;
    return r;
}
const inline void rpl(int& n, const int& v) {
    if(n < v) n = v;
}

struct PST {
    int l[NODES];
    int r[NODES];
    int p[NODES], s[NODES], c[NODES];       //prefix, suffix, combined
    int h[MAXN];
    int sz;
    int NXT;
    
    int nn(const int& v = -1) {
        if(v == -1) {
            l[NXT] = r[NXT] = -1;
            p[NXT] = s[NXT] = c[NXT] = 0;
        } else {
            l[NXT] = l[v], r[NXT] = r[v];
            p[NXT] = p[v], s[NXT] = s[v], c[NXT] = c[v];
        }
        return NXT++;
    }
    
    void init() {NXT = 0; init(h[0] = nn(), 1, sz + 1);}
    void init(int n, int nl, int nr) {
        assert(nl < nr);
        if(nr - nl > 1) {
            int m = nl + ((nr - nl)>>1);
            init(l[n] = nn(), nl, m);
            init(r[n] = nn(), m, nr);
        }
    }
    PST(const int& v = -1) {
        NXT = 0;
        sz = v;
    }
    
    void fix(int n, int nl, int nr) {
        int m = nl + ((nr - nl)>>1);
        p[n] = p[l[n]] == m - nl ? p[l[n]] + p[r[n]] : p[l[n]];
        s[n] = s[r[n]] == nr - m ? s[r[n]] + s[l[n]] : s[r[n]];
        c[n] = maxv(c[l[n]], c[r[n]], s[l[n]] + p[r[n]]);
    }
    void add(int n, int pn, int nl, int nr, int g) {
        if(nr - nl == 1) {
            assert(g == nl);
            p[n] = s[n] = c[n] = 1;
            return;
        }
        if(nr - nl > 1) {
            int m = nl + ((nr - nl)>>1);
            if(g < m) add(l[n] = nn(l[pn]), l[pn], nl, m, g);
            else add(r[n] = nn(r[pn]), r[pn], m, nr, g);
            
            fix(n, nl, nr);
            return;
        }
        assert(false);
    }
    void add(int lvl, int l) {
        add(h[lvl] = nn(h[lvl-1]), h[lvl-1], 1, sz + 1, l);
    }
    
    int qry(int n, int nl, int nr, int gl, int gr) {
        assert(gl < gr and nl < nr);
        if(gl <= nl and nr <= gr) {
            return c[n];
        }
        if(nr - nl > 1) {
            int m = nl + ((nr - nl)>>1);
            int f = 0;
            if(gl < m) rpl(f, qry(l[n], nl, m, gl, gr));
            if(m < gr) rpl(f, qry(r[n], m, nr, gl, gr));
            
            if(gl < m and m < gr) rpl(f, min(m - gl, s[l[n]]) + min(gr - m, p[r[n]]));
            
            return f;
        }
        assert(false);
        return -1;
    }
    int qry(int lvl, int gl, int gr) {
        return qry(h[lvl], 1, sz + 1, gl, gr);
    }
} pst;


int N, M;
int h[MAXN];
int ho[MAXN];

int a, b, w;
void solve() {
    scanf("%d%d%d", &a, &b, &w);
    ++b;
    
    int x = 0, y = N + 1;
    while(y > x + 1) {
        int m = x + ((y - x)>>1);
        if(pst.qry(m, a, b) < w) x = m;
        else y = m;
    }
    if(y == N + 1) printf("impossible!\n");
    else printf("%d\n", h[ho[y]]);
}

int main() {
    scanf("%d", &N);
    for(int i = 1;i <= N;i++) scanf("%d", h + i), ho[i] = i;
    sort(ho + 1, ho + N + 1, [](const int& a, const int& b){return h[b] < h[a];});
    
    pst = *(new PST(N));
    pst.init();
    for(int i = 1;i <= N;i++) pst.add(i, ho[i]);
    
    scanf("%d", &M);
    while(M--) solve(); 
    
    return 0;
}