#include <iostream>
#include <cstdio>

#include <utility>
#include <vector>
#include <queue>
#include <functional>
#include <algorithm>

#include <cassert>

using namespace std;

#define pb push_back
#define mp make_pair

#define p1 second.first
#define p2 second.second

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;
typedef priority_queue<pll, vpll, greater<pll> > pqll;

#define ti(x) static_cast<int>(x)
#define tll(x) static_cast<ll>(x)

const int MAXN = 1e5 + 100;
const int MAXNL2 = 20;
const int MAXM = 1e5 + 100;
const int MAXQ = 1e5 + 100;
const ll INF = 1e18 + 100;

int N, M, Q;
ll ans[MAXQ];
pii q[MAXQ];

pair<ll, pii> edges[MAXM];
vpll adj[MAXN];

int dsup[MAXN], dsus[MAXN];
void dsuinit(int N) {
    for(int i = 0;i <= N;i++) dsup[i] = i, dsus[i] = 1;
}
int dsuf(int x) {
    if(dsup[x] == x) return x;
    return (dsup[x] = dsuf(dsup[x]));
}
bool dsum(int a, int b) {
    a = dsuf(a);
    b = dsuf(b);
    if(a == b) return false;
    if(dsus[a] < dsus[b]) swap(a, b);
    dsup[b] = a;
    dsus[a] += dsus[b];
    dsus[b] = 0;
    return true;
}

ll dist[MAXN];

int dep[MAXN], par[MAXN][MAXNL2];
int l2(int n) {
    int i;
    for(i = 0;(1 << i) <= n;i++);
    return i;
}
void tinit() {
    for(int i = 0;i <= N;i++) for(int j = l2(N);j >= 0;j--) par[i][j] = -1;
}
void tdfs(int n, int d = 0, int p = -1) {
    par[n][0] = p;
    for(int j = 1;j < MAXNL2;j++) if(par[n][j - 1] == -1 or par[par[n][j - 1]][j - 1] == -1) break; else par[n][j] = par[par[n][j - 1]][j - 1];
    dep[n] = d;
    for(int i = 0;i < adj[n].size();i++) {
        if(adj[n][i].second == p) continue;
        dist[adj[n][i].second] = dist[n] + adj[n][i].first;
        tdfs(ti(adj[n][i].second), d + 1, n);
    }
}
int tmu(int a, int d) {
    assert(dep[a] >= d);
    for(int i = l2(dep[a] - d);i >= 0;i--) {
        if(par[a][i] != -1 and dep[par[a][i]] >= d) a = par[a][i];
    }
    assert(dep[a] == d);
    return a;
}
int lca(int a, int b) {
    if(dep[b] > dep[a]) swap(a, b);
    a = tmu(a, dep[b]);
    if(a == b) return a;
    for(int i = l2(dep[a]);i >= 0;i--) {
        if(par[a][i] != -1 and par[b][i] != -1 and par[a][i] != par[b][i]) a = par[a][i], b = par[b][i];
    }
    assert(par[a][0] == par[b][0]);
    return par[a][0];
}

bool vis[MAXN];

int main() {
    scanf("%d%d", &N, &M);
    
    for(int i = 0;i < M;i++) scanf("%d%d%lld", &edges[i].p1, &edges[i].p2, &edges[i].first);
    
    sort(edges, edges + M);//just for good measure
    
    int rm = M;
    
    dsuinit(N);
    for(int i = 0;i < rm;i++) {
        if(dsum(edges[i].p1, edges[i].p2)) {
            adj[edges[i].p1].pb(mp(edges[i].first, edges[i].p2));
            adj[edges[i].p2].pb(mp(edges[i].first, edges[i].p1));
        } else {
            swap(edges[i], edges[--rm]);
            i--;
        }
    }
    
    assert(rm == N - 1);
    
    tinit();
    dist[1] = 0;
    tdfs(1);
    
    scanf("%d", &Q);
    for(int i = 0;i < Q;i++) {
        scanf("%d%d", &q[i].first, &q[i].second);
        int l = lca(q[i].first, q[i].second);
        ans[i] = (dist[q[i].first] - dist[l]) + (dist[q[i].second] - dist[l]);
    }
    
    assert(M - rm <= 25);
    
    for(int i = rm;i < M;i++) {
        adj[edges[i].p1].pb(mp(edges[i].first, edges[i].p2));
        adj[edges[i].p2].pb(mp(edges[i].first, edges[i].p1));
    }
    for(int i = rm;i < M;i++) {
        for(int j = 0;j <= N;j++) dist[j] = INF, vis[j] = false;
        
        pqll pq;
        pq.push(mp(0LL, edges[i].p1));
        dist[edges[i].p1] = 0LL;
        
        while(!pq.empty()) {
            int n = pq.top().second;
            pq.pop();
            if(vis[n]) continue;
            vis[n] = true;
            
            for(int j = 0;j < adj[n].size();j++) {
                if(vis[adj[n][j].second]) continue;
                if(dist[n] + adj[n][j].first < dist[adj[n][j].second]) {
                    dist[adj[n][j].second] = dist[n] + adj[n][j].first;
                    pq.push(mp(dist[adj[n][j].second], adj[n][j].second));
                }
            }
        }
        
        ll t;
        for(int j = 0;j < Q;j++) {
            if((t = dist[q[j].first] + dist[q[j].second]) < ans[j]) ans[j] = t;
        }
    }
    
    for(int i = 0;i < Q;i++) printf("%lld\n", ans[i]);
    
    return 0;
}