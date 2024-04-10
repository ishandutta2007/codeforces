#include <iostream>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
using namespace std;

#define _ (int)
#define all(a) a.begin(), a.end()
#define rep(i, a, b) for(int i=int(a); i<=int(b); ++i)
#define irep(i, a, b) for(int i=int(a); i>=int(b); --i)
#define repn(i, n) rep(i, 0, (n)-1)
#define irepn(i, n) irep(i, (n)-1, 0)
#define fillchar(a, x) memset(a, x, sizeof(a))
#define fi first
#define se second
#define pb push_back
#define mp make_pair
typedef long long LL;
typedef pair<LL,LL> PLL;
typedef pair<int,int> PII;
typedef pair<double,double> PDD;
typedef vector<LL> VL;
typedef vector<int> VI;
typedef vector<PII> VPI;
typedef vector<PLL> VPL;
typedef vector<string> VS;
template<class T> bool setmax(T &_a, T _b) { if(_b>_a) { _a=_b; return true; } return false; }
template<class T> bool setmin(T &_a, T _b) { if(_b<_a) { _a=_b; return true; } return false; }
template<class T> T gcd(T _a, T _b) { return _b==0?_a:gcd(_b,_a%_b); }

LL mod(LL a, LL m) {
    return (a%m+m)%m;
}

template<class T> T ext_gcd(T a, T b, T &x, T &y) {
    if(b==0) { x=1, y=0; return a; }
    LL nx, ny, d; d=ext_gcd(b, a%b, nx, ny);
    x=ny, y=nx-(a/b)*ny;
    return d;
}

LL inv(LL a, LL mod) {
    LL x, y;
    LL g=ext_gcd(a, mod, x, y);
    if(x<1) x+=mod;
    assert(g==1);
    //printf("inv %d %d = %d\n",a, mod, x);
    return x;
}

// returns x: x%a1=a2, x%b1=b2
// guarantee: gcd(a1, b1)=1
LL find(LL a1, LL a2, LL b1, LL b2) {
    LL m=a1*b1;
    LL r=(b1*inv(b1, a1)%m*a2+a1*inv(a1, b1)%m*b2)%m;
    //printf("find %d %d %d %d = %d\n",a1,a2,b1,b2,r);
    return r;
}

PLL merge(PLL a, PLL b) {
    // return c: c.fi=lcm(a.fi, b.fi), c.se%{a,b}.fi={a,b}.se
    if(a.fi==1) return b;
    if(b.fi==1) return a;
    PLL c;
    LL g=gcd(a.fi, b.fi);
    if(a.se%g!=b.se%g) return mp(-1, 0);
    LL p=find(a.fi/g, a.se/g, b.fi/g, b.se/g)*g+a.se%g;
    c=mp(a.fi/g*b.fi, p);
    //printf("(%d,%d) (%d,%d) (%d,%d)\n",a.fi,a.se,b.fi,b.se,c.fi,c.se);
    assert(p>=0 && p<c.fi && p%a.fi==a.se && p%b.fi==b.se);
    return c;
}

double go(VPL ps) {
    PLL cur{1, 0};
    for(const auto& p: ps) {
        PLL tmp=merge(cur, p);
        if(tmp.fi<0) return 0;
        cur=tmp;
    }
    return 1.0/double(cur.fi);
}

int main() {
    // why?
    int n; LL m[16], r[16];
    cin>>n;
    repn(i, n) cin>>m[i];
    repn(i, n) cin>>r[i];
    double ans=0;
    rep(s, 1, (1<<n)-1) {
        VPL ps;
        double sign=-1;
        repn(i, n) if(s&(1<<i)) {
            sign*=-1;
            ps.pb(mp(m[i], r[i]));
        }
        ans+=sign*go(ps);
    }
    printf("%.9lf\n", ans);
    return 0;

}