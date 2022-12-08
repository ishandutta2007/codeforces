#include <algorithm>
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
    PII a[110];
    int n;
    scanf("%d", &n);
    rep(i, 1, n) scanf("%d%d", &a[i].fi,&a[i].se);
    sort(a+1, a+n+1);
    a[0]=mp(-(1<<30), 0);
    auto pos=[&a](int p, int d) { return a[p].fi+d*a[p].se; };

    static int f[110][110][2];
    fillchar(f, 0xff);
    f[0][0][0]=0;
    rep(i, 0, n-1) rep(p, 0, i) rep(d, 0, 1) {
        if(f[i][p][d]<0) continue;
        int wall=pos(p, d);

        int p2=i+1, d2=0;
        int hole=1<<30;
        rep(j, i+1, n) {
            if(a[j].fi>pos(p2, d2)) setmin(hole, pos(p2, d2));
            if(a[j].fi-a[j].se<=hole) {
                int p3=p2, d3=d2;
                if(a[j].fi>pos(p3, d3)) p3=j, d3=0;
                if(pos(p, d)>pos(p3, d3)) p3=p, d3=d;
                int le=min(a[i+1].fi, a[j].fi-a[j].se);
                int val=pos(p3, d3)-max(le, wall);
                setmax(f[j][p3][d3], f[i][p][d]+val);
            }
            if(a[j].fi+a[j].se>pos(p2, d2))
                p2=j, d2=1;
            if(a[j].fi<=hole) {
                int p3=p2, d3=d2;
                if(pos(p, d)>pos(p3, d3)) p3=p, d3=d;
                int val=pos(p3, d3)-max(a[i+1].fi, wall);
                setmax(f[j][p3][d3], f[i][p][d]+val);
            }
        }
    }

    int ans=0;
    rep(p, 0, n) rep(d, 0, 1) {
        setmax(ans, f[n][p][d]);
    }
    printf("%d\n", ans);

    return 0;
}