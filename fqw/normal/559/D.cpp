// 13:51
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
    const int MAXN=100010;
    static double xpos[MAXN], ypos[MAXN];
    int n;
    scanf("%d", &n);
    rep(i, 1, n) scanf("%lf%lf", &xpos[i],&ypos[i]);

    double ans=1.;
    rep(d, max(2,n-100), n-1) {
        double coeff_a=pow(.5, n-d+1)-pow(.5, n);
        double coeff_b=1-pow(.5, n)*(1+n+double(n)*double(n-1)/2.);
        double coeff=coeff_a/coeff_b;
        rep(i, 1, n) {
            int j=(i+d-1)%n+1;
            double s=(xpos[j]*ypos[i]-ypos[j]*xpos[i])/2.;
            double b=abs(gcd(int(xpos[i]-xpos[j]), int(ypos[i]-ypos[j])));
            ans+=coeff*(s-b/2.);
        }
    }
    printf("%.15lf\n", ans);

    return 0;
}