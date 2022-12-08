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
    int n, T; scanf("%d%d", &n,&T);
    double a[5050], b[5050], c[5050];
    fillchar(a, 0);
    a[0]=1;
    double ans=0;
    repn(i, n) {
        int p, t; scanf("%d%d", &p,&t);
        if(p==0) {
            fillchar(b, 0);
            rep(j, 0, T-t) b[j+t]+=a[j];
            memcpy(a, b, sizeof(a));
        }
        else if(p==100) {
            fillchar(b, 0);
            rep(j, 0, T-1) b[j+1]+=a[j];
            memcpy(a, b, sizeof(a));
        }
        else {
            double prob=p/100., r=1-prob;
            double res_prob=1.;
            repn(j, t) res_prob*=r;

            fillchar(b, 0); fillchar(c, 0);
            rep(j, 0, T-1) b[j+1]+=a[j];
            rep(j, 0, T-t-1) b[j+t+1]-=res_prob*a[j];
            rep(j, 0, T-t) c[j+t]+=res_prob*a[j];
            rep(j, 1, T) b[j]+=b[j-1]*r;
            rep(j, 0, T) c[j]+=b[j]*prob;
            memcpy(a, c, sizeof(a));
        }
        rep(j, 0, T) ans+=a[j];
    }
    printf("%.9lf\n", ans);
    return 0;
}