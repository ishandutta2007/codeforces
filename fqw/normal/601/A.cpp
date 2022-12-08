// 8:30
// 8:40 - 
#include <queue>
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

const int N=440;

bool g[N][N];
int n;
bool vis1[N][N], vis2[N][N];

int solve() {
    fillchar(vis1, false);
    fillchar(vis2, false);
    vis1[1][1]=true;
    VPI v1; v1.pb(mp(1,1));
    for(int ans=1; !v1.empty(); ++ans) {
        VPI v2;
        for(PII cur: v1) {
            int i=cur.fi, j=cur.se;
            for(int k=1; k<=n; ++k) 
                if((g[i][k] || (i==n && k==n)) && !vis2[k][j]) {
                    vis2[k][j]=true;
                    v2.pb(mp(k, j));
                }
        }
        v1.clear();
        for(PII cur: v2) {
            int i=cur.fi, j=cur.se;
            for(int k=1; k<=n; ++k)
                if((!g[j][k] || (j==n && k==n)) && !vis1[i][k]) {
                    vis1[i][k]=true;
                    if(i==k) {
                        if(i==n) return ans;
                    } else {
                        v1.pb(mp(i, k));
                    }
                }
        }
    }
    return -1;
}

int main() {
    fillchar(g, false);
    int m; scanf("%d%d", &n,&m);
    repn(mi, m) {
        int x, y; scanf("%d%d", &x,&y);
        g[x][y]=g[y][x]=true;
    }
    int ans=solve();
    printf("%d\n", ans);
    return 0;
}