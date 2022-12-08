// 11:46
// 11:50 - 
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

const int MAXN=1010;

int f[MAXN][MAXN];
int t[MAXN], q[MAXN];
int n, T;

int main() {
    scanf("%d%d", &n,&T);
    rep(i, 1, n) scanf("%d%d", &t[i],&q[i]);
    rep(i, 1, n) rep(j, i+1, n)
        if(t[i]<t[j]) {
            swap(t[i], t[j]);
            swap(q[i], q[j]);
        }
    t[0]=T;
    fillchar(f, 0xff);
    f[0][1]=0;
    rep(i, 0, n-1) rep(r, 0, n) {
        if(f[i][r]<0) continue;
        int r2=r;
        repn(k, t[i]-t[i+1]) r2=min(r2*2, n);
        setmax(f[i+1][r2], f[i][r]);
        if(r2>0) setmax(f[i+1][r2-1], f[i][r]+q[i+1]);
    }
    int ans=0;
    rep(r, 0, n) setmax(ans, f[n][r]);
    printf("%d\n", ans);

    return 0;
}