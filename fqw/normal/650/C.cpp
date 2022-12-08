#include <cassert>
#include <algorithm>
#include <queue>
#include <functional>
#include <set>
#include <map>
#include <cstring>
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

int main() {
    int n, m;
    scanf("%d%d", &n,&m);
    VI a(n*m); repn(k, n*m) scanf("%d", &a[k]);

    vector<pair<int,PII>> ps;
    repn(i, n) repn(j, m) ps.pb(mp(a[i*m+j], mp(i,j)));
    sort(all(ps));

    vector<VI> es(n*m);
    VI f(n*m, -1);
    function<int(int)> get=[&](int x) { return f[x]<0?x:(f[x]=get(f[x])); };
    auto merge=[&](int i, int j) { i=get(i); j=get(j); if(i!=j) f[i]=j; };
    VI mr(n, -1), mc(m, -1);
    for(const auto& p: ps) {
        int i=p.se.fi, j=p.se.se, k=i*m+j;
        if(mr[i]>=0) {
            if(a[k]==a[mr[i]]) merge(k, mr[i]);
            else es[k].pb(mr[i]);
        }
        if(mc[j]>=0) {
            if(a[k]==a[mc[j]]) merge(k, mc[j]);
            else es[k].pb(mc[j]);
        }
        mr[i]=k, mc[j]=k;
    }
    vector<VI> sons(n*m);
    repn(k, n*m) sons[get(k)].pb(k);

    VI ans(n*m);
    for(const auto& p: ps) {
        int cur=p.se.fi*m+p.se.se, r=1;
        if(get(cur)==cur) {
            for(int k: sons[cur]) for(int d: es[k]) setmax(r, ans[d]+1);
            for(int k: sons[cur]) ans[k]=r;
        }
    }
    repn(i, n) {
        repn(j, m) printf("%d ", ans[i*m+j]);
        printf("\n");
    }

    return 0;
}