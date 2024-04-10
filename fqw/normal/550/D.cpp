// 14:03
// 14:07 - 14:15 - wa
//       - 14:27 - wa
// 14:55 - 
#include <cassert>
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

VPI es;
int n;

int make(int k) {
    int x=++n;
    rep(t, 1, (k-1)/2) {
        VI u; rep(i, 1, k+1) u.pb(++n);
        rep(i, 0, k) rep(j, i+1, k) if(i!=0 || j!=1) es.pb(mp(u[i], u[j]));
        es.pb(mp(u[0], x));
        es.pb(mp(u[1], x));
    }
    return x;
}

int main() {
    int k; scanf("%d", &k);
    if(k%2==0) printf("NO\n");
    else {
        n=0; es.clear();
        int x=make(k);
        int y=make(k);
        es.pb(mp(x, y));

        //int cnt[999]; fillchar(cnt, 0); for(PII p: es) cnt[p.fi]++, cnt[p.se]++;
        //rep(i, 1, n) printf("cnt[%d]=%d\n",i,cnt[i]);

        printf("YES\n%d %d\n", n,(int)es.size());
        for(PII p: es) printf("%d %d\n", p.fi,p.se);
    }
    return 0;
}