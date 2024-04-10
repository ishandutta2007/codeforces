// 19:27
// 19:31 - 
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

const LL MOD=(int)1e9+7;
const int N=4010;

LL f[N], g[N];
LL c[N][N];

int main() {
    repn(i, N) c[i][0]=c[i][i]=1;
    repn(i, N) rep(j, 1, i-1) c[i][j]=(c[i-1][j-1]+c[i-1][j])%MOD;

    int n; scanf("%d", &n);
    fillchar(f, 0);
    fillchar(g, 0);
    f[0]=1, g[0]=1;
    rep(i, 1, n) {
        rep(k, 1, i) (f[i]+=f[i-k]*c[i-1][k-1])%=MOD;
        (f[i]+=f[i-1])%=MOD;
        rep(k, 2, i) (g[i]+=g[i-k]*c[i-1][k-1])%=MOD;
        (g[i]+=g[i-1])%=MOD;
    }
    LL ans=(f[n]-g[n]+MOD*2)%MOD;
    printf("%d\n", (int)ans);


    return 0;
}