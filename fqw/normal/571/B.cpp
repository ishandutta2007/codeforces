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

const int MAXN=300010;
const int MAXK=5050;

LL f[MAXK][MAXK];
int a[MAXN];
int n, k;

int main() {
    scanf("%d%d",&n,&k);
    rep(i, 1, n) scanf("%d", &a[i]);
    sort(a+1, a+n+1);
    
    int m=n/k, p=n%k;
    fillchar(f, 50);
    f[0][0]=0;
    rep(i, 0, k-1) rep(j, 0, p) {
        int x=i*m+j;
        setmin(f[i+1][j], (f[i][j]+a[x+m]-a[x+1]));
        setmin(f[i+1][j+1], (f[i][j]+a[x+m+1]-a[x+1]));
    }
    int ans=(int)f[k][p];
    printf("%d\n", ans);

    return 0;
}