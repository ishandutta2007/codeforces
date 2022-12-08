// 21:52
// 21:57 - 22:08
#include <cassert>
#include <algorithm>
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
typedef vector<PLL> VPL;
typedef vector<string> VS;
template<class T> bool setmax(T &_a, T _b) { if(_b>_a) { _a=_b; return true; } return false; }
template<class T> bool setmin(T &_a, T _b) { if(_b<_a) { _a=_b; return true; } return false; }
template<class T> T gcd(T _a, T _b) { return _b==0?_a:gcd(_b,_a%_b); }

LL cl[100010], cr[100010];
int cans[100010];
int q, h;

LL found, sample;

void take(LL l, LL r) {
    if(l<=r) {
        found+=r-l+1;
        sample=l;
    }
}

void solve() {
    const char *NO="Game cheated!";
    const char *UNKNOWN="Data not sufficient!";
    LL l=1, r=1;
    rep(i, 2, h) l=l*2, r=r*2+1;
    rep(i, 1, q) if(cans[i]==1)
        setmax(l, cl[i]), setmin(r, cr[i]);
    if(l>r) { printf(NO); return; }

    found=0;
    VPL lst;
    rep(i, 1, q) if(cans[i]==0)
        lst.pb(mp(cl[i], cr[i]));
    sort(all(lst));
    LL la=0;
    for(PLL p: lst) {
        take(max(la+1, l), min(p.fi-1, r));
        setmax(la, p.se);
    }
    take(max(la+1, l), r);
    if(found==1) printf("%lld\n", sample);
    else if(found>1) printf(UNKNOWN);
    else printf(NO);
}

int main() {
    scanf("%d%d", &h,&q);
    rep(k, 1, q) {
        int i, ans; LL l, r;
        scanf("%d%lld%lld%d", &i,&l,&r,&ans);
        while(i<h) {
            ++i;
            l=l*2, r=r*2+1;
        }
        cl[k]=l, cr[k]=r, cans[k]=ans;
    }
    solve();
    return 0;
}