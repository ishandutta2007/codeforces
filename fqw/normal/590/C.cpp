// 8:17
// 8:22 - 8:33 - wa 4
#include <cassert>
#include <queue>
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

const int N=1010;
const int dx[4]={0, 1, 0, -1};
const int dy[4]={1, 0, -1, 0};

char g[N][N];
int dis[3][N][N], infi;
int n, m;

void pre(int cur) {
    char target=char('1'+cur);
    fillchar(dis[cur], 50); infi=dis[cur][0][0];
    queue<PII> que;
    static bool inside[N][N]; fillchar(inside, false);
    rep(i, 1, n) rep(j, 1, m) if(g[i][j]==target) {
        inside[i][j]=true;
        dis[cur][i][j]=0;
        que.push(mp(i, j));
    }
    while(!que.empty()) {
        int x=que.front().fi, y=que.front().se; que.pop();
        inside[x][y]=false;
        repn(k, 4) {
            int x0=x+dx[k], y0=y+dy[k];
            if(x0<1 || x0>n || y0<1 || y0>m || g[x0][y0]=='#') continue;
            int d=dis[cur][x][y];
            if(g[x0][y0]=='.') ++d;
            if(setmin(dis[cur][x0][y0], d)) {
                if(!inside[x0][y0]) {
                    inside[x0][y0]=true;
                    que.push(mp(x0, y0));
                }
            }
        }
    }
}

int main() {
    scanf("%d%d", &n,&m);
    rep(i, 1, n) scanf("%s", g[i]+1);
    repn(i, 3) pre(i);

    int ans=infi;
    rep(i, 1, n) rep(j, 1, m) if(g[i][j]!='#') {
        int tmp=min(infi+10, dis[0][i][j]+dis[1][i][j])+dis[2][i][j];
        if(g[i][j]=='.') tmp-=2;
        setmin(ans, tmp);
    }
    if(ans>=infi) ans=-1;
    printf("%d\n", ans);

    return 0;
}