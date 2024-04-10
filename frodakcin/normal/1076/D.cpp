#include <iostream>
#include <cstdio>

#include <vector>
#include <queue>
#include <functional>
#include <algorithm>

#include <cassert>

using namespace std;

const int MAXN = 3e5 + 100;
const int MAXM = 3e5 + 100;

int N, M, K;

struct edg {
    int u, v, w, id;
    bool operator < (const edg& o) const {
        return w < o.w or (not (o.w < w) and id < o.id);
    }
} edges[MAXM];
int nn(int c, int i) {
    if(edges[i].u == c) return edges[i].v;
    else if (edges[i].v == c) return edges[i].u;
    else assert(false);
    return -1;
}
int ww(int i) {
    return edges[i].w;
}

typedef long long ll;
#define tll(x) static_cast<ll>(x)
typedef pair<ll, int> pii;
#define ff first
#define ss second

int dsup[MAXN], dsur[MAXN];
void dsui(const int& n) {
    for(int i = 0;i <= N;i++) dsup[i] = i, dsur[i] = 0;
}
int dsuf(const int& n) {
    if(dsup[n] == n) return n;
    return dsup[n] = dsuf(dsup[n]);
}
bool dsum(int a, int b) {
    a = dsuf(a);
    b = dsuf(b);
    if(a == b) return false;
    
    if(dsur[a] < dsur[b]) swap(a, b);
    
    dsup[b] = a;
    dsur[a]++, dsur[b] = 0;
    
    return true;
}

int anss;
bool ans[MAXN];

void done() {
    printf("%d\n", anss);
    for(int i = 0;i < M;i++) if(ans[i]) printf("%d ", i + 1);
    printf("\n");
    exit(0);
}

typedef vector<int> vi;
vi adj[MAXN], adj1[MAXN];
#define pb push_back

void dfs(const int& n = 1, const int& p = -1) {
    for(int i = 0, u;i < adj[n].size();i++) {
        if((u = nn(n, adj[n][i])) == p) continue;
        
        dfs(u, n);
        
        assert(ans[edges[adj[n][i]].id]);
        anss--;
        ans[edges[adj[n][i]].id] = false;
        
        if(anss <= K) done();
    }
}

typedef priority_queue<pii, vector<pii>, greater<pii> > pq;

ll d[MAXN];
bool v[MAXN];
int par[MAXN];

int main() {
    scanf("%d%d%d", &N, &M, &K);
    
    anss = 0;
    for(int i = 0;i < M;i++) ans[i] = false;
    
    for(int i = 0;i < M;i++) {
        scanf("%d%d%d", &edges[i].u, &edges[i].v, &edges[i].w), edges[i].id = i;
        adj1[edges[i].u].pb(i);
        adj1[edges[i].v].pb(i);
    }
    
    
    for(int i = 0;i <= N;i++) v[i] = false, d[i] = 1e17, par[i] = -1;
    
    pq q;
    
    q.push(make_pair(0, 1));
    d[1] = 0;
    
    while(!q.empty()) {
        pii cn = q.top();
        q.pop();
        if(v[cn.ss]) continue;
        v[cn.ss] = true;
        
        for(int i = 0, u;i < adj1[cn.ss].size();i++) {
            if((u = nn(cn.ss, adj1[cn.ss][i])) == par[cn.ss]) {
                anss++;
                ans[edges[adj1[cn.ss][i]].id] = true;
                continue;
            }
            ll nd = cn.ff + ww(adj1[cn.ss][i]);
            if(nd < d[u]) {
                assert(not v[u]);
                d[u] = nd;
                par[u] = cn.ss;
                q.push(make_pair(nd, u));
            }
        }
    }
    
    //cerr << "here" << "\n";
    
    dsui(N);
    sort(edges, edges + M);
    for(int i = 0;i < M;i++) {
        if(!ans[edges[i].id]) continue;
        if(dsum(edges[i].u, edges[i].v)) {
            adj[edges[i].u].pb(i);
            adj[edges[i].v].pb(i);
        } else {
            anss--;
            ans[edges[i].id] = false;
        }
    }
    
    //cerr << "here" << "\n";
    
    assert(anss == N - 1);
    
    if(anss <= K) done();
    
    dfs();
    
    assert(false);
    
    return 0;
}