// 10:33
#include <cassert>
#include <functional>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define sz(a) static_cast<int>(a.size())
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

const int N=550;
const int dx[5]={-1, 0, 1, 0, 0};
const int dy[5]={0, 1, 0, -1, 0};

char grids[N][N];
int belong[N][N], bsize[N*N];
int blocks[N][N];
int n, k, num;

int count_blocks(int x1, int y1, int x2, int y2) {
    return blocks[x2][y2]-blocks[x1-1][y2]-blocks[x2][y1-1]+blocks[x1-1][y1-1];
}

void init() {
    scanf("%d%d", &n,&k);
    fillchar(grids, 'X');
    rep(i, 1, n) {
        static char buf[N]; scanf("%s", buf+1);
        rep(j, 1, n) grids[i][j]=buf[j];
    }

    fillchar(blocks, 0);
    rep(i, 1, n) rep(j, 1, n) {
        blocks[i][j]=blocks[i-1][j]+blocks[i][j-1]-blocks[i-1][j-1];
        if(grids[i][j]=='X') blocks[i][j]++;
    }

    fillchar(belong, 0); num=0;
    function<void(int, int, int)> dfs=[&](int x, int y, int cur) {
        belong[x][y]=cur; ++bsize[cur];
        repn(i, 4) {
            int x0=x+dx[i], y0=y+dy[i];
            if(grids[x0][y0]=='.' && belong[x0][y0]==0)
                dfs(x0, y0, cur);
        }
    };
    rep(x, 1, n) rep(y, 1, n)
        if(grids[x][y]=='.' && belong[x][y]==0) {
            ++num; bsize[num]=0;
            dfs(x, y, num);
        }
}

int refcnt[N*N], tot;

void activate(int x, int y, int coef) {
    repn(i, 5) {
        int x0=x+dx[i], y0=y+dy[i];
        int bid=belong[x0][y0];
        if(bid>0) {
            int old=refcnt[bid];
            refcnt[bid]+=coef;
            if(old==0 && refcnt[bid]>0) tot+=bsize[bid];
            if(old>0 && refcnt[bid]==0) tot-=bsize[bid];
        }
    }
}

void solve() {
    int ans=0;
    //printf("* %d\n", count_blocks(2, 2, 4, 4));
    rep(x1, 1, n-k+1) {
        const int x2=x1+k-1;
        int y1=1, y2=k;
        fillchar(refcnt, 0); tot=0;
        rep(i, x1, x2) rep(j, y1, y2) activate(i, j, 1);
        while(1) {
            setmax(ans, tot+count_blocks(x1, y1, x2, y2));
            if(y2==n) break;
            rep(i, x1, x2) activate(i, y1, -1);
            ++y1, ++y2;
            rep(i, x1, x2) activate(i, y2, 1);
        }
    }
    printf("%d\n", ans);
}

int main() {
    init();
    solve();
    return 0;
}