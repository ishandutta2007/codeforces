// 21:28
// 21:33
#include <cassert>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
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

struct Edge { 
    int y, i; LL w; 
    Edge(int _y, int _i, LL _w) : y(_y), i(_i), w(_w) {}
};
typedef pair<LL, int> PLI;
const int MAXN=300010;
const int MAXE=300010;

vector<Edge> es[MAXN];
int n, m, start;

LL dis[MAXN], ew[MAXE];
int pre[MAXN]; bool vis[MAXN];

int main() {
    scanf("%d%d", &n,&m);
    rep(i, 1, n) es[i].clear();
    rep(i, 1, m) {
        int a, b, w; scanf("%d%d%d", &a,&b,&w);
        ew[i]=w;
        es[a].pb(Edge(b, i, w));
        es[b].pb(Edge(a, i, w));
    }
    scanf("%d", &start);

    fillchar(dis, 50); fillchar(vis, false);
    dis[start]=0, pre[start]=0;
    priority_queue<PLI, vector<PLI>, greater<PLI>> que;
    rep(i, 1, n) que.push(mp(dis[i], i));
    while(!que.empty()) {
        int x=que.top().se; que.pop();
        if(vis[x]) continue;
        vis[x]=true;
        for(Edge &e: es[x]) {
            int y=e.y;
            if(setmin(dis[y], dis[x]+e.w)) {
                que.push(mp(dis[y], y));
                pre[y]=e.i;
            }
            if(dis[x]+e.w==dis[y] && ew[e.i]<ew[pre[y]])
                pre[y]=e.i;
        }
    }

    LL sum=0;
    rep(i, 1, n) if(pre[i]>0) sum+=ew[pre[i]];
    printf("%lld\n", sum);
    rep(i, 1, n) if(pre[i]>0) printf("%d ", pre[i]); printf("\n");
    return 0;
}