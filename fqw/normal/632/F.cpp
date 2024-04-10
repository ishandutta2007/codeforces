#include <cassert>
#include <algorithm>
#include <map>
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

const int N=2510;

int f[N];
void init() { fillchar(f, 0); }
int find(int x) { return f[x]==0 ? x : f[x]=find(f[x]); }
void merge(int x, int y) { x=find(x); y=find(y); if(x!=y) f[x]=y; }

pair<int, PII> es[N*N];
int a[N][N];
int n, num;

bool solve() {
    scanf("%d", &n);
    rep(i, 1, n) rep(j, 1, n) scanf("%d", &a[i][j]);
    rep(i, 1, n) rep(j, 1, n) if(a[i][j]!=a[j][i]) return false;
    rep(i, 1, n) if(a[i][i]!=0) return false;

    num=0;
    rep(i, 1, n) rep(j, 1, i-1) {
        es[++num]=mp(a[i][j], mp(i, j));
    }
    sort(es+1, es+num+1);

    init();
    for(int i=1, j; i<=num; i=j+1) {
        for(j=i; j<num && es[j+1].fi==es[j].fi; ++j);
        rep(k, i, j) if(find(es[k].se.fi)==find(es[k].se.se)) return false;
        rep(k, i, j) merge(es[k].se.fi, es[k].se.se);
    }
    return true;
}

int main() {
    bool good=solve();
    printf("%s\n", good?"MAGIC":"NOT MAGIC");
    return 0;
}