// 9:36
// 9:40 -
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

const int N=110;
const int M=1010;

int rk[N];
int n, m;
double f[2][N*M];

int main() {
    scanf("%d%d", &n,&m);
    rep(i, 1, n) scanf("%d", &rk[i]); // in [1,m]
    if(m==1) { printf("1\n"); return 0; }

    fillchar(f, 0);
    int o1=0, o2=1;
    f[o1][0]=1;
    rep(i, 1, n) {
        fillchar(f[o2], 0);
        rep(s, 0, (i-1)*m) {
            double v=f[o1][s]/(m-1);
            int l=s+1, r=s+m, e=s+rk[i];
            //printf("i=%d s=%d l=%d r=%d e=%d f=%.4lf v=%.3lf\n",i,s,l,r,e,f[o1][s],v);
            f[o2][l]+=v;
            f[o2][e]-=v;
            f[o2][e+1]+=v;
            f[o2][r+1]-=v;
        }
        rep(s, 1, i*m+1)
            f[o2][s]+=f[o2][s-1];
        //rep(s, 0, i*m) printf("f[%d,%d]=%.6lf\n", i,s,f[o2][s]); printf("\n");
        swap(o1, o2);
    }
    int score=0; rep(i, 1, n) score+=rk[i];
    double ans=0;
    rep(s, 0, score-1) ans+=f[o1][s];
    ans=ans*(m-1)+1;
    printf("%.15lf\n", ans);

    return 0;
}