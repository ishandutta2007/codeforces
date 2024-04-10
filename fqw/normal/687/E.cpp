#include <cassert>
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

const int N=5050;

int g[N][N], inf;
VI es[N];
int n, m;
bool ok[N]; int c[N];

int main() {
    scanf("%d%d", &n,&m);
    rep(i, 1, m) {
        int a, b; scanf("%d%d", &a,&b);
        es[a].pb(b);
    }
    fillchar(g, 50); inf=g[0][0];
    rep(x, 1, n) {
        static int q[N];
        int ss=0, tt=1; q[1]=x; g[x][x]=0;
        while(ss<tt) {
            int y=q[++ss];
            for(int z: es[y]) if(g[x][z]==inf) {
                g[x][z]=g[x][y]+1;
                q[++tt]=z;
            }
        }
    }

    fillchar(ok, false);
    rep(x, 1, n) {
        if(es[x].empty()) {
            ok[x]=true; c[x]=0;
            continue;
        }
        int len=inf;
        rep(y, 1, n) if(y!=x && g[x][y]<inf && g[y][x]<inf) {
            setmin(len, g[x][y]+g[y][x]);
        }
        //printf("len[%d]=%d\n",x,len);
        if(len<inf) {
            ok[x]=true; c[x]=len*998+1;
        }
    }
    rep(x, 1, n) rep(y, x+1, n) if(ok[x] && ok[y]) {
        if(g[x][y]<inf && g[y][x]<inf) {
            if(c[x]<c[y]) ok[y]=false;
                else ok[x]=false;
        } else if(g[x][y]<inf) {
            ok[x]=false;
        } else if(g[y][x]<inf) {
            ok[y]=false;
        }
    }
    int ans=n;
    rep(x, 1, n) if(ok[x]) ans+=c[x];
    printf("%d\n", ans);

    return 0;
}