#include <iostream>
#include <cstdio>

#include <cassert>
#include <iomanip>
#include <cmath>
#include <set>
#include <utility>
#include <vector>

using namespace std;

typedef double ld;
#define tld(x) static_cast<ld>(x)
typedef long long ll;
#define tll(x) static_cast<ll>(x)
typedef pair<ld, ld> pff;
#define xvl first
#define yvl second
#define mp make_pair

const int MAXN = 1e5 + 100;
const int MAXT = 1e10 + 1000;
int N;
ll T;
const ld EPS = 1e-12;
const ld CHTLB = -1;
const ld CHTUB = 1e20;
ld V, t;
typedef vector<ld> vld;
typedef vector<vld> vvld;

ld pow(ld b, ll p) {
    assert(p >= 0);
    //if(b == 0) return 0;
    if(p == 0) return 1;
    if(p == 1) return b;
    ld r = tld(1);
    for(;p;p>>=1, b*=b) if(p&1) r*=b;
    return r;
}

ll rlog2(ll v) {
    ll ret = 1;
    while(v>>=1)ret++;
    return ret;
}

bool equ(const ld& a, const ld& b) {
    return abs(a - b) < EPS;
}

bool Q;
ld r[MAXN];

struct Line {
public:
    Line() {
        m = b = -1;
        id = -1;
    }
    Line(const ld& a, const ld& c) {
        m = a;
        b = c;
        id = -1;
    }
    Line(const ll& s) {
        m = b = -1;
        id = s;
    }
    Line(const ld& a, const ld& c, const int& s) {
        m = a, b = c, id = s;
    }
    ld m;       //slope
    ld b;       //y-int
    int id;      //highest optimal x position
    bool operator < (const Line& o) const {
        if(!Q) return o.m > m;
        else return r[o.id] > r[id];
    }
    ld operator() (const ld& x) const {return m * x + b;}
    bool operator() (const ld& x, const ld& y) const { return equ((*this)(x), y);}
    pff operator * (const Line& o)  const {
        assert(!equ(m, o.m));
        ld x = (o.b - b)/(m - o.m);
        ld y = (o.b*m - b*o.m)/(m - o.m);
        //assert(o(x, y) and (*this)(x, y));
        return mp(x, y);
    }
    bool keep(const Line& l, const Line& r) const {
        //assert(l.m <= m and m <= r.m);
        return (l**this).xvl < (*this*r).xvl;
    }
};
typedef multiset<Line> msl;
struct CHT {
public:
    msl lines;
    CHT() {
        Q = false;
    }
    void pout() {
        for(msl::iterator it = lines.begin();it != lines.end();it++) {
            cerr << it->m << "x + " << it->b << "(" << it->id << ") up to " << r[it->id] << "\n";
        }
    }
    bool insert(const Line& l) {
        if(lines.empty()) {
            r[l.id] = CHTUB;
            lines.insert(l);
            return true;
        }
        
        msl::iterator c = lines.lower_bound(l);
        if(c != lines.end()) {
            if(equ(c->m, l.m)) {
                if(l.b > c->b) lines.erase(c);
                else return false;
            }
        }
        c = lines.insert(l);
        
        msl::iterator p[2], n[2];
        
        //check whether to remove
        n[0] = c;
        p[0] = c;
        if(c != lines.begin() and ++n[0] != lines.end()) {
            --p[0];
            if(!c->keep(*p[0], *n[0])) {
                lines.erase(c);
                return false;
            }
        }
        
        if(c == lines.begin()) {
        } else {
            p[0] = c, p[1] = --p[0];
            
            while(p[0] != lines.begin()) {
                p[1]--;
                
                if(p[0]->keep(*p[1], *c)) {
                    break;
                } else {
                    lines.erase(p[0]);
                    p[0] = p[1];
                }
            }
            r[p[0]->id] = ((*p[0]) * (*c)).xvl;
        }
        
        
        n[0] = c, n[1] = ++n[0];
        if(n[0] == lines.end()) {
            r[c->id] = CHTUB;
        } else {
            while(++n[1] != lines.end()) {
                if(n[0]->keep(*c, *n[1])) {
                    break;
                } else {
                    lines.erase(n[0]);
                    n[0] = n[1];
                }
            }
            r[c->id] = ((*n[0]) * (*c)).xvl;
        }
        return true;
    }
    ld operator () (const ld& x) const {
        assert(CHTLB < x and x < CHTUB);
        Q = true;
        msl::iterator c = lines.lower_bound(x);
        Q = false;
        
        assert(c != lines.end());
        
        return (*c)(x);
    }
} hull;

struct mat {
public:
    vvld m;
private:
    int L, W;
    void fix() {
        L = m.size();
        W = m[0].size();
    }
public:
    
    void pout() {
        fix();
        for(int l = 0;l < L;l++) {
            for(int w = 0;w < W;w++) {
                cerr << m[l][w] << " ";
            }
            cerr << "\n";
        }
        cerr << "\n";
    }
    
    mat(const int& l = 1, const int& w = 1) {
        L = l, W = w;
        vld r(W, 0);
        m = vvld(L, r);
        if(l == w) {
            for(int i = 0;i < l;i++) m[i][i] = 1;
        }
    }
    
    vld& operator [] (const int& r) {
        fix();
        assert(0 <= r and r < L);
        return m[r];
    }
    ld& operator () (const int& r, const int& c) {
        fix();
        assert(0 <= r and r < L);
        assert(0 <= c and c < W);
        return m[r][c];
    }
    
    mat operator * (mat& o) {
        fix();
        o.fix();
        
        assert(W == o.L);
        mat ret(L, o.W);
        
        for(int l = 0;l < L;l++) {
            for(int c = 0;c < o.W;c++) {
                ret[l][c] = 0;
                for(int i = 0;i < W;i++) {
                    ret[l][c] += m[l][i] * o.m[i][c];
                }
            }
        }
        
        return ret;
    }
};

int a[MAXN], b[MAXN];
ld p[MAXN];

ld dp;
ll ct;
mat st[500];
ll next(ld p, ld a, ld cut) {
    ll v = rlog2(T - ct);
    st[0].m = {
        {tld(1) - p, p * V, p * a},
        {0, 1, 1},
        {0, 0, 1}
    };
    for(int i = 1;i <= v;i++) {
        st[i] = st[i - 1] * st[i - 1];
    }
    
    mat cm(3, 3);
    mat dpm(3, 1);
    dpm.m = {{dp},{tld(ct)},{1}};
    ll dt = 0;
    for(ll i = v;i >= 0;i--) {
        if(ct + dt + (1LL << i) > T) continue;
        mat cmt = cm * st[i];
        if(V*(ct + dt + (1LL << i)) - (cmt*dpm)[0][0] > cut);
        else {
            cm = cmt;
            dt += (1LL << i);
            assert(equ(tld(dt), cm[1][2]));
        }
    }
    
    mat rt = cm * dpm;
    assert(equ(tld(ct + dt), rt[1][0]));
    
    if(dt + ct < T and V*(ct + dt) - rt[0][0] < cut){
        dt++;
        rt = st[0] * rt;
    }
    
    dp = rt[0][0];
    return dt + ct;
}

int main() {
    Q = false;
    cerr << setprecision(10);
    
    scanf("%d%lld", &N, &T);
    V = 0;
    for(int i = 0;i < N;i++) {
        scanf("%d%d%Lf", a + i, b + i, p + i);
        if((t = b[i] * p[i]) > V) V = t;
    }
    
    for(int i = 0;i < N;i++) {
        hull.insert(Line(p[i], p[i]*a[i], i));
    }
    
    ct = 0;
    dp = 0;
    for(auto path : hull.lines) {
        ct = next(p[path.id], a[path.id], r[path.id]);
        assert(ct <= T);
        if(ct == T) break;
    }
    
    printf("%.10Lg\n", dp);
    
    return 0;
}