#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <limits>
#include <memory>
#include <queue>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

#define all(a) (a).begin(), (a).end()
#define sz(a) static_cast<int>((a).size())
#define fillchar(a, x) memset(a, x, sizeof(a))
#define rep(i, a, b) for(int i=int(a); i<=int(b); ++i)
#define irep(i, a, b) for(int i=int(a); i>=int(b); --i)
#define replr(i, a, b) rep(i, a, (b)-1)
#define reprl(i, a, b) irep(i, (b)-1, a)
#define repn(i, n) rep(i, 0, (n)-1)
#define irepn(i, n) irep(i, (n)-1, 0)
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
typedef vector<string> VS;
template<class T, class S> ostream& operator<<(ostream& os, const pair<T, S>& v) { return os<<"("<<v.first<<", "<<v.second<<")"; }
template<class T> ostream& operator<<(ostream& os, const vector<T>& v) { os<<"["; repn(i, sz(v)) { if(i) os<<", "; os<<v[i]; } return os<<"]"; }
template<class T> bool setmax(T &_a, T _b) { if(_b>_a) { _a=_b; return true; } return false; }
template<class T> bool setmin(T &_a, T _b) { if(_b<_a) { _a=_b; return true; } return false; }
template<class T> T gcd(T _a, T _b) { return _b==0?_a:gcd(_b,_a%_b); }

const LL MOD=LL(1e9)+7;
const int N=200020;

LL fac[N], ifac[N];

void init() {
    const auto pow=[&](LL a, LL b) {
        LL c=1;
        for(; b>0; b>>=1, a=a*a%MOD)
            if(b&1) c=c*a%MOD;
        return c;
    };
    fac[0]=1;
    rep(i, 1, N-1) fac[i]=fac[i-1]*i%MOD;
    ifac[N-1]=pow(fac[N-1], MOD-2);
    irep(i, N-1, 1) ifac[i-1]=ifac[i]*i%MOD;
}

LL paths(PII a, PII b) {
    int dx=b.fi-a.fi, dy=b.se-a.se;
    if(dx<0 || dy<0) return 0;
    return fac[dx+dy]*ifac[dx]%MOD*ifac[dy]%MOD;
}

int main() {
    init();

    int n, m, k, s; scanf("%d%d%d%d", &n,&m,&k,&s);
    VPI a(k); repn(i, k) scanf("%d%d", &a[i].fi,&a[i].se);
    sort(all(a));
    if(a.empty() || a[0]!=mp(1,1)) {
        a.insert(a.begin(), mp(1,1));
    } else {
        s-=s/2;
    }
    if(n>1 || m>1) {
        if(a.empty() || a.back()!=mp(n,m)) {
            a.pb(mp(n, m));
        } else {
            s-=s/2;
        }
    }
    k=sz(a);

    const int M=21;
    vector<VL> f(k, VL(M));
    f[0][0]=1;
    replr(i, 1, k) {
        LL sum=0;
        repn(c, M) {
            f[i][c]=paths(mp(1,1), a[i]);
            replr(j, 1, i) (f[i][c]-=f[j][c]*paths(a[j], a[i]))%=MOD;
            (f[i][c]-=sum)%=MOD;
            (f[i][c]+=MOD)%=MOD;
            (sum+=f[i][c])%=MOD;
        }
    }
    LL ans=0, rest=paths(mp(1,1), mp(n,m));
    repn(c, M) {
        (ans+=s*f[k-1][c])%=MOD;
        (rest-=f[k-1][c])%=MOD;
        s-=s/2;
    }
    (ans+=s*rest)%=MOD;
    (ans+=MOD)%=MOD;
    (ans*=(ifac[n+m-2]*fac[n-1]%MOD*fac[m-1]%MOD))%=MOD;
    printf("%lld\n", ans);
    return 0;
}