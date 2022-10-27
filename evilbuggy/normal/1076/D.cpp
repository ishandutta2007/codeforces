#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;

const ll inf = (1LL<<62);

struct Edge{
    int v, ind;
    ll w;
    Edge(){}
    Edge(int iv, int ii, ll iw){
        v = iv;
        ind = ii;
        w = iw;
    }
};

vector<Edge> g[300005];
vector<pair<int,int> > rg[300005];
int n, k;
bool vis[300005];
ll dist[300005];
Edge pedge[300005];
vector<int> chld;

void dfs(int v, int p){
    if(k == 0)return;
    for(int i = 0; i < rg[v].size(); i++){
        if(k == 0)return;
        if(rg[v][i].first == p)continue;
        cout<<rg[v][i].second+1<<" ";
        k--;
        dfs(rg[v][i].first, v);
    }
}

int main(){

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int m, u, v, w;
    cin>>n>>m>>k;
    for(int i = 0; i < m; i++){
        cin>>u>>v>>w;
        g[u].push_back(Edge(v, i, w));
        g[v].push_back(Edge(u, i, w));
    }

    memset(vis, false, sizeof(vis));
    for(int i = 1; i <= n; i++){
        dist[i] = inf;
    }
    dist[1] = 0;
    priority_queue<pair<ll, int>, vector<pair<ll, int> >, greater<pair<ll, int> > > pq;
    pq.push(make_pair(0, 1));
    while(!pq.empty()){
        pair<ll, int> y = pq.top();
        pq.pop();
        u = y.second;
        if(vis[u])continue;
        vis[u] = true;
        for(int i = 0; i < g[u].size(); i++){
            v = g[u][i].v;
            if(vis[v])continue;
            if(dist[v] > dist[u] + g[u][i].w){
                dist[v] = dist[u] + g[u][i].w;
                pedge[v] = Edge(u, g[u][i].ind, 0);
                pq.push(make_pair(dist[v], v));
            }
        }
    }
    if(k == 0){
        cout<<0<<endl;
        return 0;
    }
    if(k >= n-1){
        cout<<n-1<<endl;
        for(int i = 2; i <= n; i++){
            cout<<pedge[i].ind + 1<<" ";
        }
        cout<<endl;
        return 0;
    }
    for(int i = 2; i <= n; i++){
        rg[pedge[i].v].push_back(make_pair(i, pedge[i].ind));
    }
    cout<<k<<endl;
    dfs(1, 1);
}