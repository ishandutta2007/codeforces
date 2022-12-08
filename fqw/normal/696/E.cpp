// 10:20
#include <algorithm>
#include <functional>
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
typedef pair<LL,int> PLI;
typedef pair<int,int> PII;
typedef pair<double,double> PDD;
typedef vector<LL> VL;
typedef vector<int> VI;
typedef vector<PII> VPI;
typedef vector<string> VS;
template<class T> bool setmax(T &_a, T _b) { if(_b>_a) { _a=_b; return true; } return false; }
template<class T> bool setmin(T &_a, T _b) { if(_b<_a) { _a=_b; return true; } return false; }
template<class T> T gcd(T _a, T _b) { return _b==0?_a:gcd(_b,_a%_b); }

const int N=100010;
const int LOG=20;
const LL INF=1LL<<60;

VI girls[N];
VI es[N];
int n;

int dep[N], up[N][LOG];
int seq[N], ind[N], lastind[N], head[N];

int go_up(int x, int d) {
    repn(i, LOG) if(d&(1<<i)) x=up[x][i];
    return x;
}

int lca(int x, int y) {
    if(dep[x]>dep[y]) {
        x=go_up(x, dep[x]-dep[y]);
    } else {
        y=go_up(y, dep[y]-dep[x]);
    }
    irepn(i, LOG) if(up[x][i]!=up[y][i]) {
        x=up[x][i]; y=up[y][i];
    }
    if(x!=y) {
        x=up[x][0], y=up[y][0];
    }
    assert(x==y);
    return x;
}

void prepare() {
    static int size[N], maxp[N];
    function<void(int, int, int)> dfs1=[&](int x, int fa, int d) {
        dep[x]=d; up[x][0]=fa;
        repn(i, LOG-1) up[x][i+1]=up[up[x][i]][i];
        size[x]=1; maxp[x]=0;
        for(int y: es[x]) if(y!=fa) {
            dfs1(y, x, d+1);
            size[x]+=size[y];
            if(maxp[x]==0 || size[y]>size[maxp[x]]) maxp[x]=y;
        }
    };
    fillchar(up[0], 0);
    dfs1(1, 0, 1);

    int tot=0;
    function<void(int, int, int)> dfs2=[&](int x, int fa, int h) {
        seq[++tot]=x, ind[x]=tot;
        head[x]=h;
        if(maxp[x]>0) {
            const int y=maxp[x];
            dfs2(y, x, h);
        }
        for(int y: es[x]) if(y!=fa && y!=maxp[x]) {
            dfs2(y, x, y);
        }
        lastind[x]=tot;
    };
    dfs2(1, 0, 1);
}

struct Node {
    PLI v;
    LL buf;
} tr[N*4];

void update(int x) { tr[x].v=min(tr[x*2].v, tr[x*2+1].v); }

void release(int x) {
    if(tr[x].buf!=0) {
        tr[x*2].buf+=tr[x].buf;
        tr[x*2].v.fi+=tr[x].buf;
        tr[x*2+1].buf+=tr[x].buf;
        tr[x*2+1].v.fi+=tr[x].buf;
        tr[x].buf=0;
    }
}

void build(int x, int s, int t) {
    tr[x].buf=0;
    if(s==t) {
        LL v=INF;
        if(!girls[seq[s]].empty()) v=girls[seq[s]].back();
        tr[x].v=mp(v, seq[s]);
        return;
    }
    const int mid=(s+t)/2;
    build(x*2, s, mid);
    build(x*2+1, mid+1, t);
    update(x);
}

void add(int x, int s, int t, int st, int en, LL val) {
    if(st<=s && t<=en) {
        tr[x].buf+=val;
        tr[x].v.fi+=val;
        return;
    }
    release(x);
    const int mid=(s+t)/2;
    if(st<=mid) add(x*2, s, mid, st, en, val);
    if(mid<en) add(x*2+1, mid+1, t, st, en, val);
    update(x);
}

PLI get(int x, int s, int t, int st, int en) {
    if(st<=s && t<=en) return tr[x].v;
    release(x);
    const int mid=(s+t)/2;
    PLI r{INF, 0};
    if(st<=mid) setmin(r, get(x*2, s, mid, st, en));
    if(mid<en) setmin(r, get(x*2+1, mid+1, t, st, en));
    return r;
}

PLI get_direct_path(int x, int z) {
    PLI r{INF, 0};
    while(1) {
        int y=head[x]; if(dep[y]<dep[z]) y=z;
        setmin(r, get(1, 1, n, ind[y], ind[x]));
        if(y==z) break;
        else x=up[y][0];
    }
    return r;
}

PLI get_path(int x, int y) {
    int z=lca(x, y);
    return min(get_direct_path(x, z), get_direct_path(y, z));
}

int main() {
    int m, q; scanf("%d%d%d", &n,&m,&q);
    rep(i, 1, n-1) {
        int a, b; scanf("%d%d", &a,&b);
        es[a].pb(b), es[b].pb(a);
    }
    rep(i, 1, m) {
        int c; scanf("%d", &c);
        girls[c].pb(i);
    }
    rep(x, 1, n) reverse(girls[x].begin(), girls[x].end());

    prepare();
    build(1, 1, n);
    while(q--) {
        int t; scanf("%d", &t);
        if(t==1) {
            int u, v, k; scanf("%d%d%d", &u,&v,&k);
            VI ans;
            while(k--) {
                PLI r=get_path(u, v);
                if(r.fi>=INF) break;
                int x=r.se;
                int gi=girls[x].back(); girls[x].pop_back();
                //printf("select %d@%d (%lld)\n",gi,r.se,r.fi);
                ans.pb(gi);
                LL delta=0;
                if(girls[x].empty()) {
                    delta=INF;
                } else {
                    delta=girls[x].back()-gi;
                }
                //printf("  delta=%lld\n",delta);
                add(1, 1, n, ind[x], ind[x], delta);
            }
            printf("%d", sz(ans));
            for(int x: ans) printf(" %d", x);
            printf("\n");
        } else {
            int v, k; scanf("%d%d", &v,&k);
            add(1, 1, n, ind[v], lastind[v], k);
        }
    }


    return 0;
}