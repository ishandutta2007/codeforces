#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> adj[200001];
int leaves[200001];

// the x-th ranked is the best we can do if current player is cp
int god_maximize(int u, int cp)
{
    if(adj[u].empty())
    {
        leaves[u]=1;
        return 1;
    }
    leaves[u]=0;
    vector<int> possible;
    for(auto& v: adj[u])
    {
        possible.push_back(god_maximize(v, cp^1));
        leaves[u]+=leaves[v];
    }
    if(cp==0)
    {
        // share the same goal so we can maximize
        int ret=0;
        for(size_t i=0; i<adj[u].size(); i++)
        {
            int v=adj[u][i], p=possible[i];
            ret=max(ret, leaves[u]-leaves[v]+p);
        }
        return ret;
    }
    int waste=0;
    for(auto& it: possible)
        waste+=it-1;
    return waste+1;
}

// the x-th ranked is the best we can do if current player is cp
int god_minimize(int u, int cp)
{
    if(adj[u].empty())
    {
        leaves[u]=1;
        return 1;
    }
    leaves[u]=0;
    vector<int> possible;
    for(auto& v: adj[u])
    {
        possible.push_back(god_minimize(v, cp^1));
        leaves[u]+=leaves[v];
    }
    if(cp==1)
    {
        // share the same goal so we can minimize
        int ret=0x3f3f3f3f;
        for(size_t i=0; i<adj[u].size(); i++)
        {
            int p=possible[i];
            ret=min(ret, p);
        }
        return ret;
    }
    // distribute numbers from 1..leaves[u] so that maximum is small as possible
    // max from the one at the p_ith position from each child is small
    int waste=0;
    for(size_t i=0; i<adj[u].size(); i++)
    {
        int v=adj[u][i], p=possible[i];
        waste+=leaves[v]-p;
    }
    int limit=leaves[u]-waste;
    return limit;
}

int main()
{
    scanf("%d", &N);
    int a, b;
    for(int i=1; i<N; i++)
    {
        scanf("%d%d", &a, &b);
        adj[a].push_back(b);
    }
    printf("%d %d\n", god_maximize(1, 0), god_minimize(1, 0));
    return 0;
}