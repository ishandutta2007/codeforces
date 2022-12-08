#include <cassert>
#include <set>
#include <map>
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

const int N=1000010;

int a[N], n;

bool is_prime[N];
int canonical[N];
VI primes[N];

void cal_h() {
    rep(i, 1, n) {
        is_prime[i]=true;
        canonical[i]=1;
    }
    primes[1].pb(1);
    rep(i, 2, n) if(is_prime[i]) {
        for(int j=i; j<=n; j+=i) {
            if(j>i) is_prime[j]=false;
            canonical[j]*=i;
            primes[j].pb(i);
        }
    }
}

int size(int x) {
    return x==1 ? 1 : n/x;
}

int solve() {
    const LL MOD=LL(1e9)+7;
    VL fac(n+1);
    fac[0]=1;
    rep(i, 1, n) fac[i]=fac[i-1]*i%MOD;

    VI pmap(n+1), inv_pmap(n+1);
    rep(i, 1, n) if(a[i]>0) {
        const auto& p1=primes[i], p2=primes[a[i]];
        if(sz(p1)!=sz(p2)) return 0;
        repn(j, sz(p1)) {
            //printf("%d->%d\n",p1[j],p2[j]);
            //if(j+1<sz(p1)) if(p1[j]!=p2[j]) return 0;
            if(size(p1[j])!=size(p2[j])) return 0;
            if(pmap[p1[j]]>0 && pmap[p1[j]]!=p2[j]) return 0;
            if(inv_pmap[p2[j]]>0 && inv_pmap[p2[j]]!=p1[j]) return 0;
            pmap[p1[j]]=p2[j], inv_pmap[p2[j]]=p1[j];
        }
    }
    LL ans=1;
    VI n1(n+1), n2(n+1);
    rep(i, 1, n) if(is_prime[i] && pmap[i]==0) ++n1[size(i)];
    rep(i, 1, n) if(a[i]==0) ++n2[canonical[i]];
    rep(i, 1, n) {
        (ans*=fac[n1[i]])%=MOD;
        (ans*=fac[n2[i]])%=MOD;
    }
    return int(ans);
}

int main() {
    scanf("%d", &n);
    rep(i, 1, n) scanf("%d", &a[i]);
    cal_h();
    int ans=solve();
    printf("%d\n", ans);
    return 0;
}