#include <iostream>
#include <cstdio>

#include <vector>
#include <queue>

using namespace std;

#define pb push_back

typedef vector<int> vi;

const int MAXN = 202000;

int N;

int order[MAXN];
int trav[MAXN];

int par[MAXN];
int childs[MAXN];
vi adj[MAXN];

bool vis[MAXN];

void dfs(int n, int p = -1) {
    par[n] = p;
    int s = 0;
    for(int i = 0;i < adj[n].size();i++) {
        if(adj[n][i] == p) continue;
        dfs(adj[n][i], n);
        s++;
    }
    childs[n] = s;
}

void notvalid() {
    printf("No\n");
    exit(0);
}

int main() {
    scanf("%d", &N);
    
    for(int i = 0;i < N - 1;i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        adj[a].pb(b);
        adj[b].pb(a);
    }
    
    dfs(1);
    
    order[0] = -1;
    for(int i = 0;i < N;i++) {
        scanf("%d", &trav[i]);
        order[trav[i]] = i;
    }
    
    if(trav[0] != 1) {
        notvalid();
    }

    for(int i = 0;i <= N;i++) vis[i] = false;
    for(int i = 0;i < N;i++) {
        if(vis[trav[i]]) {
            notvalid();
        }
        else vis[trav[i]] = true;
    }
    
    int cctr = 1;
    for(int i = 0;i < N;i++) {
        for(int j = 0;j < childs[trav[i]];j++) {
            if(cctr >= N) notvalid();
            if(par[trav[cctr++]] != trav[i]) notvalid();
        }
    }
    
    printf("Yes\n");
    
    return 0;
}