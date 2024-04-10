// 10:21
// 10:25 - 10:27 - 
#include <algorithm>
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

LL f[100010];
int la[100010];
int a[100010], n;

int main() {
    scanf("%d", &n);
    rep(i, 1, n) scanf("%d", &a[i]);
    sort(a+1, a+n+1);

    la[0]=0;
    rep(i, 1, n) {
        la[i]=la[i-1];
        if(i>1 && a[i]<=a[i-1]+1) la[i]=i-1;
    }

    f[0]=0;
    rep(i, 1, n) {
        f[i]=f[i-1];
        int j=la[i];
        int k=(j>0?la[j-1]:0);
        if(k>0) {
            setmax(f[i], f[k-1]+LL(a[j])*LL(a[k]));
        }
    }
    printf("%lld\n", f[n]);

    return 0;
}