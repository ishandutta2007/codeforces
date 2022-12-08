#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define sz(a) static_cast<int>(a.size())
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
typedef vector<string> VS;
template<class T> bool setmax(T &_a, T _b) { if(_b>_a) { _a=_b; return true; } return false; }
template<class T> bool setmin(T &_a, T _b) { if(_b<_a) { _a=_b; return true; } return false; }
template<class T> T gcd(T _a, T _b) { return _b==0?_a:gcd(_b,_a%_b); }

const LL MOD=LL(1e9)+7;

VL coeffs(int n) {
    auto pow=[&](LL a, LL b) {
        LL c=1;
        for(; b>0; b>>=1, (a*=a)%=MOD)
            if(b&1) (c*=a)%=MOD;
        return c;
    };
    VL inv(n);
    rep(i, 1, n-1) inv[i]=pow(i, MOD-2);
    
    VL binom(n);
    binom[0]=1;
    rep(i, 1, n-1) binom[i]=binom[i-1]*(n-i)%MOD*inv[i]%MOD;
    rep(i, 1, n-1) (binom[i]+=binom[i-1])%=MOD;

    VL ans(n);
    repn(i, n) {
        int l=i, r=n-i-1;
        if(l>0) ans[i]+=binom[l-1];
        if(r>0) ans[i]-=binom[r-1];
    }
    return ans;
}

int main() {
    int n; scanf("%d", &n);
    vector<VI> primes(300030);
    repn(i, n) {
        int x; scanf("%d", &x);
        for(int y=2; y*y<=x; ++y)
            if(x%y==0) {
                int cnt=0;
                while(x%y==0) ++cnt, x/=y;
                primes[y].pb(cnt);
            }
        if(x>1) {
            primes[x].pb(1);
        }
    }
    VL c=coeffs(n);
    //for(LL x: c) printf("%lld ", x); printf("\n");
    LL ans=0;
    repn(p, 300030) if(!primes[p].empty()) {
        sort(all(primes[p]));
        int padding=n-sz(primes[p]);
        repn(i, sz(primes[p])) {
            (ans+=primes[p][i]*c[padding+i])%=MOD;
        }
    }
    printf("%lld\n", ans);

    return 0;
}