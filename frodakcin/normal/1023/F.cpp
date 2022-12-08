#include <iostream>
#include <cstdio>

#include <vector>
#include <algorithm>
#include <utility>
#include <cassert>

using namespace std;

#define mp make_pair
#define fv first
#define sv second
#define pb push_back

typedef long long ll;
typedef vector<int> vi;
typedef pair<bool, int> pbi;
typedef vector<pbi> vpbi;

const int MAXN = 505000;
const int MAXNL2 = 21;
const int MAXK = 505000;
const int MAXM = 505000;
const int INF = 1000000010;

int N, K, M, NL2;

int log2(int n) {
    for(int i = 0;i <= MAXNL2;i++) if((1 << i) > n) return i;
    return -1;
}

int dep[MAXN];
int par[MAXN][MAXNL2];
vpbi adj[MAXN];
vi atdep[MAXN];
bool vis[MAXN];
bool selling[MAXN];

void tdfs(int n, int p = -1, int d = 0) {
    if(vis[n]) return;
    vis[n] = true;
    par[n][0] = p;
    dep[n] = d;
    atdep[d].pb(n);
    
    for(int i = 0;i < adj[n].size();i++) {
        if(adj[n][i].sv == p) continue;
        assert(!vis[adj[n][i].sv]);
        selling[adj[n][i].sv] = adj[n][i].fv;
        tdfs(adj[n][i].sv, n, d + 1);
    }
}

int tmu(int a, int d) {
    assert(dep[a] >= d);
    for(int i = log2(dep[a] - d);i >= 0;i--) if(par[a][i] != -1 and dep[par[a][i]] >= d) a = par[a][i];
    assert(dep[a] == d);
    return a;
}

int tlca(int a, int b) {
    if(dep[b] > dep[a]) swap(a, b);
    a = tmu(a, dep[b]);
    
    if(a == b) return a;

    for(int i = log2(dep[b]);i >= 0;i--) if(par[a][i] != -1 and par[b][i] != -1 and par[a][i] != par[b][i]) a = par[a][i], b = par[b][i];
    
    assert(par[a][0] != -1 and par[a][0] == par[b][0]);
    return par[a][0];
}

int ans[MAXN];
int equ[MAXN];

int paint(int s, int e, int w) {
    if(dep[s] <= dep[e]) return s;
    if(equ[s] != s) return (equ[s] = paint(equ[s], e, w));
    assert(ans[s] == -1);
    ans[s] = w;
    return (equ[s] = paint(par[equ[s]][0], e, w));
}

//DISJOINT UNION
int dsup[MAXN], dsus[MAXN];
void dsuinit(int n) {
    for(int i = 0;i <= n;i++) {
        dsup[i] = i;
        dsus[i] = 1;
        //not dsu but still init
        vis[i] = false;
        dep[i] = -1;
    }
}
int dsuf(int a) {
    if(dsup[a] == a) return a;
    return dsup[a] = dsuf(dsup[a]);
}
bool dsum(int a, int b) {
    a = dsuf(a);
    b = dsuf(b);
    if(a == b) return false;
    if(dsus[b] > dsus[a]) swap(a, b);
    dsup[b] = a;
    dsus[a] += dsus[b];
    return true;
}

struct segment {
public:
    int p[2];
    int w;
    
    segment() {
        p[0] = p[1] = w = -1;
    }
    segment(int a, int b, int c) {
        p[0] = a;
        p[1] = b;
        w = c;
    }
    
    inline bool operator < (const segment& o) const {return w < o.w;}
    inline bool operator > (const segment& o) const {return w > o.w;}
} cmpt[MAXM], cmpt2[MAXM];

bool cmp(segment a, segment b) {return a < b;}

int main() {
    scanf("%d%d%d", &N, &K, &M);
    NL2 = log2(N);
    
    dsuinit(N);
    
    for(int i = 0;i < K;i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        assert(dsum(a, b));
        adj[a].pb(mp(true, b));
        adj[b].pb(mp(true, a));
    }
    
    for(int i = 0;i < M;i++) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        cmpt[i] = segment(a, b, c);
    }
    
    sort(cmpt, cmpt + M, cmp);
    
    int ctr = 0;
    for(int i = 0;i < M;i++) {
        if(dsum(cmpt[i].p[0], cmpt[i].p[1])) {
            adj[cmpt[i].p[0]].pb(mp(false, cmpt[i].p[1]));
            adj[cmpt[i].p[1]].pb(mp(false, cmpt[i].p[0]));
        } else {
            cmpt2[ctr++] = cmpt[i];
        }
    }
    
    for(int i = 0;i <= N;i++) for(int j = 0;j < NL2;j++) par[i][j] = -1;
    for(int i = 1;i <= N;i++) {
        if(dsup[i] == i) {
            assert(!vis[i]);
            tdfs(i);
        }
    }
    for(int d = 0;d < N;d++) for(int i : atdep[d]) for(int j = 0;j < NL2;j++)
    {
        if(par[i][j] == -1 or par[par[i][j]][j] == -1) break;
        par[i][j + 1] = par[par[i][j]][j];
        assert(dep[par[i][j]] - dep[par[par[i][j]][j]] == 1 << j);
    }
    
    for(int i = 0;i <= N;i++) ans[i] = -1, equ[i] = i;
    
    for(int i = 0;i < ctr;i++) {
        if(dsuf(cmpt2[i].p[0]) != dsuf(cmpt2[i].p[1])) continue;
        int l = tlca(cmpt2[i].p[0], cmpt2[i].p[1]);
        for(int j = 0;j < 2;j++) paint(cmpt2[i].p[j], l, cmpt2[i].w);
    }
    
    ll fans = 0;
    for(int i = 0;i <= N;i++) {
        if(par[i][0] == -1 or !selling[i]) continue;
        if(ans[i] == -1) {fans = -1; break;}
        fans += ans[i];
    }
    printf("%lld\n", fans);
    
}