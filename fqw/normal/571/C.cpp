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

template <size_t maxn, size_t maxedges> class Graph {
public:
    int g[maxn], g_lnk[maxedges], g_next[maxedges];
    int dx[maxn], dy[maxn], q[maxn];
    int lx[maxn], ly[maxn];
    int n, m, ecnt;

    bool build() {
        int ss = 0, tt = 0;
        bool found = false;
        fillchar(dx, 0xff);
        fillchar(dy, 0xff);
        repn (x, n)
            if (lx[x] < 0)
                dx[q[tt++]=x] = 0;
        while (ss < tt)
            for (int x = q[ss++], e = g[x], y; e >= 0; e = g_next[e])
                if (dy[y=g_lnk[e]] < 0) {
                    dy[y] = dx[x]+1;
                    if (ly[y] < 0) found = true;
                    else dx[q[tt++]=ly[y]] = dy[y]+1;
                }
        return found;
    }
    bool find(int x) {
        for (int e = g[x], y; e >= 0; e = g_next[e])
            if (dy[y=g_lnk[e]] > dx[x]) {
                dy[y] = -1;
                if (ly[y] < 0 || find(ly[y])) {
                    lx[x] = y; ly[y] = x;
                    return true;
                }
            }
        return false;
    }
public:
    void initialize(int _n, int _m) {
        n = _n, m = _m;
        ecnt = 0, fillchar(g, 0xff);
    }
    void add_edge(int x, int y) {
        g_lnk[ecnt] = y, g_next[ecnt] = g[x], g[x] = ecnt;
        ++ ecnt;
    }
    int max_matching() {
        int ans = 0;
        fillchar(lx, 0xff);
        fillchar(ly, 0xff);
        while (build())
            repn (x, n)
                if (lx[x] < 0 && find(x))
                    ++ ans;
        return ans;
    }
};

const int MAXN=200010;

VPI a[MAXN];
bool done[MAXN]; int usign[MAXN], upos[MAXN];
int n, m;

void solve() {
    fillchar(usign, 0xff);
    rep(i, 1, n) for(PII p: a[i]) {
        if(usign[p.fi]<0)
            usign[p.fi]=p.se;
        else if(usign[p.fi]!=p.se)
            usign[p.fi]=2;
    }
    fillchar(done, false);
    rep(i, 1, n) for(PII p: a[i]) {
        if(usign[p.fi]==p.se)
            done[i]=true;
    }

    static Graph<MAXN, MAXN*2> g;
    g.initialize(n, m);
    int cnt=0;
    rep(i, 1, n) if(!done[i]) {
        ++cnt;
        for(PII p: a[i]) {
            if(p.se==1) upos[p.fi]=i;
            g.add_edge(i-1, p.fi-1);
        }
    }
    if(g.max_matching()!=cnt) {
        printf("NO\n"); return;
    }
    rep(i, 1, m) {
        if(usign[i]<0) { usign[i]=0; continue; }
        if(usign[i]>1) {
            usign[i]=(g.ly[i-1]==upos[i]-1);
        }
    }
    printf("YES\n");
    rep(i, 1, m) printf("%d", usign[i]); printf("\n");
}

int main() {
    scanf("%d%d", &n,&m);
    rep(i, 1, n) {
        int k; scanf("%d", &k);
        a[i].clear();
        while(k--) {
            int j; scanf("%d", &j);
            int sign=(j>0); if(j<0) j=-j;
            a[i].pb(mp(j, sign));
        }
    }
    solve();
    return 0;
}