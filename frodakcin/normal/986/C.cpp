#include <iostream>
#include <cstdio>

#include <queue>

#include <cassert>
#include <bitset>

using namespace std;

const int MAXN = 23;
const int MAXM = 1 << MAXN;

int N, M;
int Nf;

bool vis[MAXM][2];
bool used[MAXM];

int elem[MAXM];

void bfs(int S) {
    queue<int> qu;
    
    assert(!vis[S][0]);
    vis[S][0] = vis[S][1] = true;
    
    qu.push(S);
    while(!qu.empty()) {
        int n = qu.front();
        
        assert(vis[n][1]);
        
        qu.pop();
        
        int nn = n xor Nf;
        if(used[nn] and !vis[nn][0]) {
            vis[nn][0] = true;
            vis[nn][1] = true;
            qu.push(nn);
        }
        for(int i = 0;i < N;i++) {
            nn = n | (1 << i);
            
            if(vis[nn][1]) continue;
            
            vis[nn][1] = true;
            qu.push(nn);
        }
    }
}

int main() {
    
    scanf("%d%d", &N, &M);
    Nf = (1 << N) - 1;
    
    int ans = 0;
    
    for(int i = 0;i < (1 << N);i++) used[i] = false;
    
    for(int i = 0;i < M;i++) {
        scanf("%d", &elem[i]);
        used[elem[i]] = true;
    }
    
    for(int i = 0;i < (1 << N);i++) vis[i][0] = vis[i][1] = false;
    
    for(int i = 0;i < M;i++) {
        if(!vis[elem[i]][0]) {
            bfs(elem[i]);
            ans++;
        }
    }
    
    printf("%d\n", ans);
    
    return 0;
}