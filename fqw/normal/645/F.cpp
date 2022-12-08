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
const int V=1000010;
const int N=200010;

LL fac[N], inv_fac[N];
LL phi[V];

void pre() {
    auto pow=[&](LL a, LL b) {
        LL c=1;
        for(; b>0; b>>=1, a=a*a%MOD)
            if(b&1) c=c*a%MOD;
        return c;
    };
    fac[0]=1;
    rep(i, 1, N-1) fac[i]=fac[i-1]*i%MOD;
    inv_fac[0]=1;
    rep(i, 1, N-1) inv_fac[i]=inv_fac[i-1]*pow(i, MOD-2)%MOD;

    rep(i, 1, V-1) phi[i]=i;
    rep(i, 1, V-1)
        for(int j=i*2; j<V; j+=i)
            phi[j]-=phi[i];
}

LL binom(int n, int r) {
    if(r<0 || r>n) return 0;
    LL ans=fac[n];
    (ans*=inv_fac[r])%=MOD;
    (ans*=inv_fac[n-r])%=MOD;
    return ans;
}

int d[V]; LL ans;
int k;

void add(int x) {
    auto go=[&](int y) {
        LL cur=binom(d[y], k-1);
        (ans+=phi[y]*cur)%=MOD;
    };
    for(int y=1; y*y<=x; ++y)
        if(x%y==0) {
            go(y);
            if(y*y<x) go(x/y);
        }
    for(int y=1; y*y<=x; ++y)
        if(x%y==0) {
            d[y]++;
            if(y*y<x) d[x/y]++;
        }
}

int main() {
    pre();
    int n, q; scanf("%d%d%d", &n,&k,&q);
    fillchar(d, 0); ans=0;
    rep(i, 1, n) {
        int x; scanf("%d", &x);
        add(x);
    }
    rep(i, 1, q) {
        int x; scanf("%d", &x);
        add(x);
        printf("%d\n", (int)ans);
    }
    return 0;
}