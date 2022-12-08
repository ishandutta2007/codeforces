// 14:45
// 14:49 - 
#include <cassert>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
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
    int n, k, p, x, y;
    int a[1100];
    scanf("%d%d%d%d%d", &n,&k,&p,&x,&y);
    int c1=0, c2=0;
    rep(i, 1, k) { scanf("%d", &a[i]); if(a[i]>=y) ++c2; else ++c1; }
    rep(i, k+1, n) if(c2<n/2+1) a[i]=y, ++c2; else a[i]=1, ++c1;

    bool ok=true;
    int sum=0; rep(i, 1, n) sum+=a[i];
    if(sum>x) ok=false;
    int b[1100]; rep(i, 1, n) b[i]=a[i]; sort(b+1, b+n+1); int med=b[n/2+1];
    if(med<y) ok=false;
    if(ok) { rep(i, k+1, n) printf("%d ", a[i]); printf("\n"); } else printf("-1\n");

    return 0;
}