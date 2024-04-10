#include <cstdio>
#include <iostream>

#include <vector>
#include <cassert>

using namespace std;

#define pb push_back

typedef vector<int> vi;

const int MAXN = 1010000;
const int MAXS = 25;

int N, M;
int ts[MAXN], tss;

vi adj[MAXN], adjr[MAXN];
bool vis[MAXN];

void dfs(int n) {
    vis[n] = true;
    for(int i = 0;i < adj[n].size();i++) if(!vis[adj[n][i]]) dfs(adj[n][i]);
    ts[tss++] = n;
}

int snk[MAXS], snks;
int src[MAXS], srcs;

int s[MAXN];

int main() {
    
    scanf("%d%d", &N, &M);
    
    for(int i = 0;i < M;i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        adj[a].pb(b);
        adjr[b].pb(a);
    }
    
    for(int i = 1;i <= N;i++) vis[i] = false;
    
    tss = 0;
    for(int i = 1;i <= N;i++) if(!vis[i]) dfs(i);
    
    for(int i = 1;i <= N;i++) s[i] = 0;
    
    snks = srcs = 0;
    for(int i = 0;i < tss;i++) {
        if(adj[ts[i]].size() == 0) {
            s[ts[i]] |= (1 << snks);
            snk[snks++] = ts[i];
        }
        if(adjr[ts[i]].size() == 0) src[srcs++] = ts[i];
        
        for(int j = 0;j < adj[ts[i]].size();j++) s[ts[i]] |= s[adj[ts[i]][j]];
    }
    assert(snks == srcs and srcs < MAXS);
    
    int t;
    bool ans = false;
    for(int mask = 1;mask < (1 << srcs) - 1;mask++) {
        t = 0;
        for(int j = 0;j < srcs;j++) if(mask & (1 << j)) t |= s[src[j]];
        if(__builtin_popcount(t) <= __builtin_popcount(mask)) ans = true;
    }
    
    if(ans) printf("NO\n");
    else printf("YES\n");
    
    return 0;
}