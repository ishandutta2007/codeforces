#include <cassert>
#include <numeric>
#include <map>
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

const int N=410;

VI es[N]; int g[N][N];
VI dx[N];
int n;

double solve2(int d) {
    double ans=1./n;

    static double p[N]; fillchar(p, 0);
    for(int x: dx[d]) for(int y: es[x]) {
        p[y]+=1./n/(double)es[x].size();
    }
    static double r[N];
    static int vis[N]; fillchar(vis, 0);
    rep(y, 1, n) {
        double tmp=0;
        rep(d2, max(0,d-1), d+1) for(int z: dx[d2]) {
            int dis=g[y][z];
            if(vis[dis]<y) vis[dis]=y, r[dis]=0;
            if(p[z]>r[dis]) {
                tmp+=p[z]-r[dis];
                r[dis]=p[z];
            }
        }
        setmax(ans, tmp);
    }
    return ans;
}

double solve() {
    double ans=0;
    rep(x, 1, n) {
        rep(d, 0, n) dx[d].clear();
        rep(y, 1, n) dx[g[x][y]].pb(y);
        double tmp=0;
        rep(d, 0, n) if(!dx[d].empty()) {
            tmp+=solve2(d);
        }
        setmax(ans, tmp);
    }
    return ans;
}

int main() {
    int m; scanf("%d%d", &n,&m);
    fillchar(g, 50); rep(i, 1, n) g[i][i]=0;
    while(m--) {
        int a, b; scanf("%d%d", &a,&b);
        es[a].pb(b), es[b].pb(a);
        g[a][b]=g[b][a]=1;
    }
    rep(k, 1, n) rep(i, 1, n) rep(j, 1, n) {
        setmin(g[i][j], g[i][k]+g[k][j]);
    }
    double ans=solve();
    printf("%.9lf\n", ans);

    return 0;
}