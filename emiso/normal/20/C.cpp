#include <stdio.h>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>

#define MAXN 100100

using namespace std;

typedef long long ll;

int vis[MAXN],parent[MAXN];
ll dist[MAXN];
vector <pair<int,int> > adj[MAXN];
priority_queue <pair<ll,int> > pfila;

void dijkstra(int node) {
    vis[node] = 1;
    dist[node] = 0;
    parent[node] = -1;

    pfila.push(make_pair(0,1));
    while(!pfila.empty()) {
        ll d = -1 * pfila.top().first;
        int v = pfila.top().second;
        pfila.pop();

        if (vis[v] == 1 && dist[v] <= d)  {
            for(int i = 0;i < adj[v].size(); i++) {
                int u = adj[v][i].second;
                int w = adj[v][i].first;
                if(!vis[u] || (vis[u] && dist[u] > (long long) dist[v] + w)) {
                    vis[u] = 1;
                    dist[u] = (long long) dist[v] + w;
                    parent[u] = v;
                    pfila.push(make_pair(-1 * dist[u],u));
                }
            }
        }
    }
}

int main() {
    int n,m,a,b,w;
    scanf("%d %d",&n,&m);
    for(int i=0;i<m;i++) {
        scanf("%d %d %d",&a,&b,&w);
        adj[a].push_back(make_pair(w,b));
        adj[b].push_back(make_pair(w,a));
    }
    dijkstra(1);
    if(vis[n]) {
        int aux = n;
        stack<int> path;
        while(aux > 0) {
            path.push(aux);
            aux = parent[aux];
        }
        while(!path.empty()) {
            printf("%d ",path.top());
            path.pop();
        }
        puts("");
    }
    else printf("-1\n");
    return 0;
}