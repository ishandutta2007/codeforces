#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<int> adj[100001];
int P[17][100001];
int level[100001];
int sz[100001];
long long down[100001];
long long up[100001];

void dfs(int u, int p)
{
    P[0][u]=p;
    for(int i=1; i<=16; i++)
        P[i][u]=P[i-1][P[i-1][u]];
    sz[u]=1;
    for(auto& v: adj[u]) if(v!=p)
    {
        level[v]=level[u]+1;
        dfs(v, u);
        down[u]+=down[v]+sz[v];
        sz[u]+=sz[v];
    }
}

void dfs2(int u, int p)
{
    for(auto& v: adj[u]) if(v!=p)
    {
        up[v]=up[u]+down[u]-down[v]-sz[v]+N-sz[v];
        dfs2(v, u);
    }
}

int lca(int u, int v)
{
    if(level[u]<level[v])
        swap(u, v);
    for(int i=16; i>=0; i--) if(level[P[i][u]]>=level[v])
        u=P[i][u];
    if(u==v)
        return u;
    for(int i=16; i>=0; i--) if(P[i][u]!=P[i][v])
        u=P[i][u], v=P[i][v];
    return P[0][u];
}

int getprev(int u, int v)
{
    for(int i=16; i>=0; i--) if(level[P[i][u]]>level[v])
        u=P[i][u];
    return u;
}

int main()
{
    scanf("%d%d", &N, &M);
    int a, b;
    for(int i=0; i<N-1; i++)
    {
        scanf("%d%d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1, 1);
    dfs2(1, 1);
    for(int i=0; i<M; i++)
    {
        scanf("%d%d", &a, &b);
        if(level[a]<level[b])
            swap(a, b);
        int c=lca(a, b);
        if(c==b)
        {
            double ans=level[a]+level[b]-2*level[c]+(double)down[a]/sz[a]+1;
            int d=getprev(a, b);
            long long tmp=up[b]+down[b]-down[d]-sz[d];
            long long den=N-sz[d];
            ans+=(double)tmp/den;
            printf("%.9f\n", ans);
        }
        else
        {
            double ans=level[a]+level[b]-2*level[c]+(double)down[a]/sz[a]+(double)down[b]/sz[b]+1;
            printf("%.9f\n", ans);
        }
    }
    return 0;
}