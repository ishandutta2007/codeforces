#include <queue>
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

const int N=3030;
const int M=5050;
const int K=5;

int g[N][N], pre[N][N], n, maxval;
PII far_in[N][K], far_out[N][K];
VI es[N];

void update(PII far[], PII c) {
    int i=K-1;
    if(setmax(far[i], c)) {
        while(i>0 && far[i]>far[i-1]) {
            swap(far[i], far[i-1]);
            --i;
        }
    }
}

bool diff(int x, int y1) { return x!=y1; }
bool diff(int x, int y1, int y2) { return x!=y1 && x!=y2; }
bool diff(int x, int y1, int y2, int y3) { return x!=y1 && x!=y2 && x!=y3; }

int main() {
    int m; scanf("%d%d", &n,&m);
    while(m--) {
        int a, b; scanf("%d%d", &a,&b);
        es[a].pb(b);
    }
    rep(start, 1, n) {
        fillchar(g[start], 50); maxval=g[start][0];
        queue<int> q;
        g[start][start]=0; pre[start][start]=-1;
        q.push(start);
        while(!q.empty()) {
            int x=q.front(); q.pop();
            for(int y: es[x]) if(g[start][y]==maxval) {
                g[start][y]=g[start][x]+1;
                pre[start][y]=x;
                q.push(y);
            }
        }
    }
    rep(x, 1, n) {
        repn(k, K) far_in[x][k]=far_out[x][k]=mp(0, x);
        rep(y, 1, n) {
            if(g[y][x]<maxval) update(far_in[x], mp(g[y][x], y));
            if(g[x][y]<maxval) update(far_out[x], mp(g[x][y], y));
        }
    }
    int ans=-1, x1=0, x2=0, x3=0, x4=0;
    rep(x, 1, n) rep(y, 1, n) if(x!=y && g[x][y]<maxval) {
        repn(kx, K) if(diff(far_in[x][kx].se, x, y)) {
            int ix=far_in[x][kx].se;
            repn(ky, K) if(diff(far_out[y][ky].se, x, y, ix)) {
                int oy=far_out[y][ky].se;
                if(setmax(ans, g[x][y]+g[ix][x]+g[y][oy])) { //far_in[x][kx].fi+far_out[y][ky].fi)) {
                    x1=ix, x2=x, x3=y, x4=oy;
                }
            }
        }
    }
    //printf("ans=%d\n",ans);
    printf("%d %d %d %d\n", x1,x2,x3,x4);
    //printf("%d %d %d\n", g[x1][x2], g[x2][x3], g[x3][x4]);



    return 0;
}