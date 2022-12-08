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

const LL INF=1LL<<55;

LL ext_gcd(LL a, LL b, LL* x, LL* y) {
    if(b==0) { *x=1, *y=0; return a; }
    LL nx, ny; LL d=ext_gcd(b, a%b, &nx, &ny);
    *x=ny, *y=nx-(a/b)*ny;
    return d;
}

LL go(LL n, LL m, LL x, LL y) {
    LL i, j;
    const LL g=ext_gcd(n, -m, &i, &j);
    if((y-x)%g!=0) return INF;
    i*=(y-x)/g, j*=(y-x)/g;

    const LL di=m/abs(g), dj=n/abs(g);
    LL t;
    if(i<0) {
        t=-i/di+1; i+=di*t, j+=dj*t;
    }
    if(j<0) {
        t=-j/dj+1; i+=di*t, j+=dj*t;
    }
    t=min(i/di, j/dj); i-=di*t, j-=dj*t;
    return i*n+x;
}

int main() {
    int n, m, k; scanf("%d%d%d", &n,&m,&k);
    repn(i, k) {
        int x, y; scanf("%d%d", &x,&y);
        LL ans=INF;
        setmin(ans, go(n*2, m*2, x, y));
        setmin(ans, go(n*2, m*2, n*2-x, y));
        setmin(ans, go(n*2, m*2, x, m*2-y));
        setmin(ans, go(n*2, m*2, n*2-x, m*2-y));
        if(ans==INF) ans=-1;
        printf("%lld\n", ans);
    }
    return 0;
}