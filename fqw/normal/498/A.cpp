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

const double EPS=1e-10;
double sgn(double x) { return x<-EPS ? -1 : x>EPS; }
struct Point {
    int x, y;
    void read() { scanf("%d%d", &x,&y); }
};
struct Line {
    int a, b, c;
    void read() { scanf("%d%d%d", &a,&b,&c); }
    int left(Point p) {
        return a*(LL)p.x+b*(LL)p.y+c>0 ? 1 : 0;
    }
};

int main() {
    Line lines[330];
    Point st, en;
    int n;

    st.read();
    en.read();
    scanf("%d", &n);
    rep(i, 1, n) lines[i].read();

    int ans=0;
    rep(i, 1, n) {
        int x=lines[i].left(st);
        int y=lines[i].left(en);
        if(x!=y) ++ans;
    }
    printf("%d\n", ans);

    return 0;
}