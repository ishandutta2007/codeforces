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

const LL MOD=LL(1e9)+7;

char a[100100]; int la;
char b[100010]; int lb;
int pre[100010];
bool matched[100010];
int x[100010];

LL f[100010], g[100010], h[100010];

int main() {
    scanf("%s%s", a+1, b+1);
    la=(int)strlen(a+1), lb=(int)strlen(b+1);
    pre[1]=0;
    for(int i=2, j=0; i<=lb; ++i) {
        while(j>0 && b[j+1]!=b[i]) j=pre[j];
        if(b[j+1]==b[i]) ++j;
        pre[i]=j;
    }
    fillchar(matched, false);
    for(int i=1, j=0; i<=la; ++i) {
        while(j>0 && b[j+1]!=a[i]) j=pre[j];
        if(b[j+1]==a[i]) ++j;
        if(j==lb) {
            matched[i]=true;
            j=pre[j];
        }
    }

    fillchar(x, 0);
    rep(i, 1, la) {
        x[i]=x[i-1]; if(matched[i]) x[i]=i-lb+1;
    }

    fillchar(f, 0); fillchar(g, 0); fillchar(h, 0);
    LL ans=0;
    rep(i, 1, la) {
        int j=x[i]; if(j>0) {
            f[i]=(h[j-1]+j)%MOD;
        }
        g[i]=(g[i-1]+f[i])%MOD;
        h[i]=(h[i-1]+g[i])%MOD;
        (ans+=f[i]) %=MOD;
    }
    printf("%d\n", (int)ans);

    return 0;
}