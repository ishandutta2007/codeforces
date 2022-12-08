// 18:42
// 18:43
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

int main() {
    int n; scanf("%d", &n);
    static int cnt[1000010], l[1000010], r[1000010]; fillchar(cnt, 0);
    rep(i, 1, n) {
        int x; scanf("%d", &x); cnt[x]++;
        if(cnt[x]==1) l[x]=i;
        r[x]=i;
    }
    int maxv=0;
    rep(i, 1, 1000000) setmax(maxv, cnt[i]);
    int ansl=1, ansr=n;
    rep(i, 1, 1000000) if(cnt[i]==maxv) {
        if(r[i]-l[i]<ansr-ansl) ansl=l[i], ansr=r[i];
    }
    printf("%d %d\n", ansl, ansr);
    return 0;
}