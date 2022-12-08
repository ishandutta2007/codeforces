#include <iostream>
#include <cstdio>

#include <cassert>

using namespace std;

const int MAXN = 2e5 + 100;
const int MAXM = 15;

int N, Q, M;

int log2(int v) {
    int r = 1;
    while(v>>=1) r++;
    return r;
}

int a[MAXN];
int t[2][MAXN];

struct ST {
    int v[3*MAXN][2][MAXM];
    int l[3*MAXN], r[3*MAXN];
    bool lz[3*MAXN];
    
    int NXT;
    int sz;
    
    void updv(const int& n) {
        assert(n != -1 and l[n] != -1 and r[n] != -1);
        for(int i = 0;i <= M;i++) for(int j = 0;j < 2;j++) v[n][j][i] = v[l[n]][j][v[r[n]][j][i]];
    }
    void init(int n, int nl, int nr) {
        assert(n != -1 and nl < nr);
        lz[n] = false;
        l[n] = r[n] = -1;
        if(nr - nl == 1) {
            for(int i = 0;i < M;i++) for(int j = 0;j < 2;j++) v[n][j][i] = i + 1;
            v[n][a[nl]][M] = M, v[n][!a[nl]][M] = 0;
        }
        if(nr - nl > 1) {
            int m = nl + ((nr - nl)>>1);
            init(l[n] = NXT++, nl, m);
            init(r[n] = NXT++, m, nr);
            
            updv(n);
        }
        //cerr << nl << " " << nr << " " << v[n][0][0] << " " << v[n][0][1] << " " << v[n][0][2] << "\n";
    }
    ST(){}
    ST(const int& s, bool ini) {
        sz = s;
        NXT = 0;
        if(ini) init(NXT++, 0, sz);
    }
    
    void prop(int n, int nl, int nr) {
        if(!lz[n]) return;
        
        for(int i = 0;i <= M;i++) swap(v[n][0][i], v[n][1][i]);
        
        if(nr - nl > 1) {
            lz[l[n]] = !lz[l[n]];
            lz[r[n]] = !lz[r[n]];
        }
        
        lz[n] = false;
    }
    void upd(int n, int nl, int nr, int gl, int gr) {
        //prop(n, nl, nr);
        
        if(gl <= nl and gr >= nr) {
            
            lz[n] = !lz[n];
            prop(n, nl, nr);
            
            return;
        }
        if(nr - nl > 1) {
            prop(n, nl, nr);
            int m = nl + ((nr - nl)>>1);
            
            if(gl < m) upd(l[n], nl, m, gl, gr); else prop(l[n], nl, m);
            if(gr > m) upd(r[n], m, nr, gl, gr); else prop(r[n], m, nr);
            
            updv(n);
            
            return;
        }
        
        assert(false);
    }
    void upd(int gl, int gr) {upd(0, 0, sz, gl, gr);}
    
    int qry(int n, int nl, int nr, int gl, int gr, int c = M) {
        prop(n, nl, nr);
        
        if(gl <= nl and gr >= nr) {
            return v[n][0][c];
        }
        if(nr - nl > 1) {
            int m = nl + ((nr - nl)>>1);
            
            if(gr > m) c = qry(r[n], m, nr, gl, gr, c);
            if(gl < m) c = qry(l[n], nl, m, gl, gr, c);
            
            return c;
        }
        assert(false);
        return -1;
    }
    int qry(int gl, int gr) {return qry(0, 0, sz, gl, gr);}
    
} st;

void q1() {
    int l, r, v;
    scanf("%d%d%d", &l, &r, &v);
    if(v&1) st.upd(--l, r);
}
void q2() {
    int l, r;
    scanf("%d%d", &l, &r);
    printf("%d\n", (st.qry(--l, r) == 0 ? 2 : 1));
    //printf("%d\n", st.qry(--l, r));
}

int main() {
    scanf("%d%d%d", &N, &M, &Q);
    
    for(int i = 0, v;i < N;i++) {
        scanf("%d", &v);
        a[i] = v&1;
    }
    
    st = *(new ST(N, true));
    
    
    for(int i = 0, type;i < Q;i++) {
        scanf("%d", &type);
        if(type == 1) q1();
        else if(type == 2) q2();
    }
    
    return 0;
}