#include <bits/stdc++.h>

using namespace std;

int N;
int ans[400001];
int sz[400001];
set<pair<int, int>> s[400001];
multiset<int> ss[400001];
vector<int> adj[400001];

int f(int u)
{
    int ret=0;
    if(!ss[u].empty())
        ret=*ss[u].rbegin();
    if(sz[u]<=N/2)
        ret=max(ret, sz[u]);
    return ret;
}

void dfs(int u, int p)
{
    sz[u]=1;
    for(auto& v: adj[u]) if(v!=p)
    {
        dfs(v, u);
        ss[u].insert(f(v));
        s[u].insert({sz[v], v});
        sz[u]+=sz[v];
    }
    s[u].insert({sz[u], u});
}

void moveroot(int u, int v)
{
    s[u].erase({sz[u], u});
    s[u].erase({sz[v], v});
    s[v].erase({sz[v], v});
    ss[u].erase(ss[u].find(f(v)));
    sz[u]-=sz[v];
    sz[v]+=sz[u];
    ss[v].insert(f(u));
    s[v].insert({sz[v], v});
    s[v].insert({sz[u], u});
    s[u].insert({sz[u], u});
}

void dfs2(int u, int p)
{
    auto maxi=----s[u].end();
    if(maxi->first<=N/2)
        ans[u]=1;
    else
    {
        int l=maxi->first-N/2;
        if(f(maxi->second)>=l)
            ans[u]=1;
    }
    for(auto& v: adj[u]) if(v!=p)
    {
        moveroot(u, v);
        dfs2(v, u);
        moveroot(v, u);
    }
}

int main()
{
    scanf("%d", &N);
    int a, b;
    for(int i=0; i<N-1; i++)
    {
        scanf("%d%d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1, 1);
    dfs2(1, 1);
    for(int i=1; i<=N; i++)
        printf("%d%c", ans[i], " \n"[i==N]);
    return 0;
}