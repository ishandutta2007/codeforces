// 9:04 - 
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

const int N=153;
const int MAXS=80*80;

int a[N], f[2][N][MAXS];
int n, k, s;

int main() {
    scanf("%d%d%d", &n,&k,&s);
    rep(i, 1, n) scanf("%d", &a[i]);
    setmin(s, MAXS-5);

    int o1=0, o2=1;
    fillchar(f, 50);
    f[o1][0][0]=0;
    rep(i, 0, n-1) {
        fillchar(f[o2], 50);
        rep(j, 0, i) rep(p, 0, s) {
            int val=f[o1][j][p];
            //printf("f[%d,%d,%d]=%d\n",i,
            if(p+(i-j)<=s) 
                setmin(f[o2][j+1][p+(i-j)], val+a[i+1]);
            setmin(f[o2][j][p], val);
        }
        swap(o1, o2);
    }
    int ans=1<<30;
    rep(p, 0, s) setmin(ans, f[o1][k][p]);
    printf("%d\n", ans);


    return 0;
}