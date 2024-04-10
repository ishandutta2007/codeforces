// 19:26 - 19:52
// 20:22 - 20:39 - finish - wa sample
// 20:48 - 
#include <algorithm>
#include <iostream>
#include <sstream>
#include <cassert>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <set>
#include <map>
using namespace std;

#define _ (size_t)
#define all(a) a.begin(), a.end()
#define forint(i, a, b) for(int i=int(a); i<=int(b); ++i)
#define forintdown(i, a, b) for(int i=int(a); i>=int(b); --i)
#define forn(i, n) forint(i, 0, (n)-1)
#define forndown(i, n) forintdown(i, (n)-1, 0)
#define fillchar(a, x) memset(a, x, sizeof(a))
#define fi first
#define se second
#define PB push_back
#define MP make_pair
#ifdef DEBUG
    #define _debug(args...) { fprintf(stderr, args); fflush(stderr); }
#else
    #define _debug(args...) {}
#endif
typedef long long LL;
typedef pair<LL,LL> PLL;
typedef pair<int,int> PII;
typedef pair<int,int> PDD;
typedef vector<LL> VL;
typedef vector<int> VI;
typedef vector<PII> VPI;
typedef vector<string> VS;
template<class T> bool setmax(T &_a, T _b) { if(_b>_a) { _a=_b; return true; } return false; }
template<class T> bool setmin(T &_a, T _b) { if(_b<_a) { _a=_b; return true; } return false; }
template<class T> T gcd(T _a, T _b) { return _b==0?_a:gcd(_b,_a%_b); }

const int MAXN=100010;
const int MAXQ=100010;
const int MAXLog=20;

int g[MAXN], g_lnk[MAXN*2], g_cst[MAXN*2], g_nxt[MAXN*2];
struct Query { int u, v, l, i; } queries[MAXQ];
int f[MAXN];
int n, q;

void init() {
    scanf("%d%d", &n,&q);
    forint(i, 1, n-1) scanf("%d", &f[i]);
    fillchar(g, 0);
    int e=0;
    forint(i, 1, n-1) {
        int a, b, c; scanf("%d%d%d", &a, &b, &c);
        g_lnk[++e]=b, g_cst[e]=c, g_nxt[e]=g[a], g[a]=e;
        g_lnk[++e]=a, g_cst[e]=c, g_nxt[e]=g[b], g[b]=e;
    }
    forint(i, 1, q) {
        scanf("%d%d%d", &queries[i].u, &queries[i].v, &queries[i].l);
        queries[i].i=i;
    }
}

int the[MAXN], dep[MAXN], size[MAXN], up[MAXN][MAXLog];

void dfs0(int x, int fa) {
    dep[x]=dep[fa]+1;
    size[x]=1;
    fillchar(up[x], 0);
    up[x][0]=fa;
    for(int i=0; up[x][i]>0; ++i)
        up[x][i+1]=up[up[x][i]][i];
    for(int e=g[x]; e; e=g_nxt[e]) {
        int y=g_lnk[e];
        if(y!=fa) {
            dfs0(y, x);
            size[x]+=size[y];
            the[y]=g_cst[e];
        }
    }
}

int go_up(int x, int d) {
    forn(i, MAXLog)
        if(d&(1<<i))
            x=up[x][i];
    return x;
}

int lca(int x, int y) {
    _debug("lca %d %d\n", x, y);
    forndown(i, MAXLog) {
        if(dep[up[x][i]]>=dep[y])
            x=up[x][i];
        if(dep[up[y][i]]>=dep[x])
            y=up[y][i];
    }
    forndown(i, MAXLog) {
        if(up[x][i]!=up[y][i]) {
            x=up[x][i];
            y=up[y][i];
        }
    }
    if(x!=y) {
        x=up[x][0];
        y=up[y][0];
    }
    assert(x==y);
    assert(x!=0);
    return x;
}

int ind[MAXN], head[MAXN], num;

void dfs(int x, int fa) {
    int ymax=0;
    for(int e=g[x]; e; e=g_nxt[e]) {
        int y=g_lnk[e];
        if(y!=fa && size[y]>size[ymax])
            ymax=y;
    }
    for(int e=g[x]; e; e=g_nxt[e]) {
        int y=g_lnk[e];
        if(y!=fa && y!=ymax)
            dfs(y, x);
    }
    if(ymax>0) {
        head[ymax]=head[x];
        dfs(ymax, x);
        assert(ind[ymax]==num);
    }
    ind[x]=++num;
}

void preprocess() {
    fillchar(up[0], 0);
    dep[0]=size[0]=0; 
    the[1]=0;
    dfs0(1, 0);

    forint(i, 1, n) head[i]=i;
    num=0;
    dfs(1, 0);
    assert(num==n);
}

struct St {
    bool pure;
    int l, r, s;
    St() : pure(true), l(0), r(0), s(0) {}
    friend St st_concat(St a, St b) {
        St c;
        if(a.pure && b.pure) {
            assert(a.l==a.r); assert(a.s==0);
            assert(b.l==b.r); assert(b.s==0);
            c.pure=true;
            c.l=c.r=a.l+b.l;
            c.s=0;
            return c;
        }
        c.pure=false;
        if(a.pure) {
            c.l=a.l+b.l;
            c.r=b.r;
            c.s=b.s;
            return c;
        }
        if(b.pure) {
            c.l=a.l;
            c.r=a.r+b.r;
            c.s=a.s;
            return c;
        }
        c.l=a.l;
        c.r=b.r;
        c.s=a.s+b.s+f[a.r+b.l];
        return c;
    }
    St reverse() const {
        St c=*this;
        swap(c.l, c.r);
        return c;
    }
};

struct Tree {
    St tr[MAXN*4];
    void init() {
        forn(i, MAXN*4) {
            tr[i]=St();
            tr[i].pure=false;
        }
    }
    void set(int x, int s, int t, int i) {
        if(s==t) {
            tr[x].pure=true;
            tr[x].l=tr[x].r=1;
            tr[x].s=0;
            return;
        }
        int mid=(s+t)/2;
        if(i<=mid) set(x*2, s, mid, i);
        else set(x*2+1, mid+1, t, i);
        tr[x]=st_concat(tr[x*2], tr[x*2+1]);
    }
    void set(int i) {
        set(1, 1, n, i);
    }
    St get(int x, int s, int t, int st, int en) {
        if(st<=s && t<=en)
            return tr[x];
        int mid=(s+t)/2;
        St ans;
        if(st<=mid) ans=st_concat(ans, get(x*2, s, mid, st, en));
        if(mid<en) ans=st_concat(ans, get(x*2+1, mid+1, t, st, en));
        return ans;
    }
    St get(int l, int r) {
        return get(1, 1, n, l, r);
    }
} tree;

St get_straight(int x, int y) {
    _debug("straight %d %d\n", x,y);
    St st;
    assert(dep[x]>=dep[y]);
    while(dep[x]>dep[y]) {
        int z=head[x];
        if(dep[z]>dep[y]) {
            _debug("  - %d %d (%d,%d)\n", x,up[z][0],ind[x],ind[z]);
            St tmp=tree.get(ind[x], ind[z]);
            st=st_concat(st, tmp);
            x=up[z][0];
        }
        else {
            _debug("  - %d %d (%d,%d)\n", x,y,ind[x],ind[y]-1);
            St tmp=tree.get(ind[x], ind[y]-1);
            st=st_concat(st, tmp);
            x=y;
        }
    }
    assert(x==y);
    return st;
}

int answer(int x, int y) {
    int z=lca(x, y);
    St sx=get_straight(x, z);
    St sy=get_straight(y, z).reverse();
    St s=st_concat(sx, sy);
    _debug("st: %d (%d,%d) s=%d\n",s.pure,s.l,s.r,s.s);
    int ans=s.s;
    ans+=f[s.l];
    if(!s.pure) ans+=f[s.r];
    return ans;
}

void solve() {
    _debug("#1\n");
    static PII keys[MAXN];
    forint(i, 1, n) keys[i]=MP(the[i], i);
    sort(keys+1, keys+n+1, greater<PII>());

    _debug("#2\n");
    static int ans[MAXQ];
    sort(queries+1, queries+q+1, [](const Query &a, const Query &b) -> bool { return a.l>b.l; });
    int cur=1;
    tree.init();
    forint(j, 1, q) {
        _debug("#j=%d %d %d %d\n", j,queries[j].u,queries[j].v,queries[j].l);
        while(cur<=n && keys[cur].fi>=queries[j].l) {
            _debug("set x=%d\n",keys[cur].se);
            tree.set(ind[keys[cur].se]);
            ++cur;
        }
        ans[queries[j].i]=answer(queries[j].u, queries[j].v);
    }

    forint(i, 1, q) printf("%d\n", ans[i]);
}

int main() {
    init();
    preprocess();
    solve();
    return 0;
}