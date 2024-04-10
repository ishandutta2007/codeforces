// 20:16 - 20:20 -
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

const int MAXN=2020;
const int dx[8]={0, 1, 0, -1, -1, -1, 1, 1};
const int dy[8]={1, 0, -1, 0, -1, 1, -1, 1};

char g[MAXN][MAXN];
int n, m;

bool vis[MAXN][MAXN];

bool need_vis(int x, int y) {
    if(g[x][y]=='.') return false;
    repn(ix, 2) repn(iy, 2) {
        int cnt=0;
        cnt+=(g[x-1+ix][y-1+iy]=='.');
        cnt+=(g[x+ix][y-1+iy]=='.');
        cnt+=(g[x-1+ix][y+iy]=='.');
        cnt+=(g[x+ix][y+iy]=='.');
        if(cnt==3) return true;
    }
    return false;
}

void bfs(int sx, int sy) {
    queue<PII> que;
    que.push(mp(sx, sy));
    vis[sx][sy]=true;
    while(!que.empty()) {
        int x=que.front().fi;
        int y=que.front().se;
        que.pop();
        repn(k, 4) {
            int x0=x+dx[k], y0=y+dy[k];
            if(!vis[x0][y0] && g[x0][y0]=='.') {
                vis[x0][y0]=true, que.push(mp(x0, y0));
            }
        }
        repn(k, 8) {
            int x0=x+dx[k], y0=y+dy[k];
            if(!vis[x0][y0] && (x0>=1 && x0<=n && y0>=1 && y0<=m) && need_vis(x0, y0)) {
                g[x0][y0]='.';
                vis[x0][y0]=true, que.push(mp(x0, y0));
            }
        }
    }
}

int main() {
    scanf("%d%d", &n,&m);
    fillchar(g, '#');
    rep(i, 1, n) scanf("%s", g[i]+1);

    fillchar(vis, false);
    rep(i, 1, n) rep(j, 1, m)
        if(g[i][j]=='.' && !vis[i][j]) {
            bfs(i, j);
        }
    rep(i, 1, n) printf("%s\n", g[i]+1);

    return 0;
}