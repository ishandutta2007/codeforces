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

const int N=1010;
const int M=30030;
const LL INF=1LL<<60;

VPI es[N];
LL cost[M];
int n, m, s, t;

int dfn[N], low[N], vis[N], pre[N], prei[N], tot;
int banned_i;

void dfs(int x, int pi) {
    dfn[x]=low[x]=++tot;
    vis[x]=-1;
    for(const auto& e: es[x]) if(e.se!=pi && e.se!=banned_i) {
        const int y=e.fi;
        if(vis[y]==0) {
            pre[y]=x, prei[y]=e.se;
            dfs(y, e.se);
            setmin(low[x], low[y]);
        } else if(vis[y]<0) {
            setmin(low[x], dfn[y]);
        }
    }
    vis[x]=1;
}

bool is_bridge(int a, int b) {
    return low[b]>dfn[a];
}

pair<LL, VI> solve(int chances) {
    fillchar(vis, 0); tot=0;
    dfs(s, 0);
    if(vis[t]==0) return mp(0, VI());

    pair<LL, VI> ans=mp(INF, VI());
    for(int b=t, a=pre[t]; b!=s; b=a, a=pre[a]) {
        if(is_bridge(a, b) && setmin(ans.fi, cost[prei[b]])) {
            ans.se={prei[b]};
        }
    }
    if(chances==2) {
        static int copy_pre[N], copy_prei[N];
        memmove(copy_pre, pre, sizeof(pre));
        memmove(copy_prei, prei, sizeof(prei));
        for(int b=t, a=copy_pre[t]; b!=s; b=a, a=copy_pre[a]) {
            const int i=copy_prei[b];
            banned_i=i;
            auto r=solve(chances-1);
            if(setmin(ans.fi, r.fi+cost[i])) {
                ans.se=r.se; ans.se.pb(i);
            }
            banned_i=0;
        }
    }
    return ans;
}

int main() {
    scanf("%d%d%d%d", &n,&m,&s,&t);
    rep(i, 1, m) {
        int a, b, c; scanf("%d%d%d", &a,&b,&c);
        cost[i]=c;
        es[a].pb(mp(b, i));
        es[b].pb(mp(a, i));
    }

    banned_i=0;
    auto ans=solve(2);
    if(ans.fi==INF) printf("-1\n");
    else {
        cout<<ans.fi<<endl;
        cout<<sz(ans.se)<<endl;
        for(int i: ans.se) cout<<i<<" "; cout<<endl;
    }

    return 0;
}