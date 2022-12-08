#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN = 202000;

int N;

bool vis[MAXN];     //now
bool vis2[MAXN];    //aft

void resv() {
    for(int i = 1;i <= N;i++) {
        vis[i] = vis2[i] = false;
    }
}

int cost[MAXN];
int mov[MAXN];
bool partof;

int dfs(int n) {
    vis[n] = true;
    if(vis2[mov[n]]) {vis2[n] = true; return 0;}
    if(mov[n] == n) {vis2[n] = true; return cost[n];}
    if(vis[mov[n]] and not vis2[mov[n]]) {vis2[mov[n]] = vis2[n] = partof = true; return cost[n];}
    int p = dfs(mov[n]);
    if(vis2[n]) {partof = false; p = min(p, cost[n]);}
    vis2[n] = true;
    return partof ? min(p, cost[n]) : p;
}

int main() {
    scanf("%d", &N);
    
    int ans = 0;
    
    for(int i = 1;i <= N;i++) scanf("%d", &cost[i]);
    for(int i = 1;i <= N;i++) scanf("%d", &mov[i]);
    
    resv();
    for(int i = 1;i <= N;i++) {
        partof = false;
        if(!vis[i]) ans += dfs(i);
    }
    
    printf("%d\n", ans);
    return 0;
}