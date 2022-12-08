#include <algorithm>
#include <cassert>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
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
    auto ok=[](int a[]) {
        VI b; repn(i, 4) b.pb(a[i]);
        sort(all(b));
        if(b[0]+b[1]+b[2]+b[3]!=4*(b[3]-b[0])) return false;
        if(b[0]+b[1]+b[2]+b[3]!=2*(b[1]+b[2])) return false;
        return true;
    };
    int n; scanf("%d", &n);
    int a[4]; repn(i, n) scanf("%d", &a[i]);
    if(n==0) { printf("YES\n1\n1\n3\n3\n"); return 0; }
    if(n==1) { printf("YES\n%d\n%d\n%d\n", a[0],a[0]*3,a[0]*3); return 0; }
    if(n==2) {
        rep(i, 1, 2000) rep(j, 1, 2000) {
            a[2]=i, a[3]=j;
            if(ok(a)) { printf("YES\n"); printf("%d\n%d\n", a[2], a[3]); return 0; }
        }
        printf("NO\n");
        return 0;
    }
    if(n==3) {
        rep(i, 1, 2000) {
            a[3]=i;
            if(ok(a)) { printf("YES\n"); printf("%d\n", a[3]); return 0; }
        }
        printf("NO\n");
        return 0;
    }
    if(ok(a)) printf("YES\n"); else printf("NO\n");
    return 0;
}