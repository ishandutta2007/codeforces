// 18:45
// 18:49 - 18:51 - wa
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
    static int u[100010], v[100010], t[100010];
    fillchar(u, 0);
    fillchar(v, 0);
    fillchar(t, 0);
    rep(i, 1, n) {
        int x; scanf("%d", &x);
        for(int y=x, c=0; y>0; y/=2, ++c) {
            for(int z=y, d=c; z<=100000; z*=2, ++d)
                if(t[z]<i) {
                    t[z]=i;
                    ++u[z], v[z]+=d;
                }
        }
    }
    int ans=1<<30;
    rep(i, 1, 100000) if(u[i]==n) setmin(ans, v[i]);
    printf("%d\n", ans);
    return 0;
}