#include <cstdio>
#include <iostream>

#include <vector>
#include <utility>

using namespace std;

#define mp make_pair
#define pb push_back

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

const int MAXN = 110;

int N;

pii edg[MAXN * 2];
vi adj[MAXN];

bool vis[5];
int odd, tot, r[2];

bool rem(int v) {
    for(int i = 0;i < 2;i++) if(v == r[i]) return true;
    return false;
}
void reset() {
    odd = tot = 0;
    for(int i = 0;i < 5;i++) vis[i] = false;
    for(int i = 0;i < 2;i++) r[i] = -1;
}
void dfs(int n) {
    vis[n] = true;
    bool c = false;
    for(int i = 0;i < adj[n].size();i++) {
        if(rem(adj[n][i])) continue;
        tot += edg[adj[n][i]].second;
        c ^= 1;
        if(!vis[edg[adj[n][i]].first]) dfs(edg[adj[n][i]].first);
    }
    odd += c;
}

int main() {
    scanf("%d", &N);
    
    for(int i = 0;i < N;i++) {
        int v[3];
        for(int j = 0;j < 3;j++) scanf("%d", v + j);
        edg[i * 2] = mp(v[2], v[1]);
        adj[v[0]].pb(i * 2);
        edg[i * 2 + 1] = mp(v[0], v[1]);
        adj[v[2]].pb(i * 2 + 1);
    }
    
    int ans = 0;
    for(int i = 1;i <= 4;i++) {
        reset();
        dfs(i);
        
        if(odd < 4) {if(tot > ans * 2) ans = tot/2;}
        else for(int j = 0;j < N;j++) {
            reset();
            r[0] = j * 2, r[1] = j * 2 + 1;
            dfs(i);
            if(odd < 4) if(tot > ans * 2) ans = tot/2;
        }
    }
    
    printf("%d\n", ans);
}