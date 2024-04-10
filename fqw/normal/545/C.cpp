// 21:14
// 21:15 - 
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
    int n; scanf("%d", &n);
    int y1=-(1<<30), y2=y1;
    int g1=0, g2=0;
    rep(i, 1, n) {
        int x, h; scanf("%d%d", &x,&h);
        int f1=0, f2=0;
        setmax(f1, g1);
        if(y2<x) setmax(f1, g2);
        if(y1<x-h) setmax(f1, g1+1);
        if(y2<x-h) setmax(f1, g2+1);
        setmax(f2, g1+1);
        if(y2<x) setmax(f2, g2+1);
        g1=f1, g2=f2;
        y1=x, y2=x+h;
    }
    int ans=max(g1, g2);
    printf("%d\n", ans);
    return 0;
}