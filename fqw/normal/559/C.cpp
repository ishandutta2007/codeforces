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

const int MAXL=200010;
const LL MOD=LL(1e9)+7;

LL fac[MAXL], inv_fac[MAXL];

void pre() {
    fac[0]=1;
    rep(i, 1, MAXL-1) fac[i]=fac[i-1]*i%MOD;
    repn(i, MAXL) {
        LL ans=1, x=fac[i], y=MOD-2;
        for(; y>0; y>>=1, x=x*x%MOD)
            if(y&1) ans=ans*x%MOD;
        inv_fac[i]=ans;
    }
}
LL binom(int n, int r) {
    LL ans=fac[n];
    ans=ans*inv_fac[r]%MOD;
    ans=ans*inv_fac[n-r]%MOD;
    return ans;
}

LL val[2020];
int xpos[2020], ypos[2020];
int n;

int main() {
    int xsize, ysize;
    scanf("%d%d%d", &xsize, &ysize, &n);
    rep(i, 1, n) scanf("%d%d", &xpos[i], &ypos[i]);
    ++n; xpos[n]=xsize, ypos[n]=ysize;
    rep(i, 1, n) rep(j, i+1, n)
        if(xpos[i]>xpos[j] || (xpos[i]==xpos[j] && ypos[i]>ypos[j])) {
            swap(xpos[i], xpos[j]);
            swap(ypos[i], ypos[j]);
        }

    pre();

    rep(i, 1, n) {
        val[i]=binom(xpos[i]-1+ypos[i]-1, xpos[i]-1);
        rep(j, 1, i-1)
            if(xpos[j]<=xpos[i] && ypos[j]<=ypos[i]) {
                int dx=xpos[i]-xpos[j];
                int dy=ypos[i]-ypos[j];
                val[i]=(val[i]-val[j]*binom(dx+dy, dy))%MOD;
            }
        val[i]=(val[i]%MOD+MOD)%MOD;
    }
    int ans=(int)val[n];
    printf("%d\n", ans);

    return 0;
}