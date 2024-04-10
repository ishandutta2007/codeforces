#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<int> adj[100001];
vector<int> adj2[100001];
vector<int> order;
map<pair<int, int>, int> edges;
bool seen[100001];
int to[100001];
int from[100001];
int dp[100001];
int path[100001];
vector<pair<pair<int, int>, int>> ans;

void bfs(int u, int dist[])
{
    memset(seen, 0, sizeof seen);
    queue<int> Q;
    Q.push(u);
    seen[u]=true;
    dist[u]=0;
    while(!Q.empty())
    {
        u=Q.front();
        Q.pop();
        for(auto& v: adj[u])
            if(!seen[v])
                dist[v]=dist[u]+1, Q.push(v), seen[v]=true;
    }
}

void dfs(int u)
{
    seen[u]=true;
    for(auto& v: adj2[u])
        if(!seen[v])
            dfs(v);
    order.push_back(u);
}

void trace(int v)
{
    if(v==1)
        return;
    int u=path[v];
    if(edges.count({u, v}))
    {
        if(!edges[{u, v}])
            ans.push_back({{u, v}, 1});
        edges.erase({u, v});
    }
    else
    {
        if(!edges[{v, u}])
            ans.push_back({{v, u}, 1});
        edges.erase({v, u});
    }
    trace(u);
}

int main()
{
    scanf("%d%d", &N, &M);
    int a, b, c;
    for(int i=0; i<M; i++)
    {
        scanf("%d%d%d", &a, &b, &c);
        adj[a].push_back(b);
        adj[b].push_back(a);
        edges[{a, b}]=c;
    }
    bfs(1, to);
    bfs(N, from);
    int shortest=to[N];
    for(auto& it: edges)
    {
        a=it.first.first;
        b=it.first.second;
        if(to[a]+1+from[b]==shortest)
            adj2[a].push_back(b);
        else if(to[b]+1+from[a]==shortest)
            adj2[b].push_back(a);
        else if(it.second==1)
            ans.push_back({{a, b}, 0});
    }
    memset(seen, 0, sizeof seen);
    dfs(1);
    reverse(order.begin(), order.end());
    memset(dp, 0x3f, sizeof dp);
    dp[1]=0;
    for(auto& u: order)
        for(auto& v: adj2[u])
        {
            int n=dp[u]+(edges.count({u, v})?(1^edges[{u, v}]):(1^edges[{v, u}]));
            if(n<dp[v])
                dp[v]=n, path[v]=u;
        }
    trace(N);
    for(int u=1; u<=N; u++)
        for(auto& v: adj2[u])
        {
            if(edges.count({u, v}))
            {
                if(edges[{u, v}])
                    ans.push_back({{u, v}, 0});
            }
            else if(edges.count({v, u}))
            {
                if(edges[{v, u}])
                    ans.push_back({{v, u}, 0});
            }
        }
    printf("%d\n", ans.size());
    for(auto& it: ans)
        printf("%d %d %d\n", it.first.first, it.first.second, it.second);
    return 0;
}