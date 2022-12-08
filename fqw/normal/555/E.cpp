// 23:32
#include <set>
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

const int MAXN=200010;
const int MAXLog=20;

VPI es[MAXN];
int mx[MAXN], my[MAXN];
int n, q;

int dfn[MAXN], low[MAXN], tot, st[MAXN], top;
int belong[MAXN], num;

void dfs(int x, int ei) {
    dfn[x]=low[x]=++tot;
    st[++top]=x;
    belong[x]=-1;
    for(PII e: es[x]) if(e.se!=ei) {
        int y=e.fi;
        if(belong[y]<0) setmin(low[x], dfn[y]);
        if(belong[y]==0) {
            dfs(y, e.se);
            setmin(low[x], low[y]);
        }
    }
    belong[x]=1;
    if(low[x]==dfn[x]) {
        ++num;
        do {belong[st[top--]]=num;} while(st[top+1]!=x);
    }
}

VI es2[MAXN];
set<int> es2s[MAXN];
int up[MAXN][MAXLog], dep[MAXN];
void dfs2(int x, int fa) {
    dep[x]=dep[fa]+1;
    up[x][0]=fa;
    for(int i=0; up[x][i]>0; ++i)
        up[x][i+1]=up[up[x][i]][i];
    for(int y: es2[x]) if(y!=fa)
        dfs2(y, x);
}

int lca(int x, int y) {
    irepn(i, MAXLog) {
        if(dep[up[x][i]]>=dep[y])
            x=up[x][i];
        if(dep[up[y][i]]>=dep[x])
            y=up[y][i];
    }
    irepn(i, MAXLog)
        if(up[x][i]!=up[y][i])
            x=up[x][i], y=up[y][i];
    if(x!=y)
        x=up[x][0], y=up[y][0];
    assert(x==y && x!=0);
    return x;
}

int go_up(int x, int d) {
    repn(i, MAXLog) if(d&(1<<i)) x=up[x][i];
    return x;
}

int color[MAXN], clen[MAXN];
bool ok;

void paint2(int x, int c, int d) {
    if(color[x]>0) {
        if(color[x]!=c) { ok=false; return; }
        setmax(clen[x], d);
    } else {
        color[x]=c;
        clen[x]=d;
    }
}

void paint(int x, int y) {
    if(go_up(x, dep[x]-1)!=go_up(y, dep[y]-1)) {
        ok=false; return;
    }
    int z=lca(x, y);
    if(x!=z) paint2(x, 1, dep[x]-dep[z]);
    if(y!=z) paint2(y, 2, dep[y]-dep[z]);
}

bool vis[MAXN];
PII go(int x, int fa) {
    vis[x]=true;
    for(int y: es2[x]) if(y!=fa) {
        PII r=go(y, x);
        if(r.se>0) paint2(x, r.fi, r.se);
    }
    return mp(color[x], clen[x]-1);
}

int main() {
    int m; scanf("%d%d%d", &n,&m,&q);
    rep(i, 1, n) es[i].clear();
    rep(i, 1, m) { int x, y; scanf("%d%d", &x,&y); es[x].pb(mp(y, i)), es[y].pb(mp(x, i)); }
    rep(i, 1, q) scanf("%d%d", &mx[i],&my[i]);

    num=tot=0; top=0;
    fillchar(belong, 0);
    rep(i, 1, n) if(belong[i]==0) dfs(i, 0);

    rep(i, 1, q) mx[i]=belong[mx[i]], my[i]=belong[my[i]];
    rep(i, 1, num) es2[i].clear(), es2s[i].clear();
    rep(i, 1, n) for(PII e: es[i]) {
        int j=e.fi;
        int i2=belong[i], j2=belong[j];
        if(i2!=j2 && es2s[i2].count(j2)==0) {
            es2[i2].pb(j2);
            es2s[i2].insert(j2);
        }
    }
    fillchar(up, 0); fillchar(dep, 0);
    rep(i, 1, num) if(dep[i]==0) dfs2(i, 0);

    fillchar(color, 0); ok=true;
    rep(i, 1, q) paint(mx[i], my[i]);
    if(ok) {
        fillchar(vis, false);
        rep(i, 1, num) if(!vis[i]) go(i, 0);
    }
    printf("%s\n", ok?"Yes":"No");


    return 0;
}