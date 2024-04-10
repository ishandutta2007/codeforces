// 14:52
// 14:55 - 
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

const int MAXN=550;
const int dx[4]={0, 1, 0, -1};
const int dy[4]={1, 0, -1, 0};

bool intact[MAXN][MAXN];
bool vis[MAXN][MAXN];
int n, m, sx, sy, tx, ty;
queue<PII> que;

bool inside(int x, int y) { return x>=1 && x<=n && y>=1 && y<=m; }

void visit(int x, int y) {
    if(!inside(x, y)) return;
    if(vis[x][y]) return;
    vis[x][y]=true;
    if(intact[x][y]) {
        que.push(mp(x, y));
    }
}

bool solve() {
    if(intact[tx][ty]) {
        int cnt=0;
        repn(k, 4) {
            int x=tx+dx[k], y=ty+dy[k];
            if(inside(x, y) && intact[x][y]) ++cnt;
        }
        if(cnt==1 && abs(sx-tx)+abs(sy-ty)==1) return true;
        if(cnt<2) return false;
    }
    fillchar(vis, false);
    que=queue<PII>();
    repn(k, 4) {
        int x=sx+dx[k], y=sy+dy[k];
        visit(x, y);
    }
    while(!que.empty()) {
        int x=que.front().fi;
        int y=que.front().se;
    //printf("%d %d\n",x,y);
        que.pop();
        repn(k, 4) {
            int x0=x+dx[k], y0=y+dy[k];
            visit(x0, y0);
        }
    }
    return vis[tx][ty];
}

int main() {
    scanf("%d%d", &n,&m);
    rep(i, 1, n) {
        static char buf[MAXN]; scanf("%s", buf+1);
        rep(j, 1, m) intact[i][j]=(buf[j]=='.');
    }
    scanf("%d%d", &sx,&sy);
    scanf("%d%d", &tx,&ty);
    if(solve()) printf("YES\n");
    else printf("NO\n");
    return 0;
}