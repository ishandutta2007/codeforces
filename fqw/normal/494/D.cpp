// 19:45
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

const int MAXN=100010, MAXLog=20;
const LL MOD=LL(1e9)+7;

LL dis[MAXN]; int st[MAXN], en[MAXN], size[MAXN], tot;
VPI es[MAXN]; int up[MAXN][MAXLog], dep[MAXN];
int n;

void dfs(int x, int fa, LL d) {
    up[x][0]=fa; dep[x]=dep[fa]+1;
    for(int i=0; up[x][i]>0; ++i) up[x][i+1]=up[up[x][i]][i];
    dis[x]=d;
    st[x]=++tot;
    size[x]=1;
    for(PII p: es[x]) if(p.fi!=fa) {
        dfs(p.fi, x, d+p.se);
        size[x]+=size[p.fi];
    }
    en[x]=tot;
}

int lca(int x, int y) {
    irepn(i, MAXLog) {
        if(dep[up[x][i]]>=dep[y]) x=up[x][i];
        if(dep[up[y][i]]>=dep[x]) y=up[y][i];
    }
    irepn(i, MAXLog)
        if(up[x][i]!=up[y][i])
            x=up[x][i], y=up[y][i];
    if(x!=y) x=up[x][0], y=up[y][0];
    assert(x==y && x!=0);
    return x;
}

struct Val {
    LL s, s2, cnt;
    void add(LL x) {
        x%=MOD;
        LL t=(s+x*cnt)%MOD;
        LL t2=(s2+cnt*x%MOD*x%MOD+2*x*s)%MOD;
        s=t, s2=t2;
    }
    void merge(const Val &v) {
        (s+=v.s)%=MOD;
        (s2+=v.s2)%=MOD;
        (cnt+=v.cnt)%=MOD;
    }
    void exclude(const Val &v) {
        (s-=v.s)%=MOD;
        (s2-=v.s2)%=MOD;
        (cnt-=v.cnt)%=MOD;
    }
};

Val S[MAXN], T[MAXN], W[MAXN];

void cal_S(int x, int fa) {
    S[x].cnt=1, S[x].s=S[x].s2=0;
    for(PII p: es[x]) if(p.fi!=fa) {
        cal_S(p.fi, x);
        Val tmp=S[p.fi]; tmp.add(p.se);
        S[x].merge(tmp);
    }
}

void cal_T(int x, int fa) {
    W[x]=S[x]; W[x].merge(T[x]);
    for(PII p: es[x]) if(p.fi!=fa) {
        Val sub=S[p.fi]; sub.add(p.se);
        Val tmp=W[x]; tmp.exclude(sub);
        tmp.add(p.se);
        T[p.fi]=tmp;
        cal_T(p.fi, x);
    }
}

void solve(int u, int v) {
    LL ans;
    if(st[v]<=st[u] && en[u]<=en[v]) { // u in S(v)
        ans=W[u].s2;
        Val tmp=T[v]; tmp.add(dis[u]-dis[v]);
        (ans-=2*tmp.s2)%=MOD;
    } else {
        ans=-W[u].s2;
        Val tmp=S[v];
        int z=lca(u, v); LL d=dis[u]+dis[v]-2*dis[z];
        tmp.add(d);
        (ans+=2*tmp.s2)%=MOD;
    }
    ans=(ans%MOD+MOD)%MOD;
    printf("%d\n", (int)ans);
}

int main() {
    while(scanf("%d", &n)>0) {
    rep(i, 1, n) es[i].clear();
    rep(i, 1, n-1) {
        int a, b, c; scanf("%d%d%d", &a,&b,&c);
        es[a].pb(mp(b, c));
        es[b].pb(mp(a, c));
    }

    tot=0; fillchar(up, 0); dep[0]=0; dfs(1, 0, 0);
    fillchar(S, 0); cal_S(1, 0);
    fillchar(T, 0); cal_T(1, 0);

    int q; scanf("%d", &q);
    while(q--) {
        int u, v; scanf("%d%d", &u,&v);
        solve(u, v);
    }
    }
    
    return 0;
}