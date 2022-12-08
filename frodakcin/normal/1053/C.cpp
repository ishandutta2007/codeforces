#include <cstdio>
#include <iostream>

#include <cassert>

using namespace std;

typedef long long ll;

#define ti(x) static_cast<int> (x)
#define tll(x) static_cast<ll> (x)

const int MAXN = 200000 + 100;
const int MOD = 1e9 + 7;
const ll MODM = tll(MOD) * 100;

int w[MAXN], x[MAXN];
int N, Q;

int prod(int a, int b) {
    if(a > 0 xor b > 0) return -ti((tll(-a) * b)%MOD);
    return ti((tll(a) * b)%MOD);
}
int sum(int a, int b) {
    return ti((tll(a) + b + MODM)%MOD);
}
int dif(int a, int b) {
    return ti((tll(a) - b + MODM)%MOD);
}

struct NODE {
public:
    int wl, wr;
    int ws;
    
    NODE * l;
    NODE * r;
    
    NODE() {
        l = nullptr;
        r = nullptr;
    }
};

struct ST {
public:
    NODE * h;
    int s;
    
    ST() {
        h = nullptr;
    }
    ST(int v) {
        s = v;
        h = new NODE();
        
        init(h, 0, s);
    }
    
    void init(NODE * n, int nl, int nr) {
        n->wl = n->wr = n->ws = 0;
        for(int i = nl;i < nr;i++) {
            n->ws = sum(n->ws, w[i]);
            n->wl = sum(n->wl, prod(w[i], x[i] - x[nl] - (i - nl) ));
            n->wr = sum(n->wr, prod(w[i], x[nr - 1] - x[i] - (nr - 1 - i) ));
        }
        
        if(nr - nl > 1) {
            int m = nl + (nr - nl)/2;
            
            n->l = new NODE();
            init(n->l, nl, m);
            
            n->r = new NODE();
            init(n->r, m, nr);
        }
    }
    
    void upd(int id, int nw) {
        upd(h, 0, s, id, nw);
        //w[id] = nw;
    }
    void upd(NODE * n, int nl, int nr, int id, int nw) {
        assert(nl <= id and id < nr);
        
        n->ws = sum(n->ws, dif(nw, w[id]));
        n->wl = sum(n->wl, prod(x[id] - x[nl] - (id - nl), dif(nw, w[id])));
        n->wr = sum(n->wr, prod(x[nr - 1] - x[id] - (nr - 1 - id), dif(nw, w[id])));
        
        if(nr - nl > 1) {
            int m = nl + (nr - nl)/2;
            
            if(id < m) upd(n->l, nl, m, id, nw);
            if(id >= m) upd(n->r, m, nr, id, nw);
        }
    }
    
    int ql(int gl, int gr, int g) {
        return ql(h, 0, s, gl, gr, g);
    }
    int ql(NODE * n, int nl, int nr, int gl, int gr, int g) {
        if(gl >= gr or gr <= nl or nr <= gl) return 0;
        
        assert(g < nr);
        
        if(g <= nl and gl <= nl and gr >= nr) return sum(n->wl, prod(n->ws, x[nl] - x[g] - (nl - g) ));
        
        int ret = 0;
        if(nr - nl > 1) {
            int m = nl + (nr - nl)/2;
            
            if(nr > m) ret = ql(n->r, m, nr, gl, gr, g);
            if(nl < m and g < m) ret = sum(ret, ql(n->l, nl, m, gl, gr, g));
        }
        
        return ret;
    }
    
    int qr(int gl, int gr, int g) {
        return qr(h, 0, s, gl, gr, g);
    }
    int qr(NODE * n, int nl, int nr, int gl, int gr, int g) {
        if(gl >= gr or nl >= gr or gl >= nr) return 0;
        
        assert(g >= nl);
        
        if(g >= nr and gl <= nl and gr >= nr) return sum(n->wr, prod(n->ws, x[g] - x[nr - 1] - (g - nr + 1) ));
        
        int ret = 0;
        if(nr - nl > 1) {
            int m = nl + (nr - nl)/2;
            
            if(nl < m) ret = qr(n->l, nl, m, gl, gr, g);
            if(nr > m and g >= m) ret = sum(ret, qr(n->r, m, nr, gl, gr, g));
        }
        
        return ret;
    }
    
} st;


struct BIT {
    ll arr[MAXN];
    int s, l2s;
    BIT() {
        s = 0;
    }
    BIT(int v) {
        s = v;
        for(l2s = 1;l2s <= s; l2s <<= 1);
        for(int i = 1;i <= s;i++) arr[i] = 0;
        for(int i = 0;i < s;i++) upd(i, 2*w[i]);
    }
    void upd(int id, int nw) {
        for(int i = id + 1;i <= s;i += (i&(-i))) arr[i] += nw - w[id];
    }
    ll qry(int id) {
        ll ret = 0;
        for(int i = id + 1;i > 0;i -= (i&(-i))) ret += arr[i];
        return ret;
    }
    int srh(ll goal) {
        int id = 0;
        ll cur = 0;
        for(int i = l2s;i > 0;i >>= 1) {
            if(id + i > s) continue;
            if(cur + arr[id + i] < goal) {
                id += i;
                cur += arr[id];
            }
        }
        return id;
    }
} psm;


int main() {
    
    scanf("%d%d", &N, &Q);
    
    for(int i = 0;i < N;i++) scanf("%d", x + i);
    for(int i = 0;i < N;i++) scanf("%d", w + i);
    
    st = ST(N);
    psm = BIT(N);
    
    int a, b;
    for(int i = 0;i < Q;i++) {
        scanf("%d%d", &a, &b);
        
        if(a < 0)
        {
            
            a = -a - 1;
            st.upd(a, b);
            psm.upd(a, b);
            
            w[a] = b;
            
        }
        else
        {
            
            a--;
            ll aw = psm.qry(a - 1);
            ll bw = psm.qry(b - 1);
            
            ll md = aw + (bw - aw + 1)/2;
            int m = psm.srh(md);
            
            //printf("%d %lld\n", m, md);
            
            int ans = sum(st.ql(m, b, m), st.qr(a, m, m));
            
            //printf("%d + %d = ", st.ql(m, b, m), st.qr(a, m, m));
            
            printf("%d\n", ans);
        }
    }
    
    return 0;
}