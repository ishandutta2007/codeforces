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

const int MAXN=110, MAXM=110;
const int MAXNum=3030;

int a[MAXN], xi[MAXM], xj[MAXM];
int n, m;

int vals[MAXNum], st[MAXN], en[MAXN];
int num;

VI es[MAXNum];
int lnk[MAXNum];
bool vis[MAXNum];

bool find(int x) {
    for(int y: es[x]) if(!vis[y]) {
        vis[y]=true;
        if(lnk[y]==0 || find(lnk[y])) {
            lnk[y]=x; return true;
        }
    }
    return false;
}

int main() {
    scanf("%d%d", &n,&m);
    rep(i, 1, n) scanf("%d", &a[i]);
    rep(j, 1, m) scanf("%d%d", &xi[j], &xj[j]);
    //n=100; rep(i, 1, n) a[i]=1<<30;
    //m=0; rep(i, 1, n/2) xi[++m]=i*2, xj[m]=i*2-1;

    num=0;
    rep(i, 1, n) {
        int x=a[i];
        st[i]=num+1;
        for(int y=2; y*y<=x; ++y)
            while(x%y==0) {
                vals[++num]=y;
                x/=y;
            }
        if(x>1) vals[++num]=x;
        en[i]=num;
    }

    rep(i, 1, num) es[i].clear();
    rep(k, 1, m) {
        int i=xi[k], j=xj[k];
        if(i%2!=1) swap(i, j);
        rep(x, st[i], en[i]) rep(y, st[j], en[j])
            if(vals[x]==vals[y])
                es[x].pb(y);
    }
    fillchar(lnk, 0);
    int ans=0;
    rep(i, 1, n) if(i%2==1) rep(x, st[i], en[i]) {
        fillchar(vis, false);
        if(find(x)) ++ans;
    }
    printf("%d\n", ans);

    return 0;
}