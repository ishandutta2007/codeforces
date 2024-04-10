// retry
// 16:01 - 16:14 - tle
#include <cassert>
#include <map>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

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
#ifdef DEBUG
    #define _debug(args...) { fprintf(stderr, args); fflush(stderr); }
#else
    #define _debug(args...) {}
#endif
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

LL ok[1000010];
bool prime[1000010];

LL mul(LL a, LL b) { if(a>LL(1e15)/b) return LL(1e15); else return a*b; }

LL is_ok(LL x) {
    if(x<=1) return false;
    if(x<=1000000) return ok[x];
    LL y=2;
    while(y*y<=x && x%y!=0) ++y;
    if(x%y==0) {
        while(x%y==0) x/=y;
        return x==1?y:-1;
    }
    return x;
}

LL factors[99999]; int num;

int main() {
    fillchar(prime, true);
    fillchar(ok, 0xff);
    prime[1]=false;
    rep(i, 2, 1000000) if(prime[i]) {
        for(int t=1; t<=1000000; t=(int)min(LL(t)*LL(i), 1LL<<30))
            ok[t]=i;
        for(int j=i*2; j<=1000000; j+=i)
            prime[j]=false;
    }

    LL n; cin>>n;
    num=0;
    for(LL x=1; x*x<=n; ++x)
        if(n%x==0) {
            factors[++num]=x;
            if(x*x<n) factors[++num]=n/x;
        }
    sort(factors+1, factors+num+1);

    map<LL, VI> co;
    rep(i, 2, num) {
        LL y=is_ok(factors[i]-1);
        if(y>0) co[y].pb(i);
    }
    static LL f[99999], g[99999];
    fillchar(f, 0);
    f[1]=1;
    for(auto &p: co) {
        memmove(g, f, sizeof(f));
        for(int k: p.se) {
            int j=1;
            rep(i, 1, num) {
                while(j<=num && mul(factors[i],factors[k])>factors[j]) ++j;
                if(j>num) break;
                if(factors[i]*factors[k]==factors[j])
                    g[j]+=f[i];
            }
        }
        memmove(f, g, sizeof(f));
    }
    cout<<f[num]<<endl;

    return 0;
}