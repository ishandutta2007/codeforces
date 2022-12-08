#include <bits/stdc++.h>
using namespace std;

#define sz(a) int(a.size())
#define all(a) a.begin(), a.end()
#define repn(i, n) for(int i=0; i<int(n); ++i)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
typedef long long LL;
typedef vector<LL> VL;
typedef pair<VL, VL> PVL;

LL ext_gcd(LL a, LL b, LL* x, LL* y) {
    if(b==0) { *x=1, *y=0; return a; }
    LL g=ext_gcd(b, a%b, y, x);
    *y-=a/b**x; return g;
}

pair<VL, vector<PVL>> init() {
    int n; cin>>n;
    VL va(n), vb(n); repn(i, n) cin>>va[i]>>vb[i];
    VL ps; auto append_primes=[&ps](LL x) {
        for(LL y=2; y*y<=x; ++y)
            if(x%y==0) {
                ps.pb(y);
                while(x%y==0) x/=y;
            }
        if(x>1) ps.pb(x);
    };
    repn(i, n) {
        append_primes(va[i]);
        append_primes(vb[i]);
    }
    sort(all(ps)); ps.erase(unique(all(ps)), ps.end());
    auto to_vec=[&ps](LL x) {
        VL r; for(LL p: ps) {
            r.pb(0);
            while(x%p==0) ++r.back(), x/=p;
        }
        return r;
    };
    vector<PVL> es;
    repn(i, n) es.emplace_back(to_vec(va[i]), to_vec(vb[i]));
    return mp(ps, es);
}

void check(const VL& ps, const vector<PVL>& es, LL x0, int z0=0) {
    auto die=[](bool b=true) { if(b) { cout<<-1<<endl; exit(0); } };
    VL p; repn(i, sz(es[z0].fi)) {
        p.pb(es[z0].fi[i]+es[z0].se[i]*x0);
    }
    for(const auto& e: es) {
        LL div=-1;
        repn(i, sz(e.fi)) {
            LL d=p[i]-e.fi[i]; if(d<0) die();
            if(e.se[i]==0) {
                die(d!=0);
            } else {
                die(d%e.se[i]!=0); d/=e.se[i];
                die(div>=0 && d!=div); div=d;
            }
        }
    }
    const LL M=LL(1e9)+7;
    function<LL(LL,LL)> pow=[&pow,&M](LL a, LL b) {
        return b==0?1:(pow(a*a%M, b/2)*((b&1)?a:1)%M);
    };
    LL ans=1;
    repn(i, sz(ps)) ans=ans*pow(ps[i], p[i])%M;
    cout<<ans<<endl;
    exit(0);
}

struct Line {
    LL a, b, c;
    Line(LL a1, LL b1, LL a2, LL b2) : a(b1), b(-b2), c(a1-a2) {}
    friend bool intersect(const Line& u, const Line& v, LL* x, LL* y) {
        LL t=u.a*v.b-u.b*v.a;
        *x=u.b*v.c-u.c*v.b;
        *y=u.c*v.a-u.a*v.c;
        if(t==0) return false;
        *x/=t, *y/=t; return true;
    }
};

bool solve(LL a1, LL b1, LL a2, LL b2, LL* x, LL* dx) {
    if(b1==0 || b2==0) return false;
    LL i, j, g=ext_gcd(b1, -b2, &i, &j);
    LL di=b2/abs(g), dj=b1/abs(g);
    if((a2-a1)%g!=0) return false;
    LL t=(a2-a1)/g; i*=t, j*=t;
    auto go=[&i,&j,di,dj](LL k) { i+=di*k, j+=dj*k; };
    if(i<0) go((-i+di-1)/di);
    if(j<0) go((-j+dj-1)/dj);
    go(-min(i/di, j/dj));
    *x=i, *dx=di; return true;
}

int main() {
    VL ps; vector<PVL> es;
    tie(ps, es)=init();
    repn(i, sz(es)) if(es[i].se==VL(es[i].se.size(), 0)) check(ps, es, 0, i);
    int ind=0; while(ind<sz(es[0].se) && es[0].se[ind]==0) ++ind;

    for(const auto& e: es) {
        const auto& e0=es[0];
        Line l(e0.fi[ind], e0.se[ind], e.fi[ind], e.se[ind]);
        repn(i, sz(e0.fi)) {
            LL x, y;
            if(intersect(l, Line(e0.fi[i], e0.se[i], e.fi[i], e.se[i]), &x,&y))
                check(ps, es, x);
        }
    }
    LL u=0, v=1;
    for(const auto& e: es) {
        LL x, dx;
        if(solve(es[0].fi[ind], es[0].se[ind], e.fi[ind], e.se[ind], &x, &dx)) {
            LL k, dk;
            if(solve(u, v, x, dx, &k, &dk)) {
                u=u+v*k, v=v*dk;
            }
        }
    }
    check(ps, es, u);
    return 0;
}