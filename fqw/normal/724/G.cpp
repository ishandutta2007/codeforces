#include <algorithm>
#include <set>
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
typedef pair<int,LL> PIL;
typedef pair<double,double> PDD;
typedef vector<LL> VL;
typedef vector<int> VI;
typedef vector<PII> VPI;
typedef vector<PIL> VPIL;
typedef vector<string> VS;
template<class T, class S> ostream& operator<<(ostream& os, const pair<T, S>& v) { return os<<"("<<v.first<<", "<<v.second<<")"; }
template<class T> ostream& operator<<(ostream& os, const vector<T>& v) { os<<"["; repn(i, sz(v)) { if(i) os<<", "; os<<v[i]; } return os<<"]"; }
template<class T> bool setmax(T &_a, T _b) { if(_b>_a) { _a=_b; return true; } return false; }
template<class T> bool setmin(T &_a, T _b) { if(_b<_a) { _a=_b; return true; } return false; }
template<class T> T gcd(T _a, T _b) { return _b==0?_a:gcd(_b,_a%_b); }

const int N=100000;
const LL MOD=LL(1e9)+7;

VPIL es[N];
int n;

VL simplify(VL a) {
    VL b;
    repn(i, 63) {
        int j=-1;
        repn(k, sz(a)) if(a[k]&(1LL<<i)) j=k;
        if(j<0) continue;
        b.pb(a[j]); a.erase(a.begin()+j);
        for(LL& x: a) if(x&(1LL<<i)) x^=b.back();
    }
    return b;
}

LL pow2(int b) {
    LL r=1;
    repn(i, b) r=r*2%MOD;
    return r;
}

int main() {
    int m; scanf("%d%d", &n,&m);
    repn(i, m) {
        int a, b; LL c;
        scanf("%d%d%lld", &a,&b,&c);
        --a, --b;
        es[a].pb(mp(b, c)), es[b].pb(mp(a, c));
    }

    VI vis(n, 0);
    VL dis(n, 0);
    LL ans=0;
    repn(start, n) if(vis[start]==0) {
        set<LL> circles;
        VL ds;
        const function<void(int, LL)> dfs=[&](int x, LL d) {
            dis[x]=d, ds.pb(d);
            vis[x]=-1;
            for(const auto& e: es[x]) {
                if(vis[e.fi]==0) {
                    dfs(e.fi, d^e.se);
                } else if(vis[e.fi]<0) {
                    circles.insert(dis[x]^dis[e.fi]^e.se);
                }
            }
            vis[x]=1;
        };
        dfs(start, 0);
        
        VL cs=simplify(VL(all(circles)));
        repn(i, 63) {
            LL d0=0, d1=0;
            for(LL d: ds) if(d&(1LL<<i)) d1++; else d0++;
            const LL c0=(d0*(d0-1)/2+d1*(d1-1)/2)%MOD;
            const LL c1=d0*d1%MOD;

            bool has1=false;
            for(LL c: cs) if(c&(1LL<<i)) has1=true;
            LL tmp=(has1 ? pow2(sz(cs)-1)*(c0+c1) : pow2(sz(cs))*c1) %MOD;
            LL coef=(1LL<<i)%MOD;
            (ans+=tmp*coef)%=MOD;
        }
    }
    printf("%lld\n", ans);
    return 0;
}