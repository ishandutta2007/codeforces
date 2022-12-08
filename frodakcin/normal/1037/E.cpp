#include <iostream>
#include <cstdio>

#include <vector>
#include <utility>
#include <queue>

#include <cassert>

using namespace std;

#define pb push_back
#define mp make_pair

typedef vector<int> vi;
typedef queue<int> qi;
typedef pair<int, int> pii;

using namespace std;

const int MAXN = 202000;
const int MAXM = 202000;
const int MAXK = 202000;

int N, M, K;

vi adj[MAXN];
pii edges[MAXM];
int ans[MAXM];

bool inc[MAXN];
int deg[MAXM];

int tans;

void init() {
    qi qu;
    for(int i = 1;i <= N;i++) {
        if(deg[i] < K) {
            tans--;
            qu.push(i);
            inc[i] = false;
        }
    }
    
    
    while(!qu.empty()) {
        int n = qu.front();
        qu.pop();
        
        for(int i = 0;i < adj[n].size();i++) {
            if(!inc[adj[n][i]]) continue;
            
            deg[adj[n][i]]--;
            if(deg[adj[n][i]] < K) {
                tans--;
                qu.push(adj[n][i]);
                inc[adj[n][i]] = false;
            }
        }
        
        deg[0] = 0;
    }
}

int main() {
    scanf("%d%d%d", &N, &M, &K);
    
    for(int i = 0;i <= N;i++) {
        deg[i] = 0;
        inc[i] = true;
    }
    
    for(int i = 0;i < M;i++) {
        scanf("%d%d", &edges[i].first, &edges[i].second);
        adj[edges[i].first].pb(edges[i].second);
        adj[edges[i].second].pb(edges[i].first);
        
        deg[edges[i].first]++;
        deg[edges[i].second]++;
    }
    
    tans = N;
    init();
    
    for(int i = M - 1;i >= 0;i--) {
        ans[i] = tans;
        
        assert(adj[edges[i].first].back() == edges[i].second);
        adj[edges[i].first].pop_back();
        
        assert(adj[edges[i].second].back() == edges[i].first);
        adj[edges[i].second].pop_back();
        
        if(inc[edges[i].first] and inc[edges[i].second])
        {
            qi qu;
            
            if(deg[edges[i].first] -- == K) {
                tans--;
                inc[edges[i].first] = false;
                qu.push(edges[i].first);
            }
            if(deg[edges[i].second] -- == K) {
                tans--;
                inc[edges[i].second] = false;
                qu.push(edges[i].second);
            }
            
            while(!qu.empty()) {
                int n = qu.front();
                qu.pop();
        
                for(int i = 0;i < adj[n].size();i++) {
                    if(!inc[adj[n][i]]) continue;
                    
                    deg[adj[n][i]]--;
                    if(deg[adj[n][i]] < K) {
                        tans--;
                        qu.push(adj[n][i]);
                        inc[adj[n][i]] = false;
                    }
                }
            }
        }
        
    }
    
    for(int i = 0;i < M;i++) printf("%d\n", ans[i]);
    
    return 0;
}