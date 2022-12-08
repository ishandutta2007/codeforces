#include <iostream>
#include <cstdio>

#include <vector>
#include <cassert>

using namespace std;

const int MAXN = 1e6 + 100;
const int INF = 1e9 + 1e6;
int N, K;

typedef vector<int> vi;
#define pb push_back

int p[MAXN];
vi adj[MAXN];
int tp[MAXN], tps;

void dfs(int n = 1) {
    for(int i = 0;i < adj[n].size();i++) dfs(adj[n][i]);
    tp[tps++] = n;
}

int lg[MAXN], lb[MAXN], d[MAXN];

int main() {
    scanf("%d%d", &N, &K);
    
    for(int i = 0;i <= N;i++) p[i] = -1;
    for(int i = 2;i <= N;i++) scanf("%d", p + i), adj[p[i]].pb(i);
    
    tps = 0;
    dfs();
    assert(tps == N);
    
    for(int i = 0, t;i < N;i++) {
        if(adj[tp[i]].size() == 0) {
            lg[tp[i]] = lb[tp[i]] = 1;
            d[tp[i]] = 0;
            continue;
        }
        
        lg[tp[i]] = lb[tp[i]] = 0;
        d[tp[i]] = INF;
        int ext = 0;
        for(int j = 0;j < adj[tp[i]].size();j++) {
            int o = adj[tp[i]][j];
            if(d[o] < K) {
                if((t = lg[o] - lb[o]) > ext) ext = t;
                lg[tp[i]] += lb[o];
                lb[tp[i]] += lb[o];
                if(d[o] + 1 < d[tp[i]]) d[tp[i]] = d[o] + 1;
            }
            if(d[o] >= K) if((t = lg[o]) > ext) ext = t;
        }
        lg[tp[i]] += ext;
    }
    
    printf("%d\n", lg[1]);
    
    return 0;
}