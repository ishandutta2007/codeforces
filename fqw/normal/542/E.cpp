// 21:22
// 21:31 - 21:40 - wa
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

bool vis[MAXN];
VI es[MAXN];
int n;

int que[MAXN], lst[MAXN], d[MAXN], ss, tt;
void bfs(int start) {
    ss=tt=1; que[1]=start;
    vis[start]=true; d[start]=0;
    while(ss<=tt) {
        int x=que[ss++];
        for(int y: es[x]) if(!vis[y]) {
            vis[y]=true; d[y]=d[x]+1;
            que[++tt]=y;
        }
    }
}

int solve_component(int start) {
    bfs(start);
    int len=tt; rep(i, 1, len) lst[i]=que[i];

    int ans=-1;
    rep(k, 1, len) {
        rep(i, 1, len) vis[lst[i]]=false;
        bfs(lst[k]);
        bool ok=true;
        rep(i, 1, tt) {
            int x=que[i];
            for(int y: es[x]) if(abs(d[x]-d[y])!=1)
                ok=false;
        }
        if(ok) setmax(ans, d[que[tt]]);
    }
    return ans;
}

int main() {
    int m; scanf("%d%d", &n,&m);
    rep(i, 1, n) es[i].clear();
    rep(i, 1, m) {
        int x, y; scanf("%d%d", &x,&y); 
        es[x].pb(y), es[y].pb(x);
    }
    fillchar(vis, false);
    int ans=0;
    rep(i, 1, n) if(!vis[i]) {
        int tmp=solve_component(i);
        if(tmp<0) { ans=-1; break; }
        ans+=tmp;
    }
    printf("%d\n", ans);
    return 0;
}