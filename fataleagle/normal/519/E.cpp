#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<int> adj[100001];
int P[100001][18];
int level[100001];
int sz[100001];

void dfs(int u, int p)
{
    P[u][0]=p;
    for(int i=1; i<=17; i++)
        P[u][i]=P[P[u][i-1]][i-1];
    sz[u]=1;
    for(auto& v: adj[u])
    {
        if(v==p)
            continue;
        level[v]=level[u]+1;
        dfs(v, u);
        sz[u]+=sz[v];
    }
}

int lca(int u, int v)
{
    if(level[u]<level[v])
        swap(u, v);
    for(int i=17; i>=0; i--)
        if(level[P[u][i]]>=level[v])
            u=P[u][i];
    if(u==v)
        return u;
    for(int i=17; i>=0; i--)
        if(P[u][i]!=P[v][i])
            u=P[u][i], v=P[v][i];
    return P[u][0];
}

int dist(int u, int v)
{
    int c=lca(u, v);
    return level[u]+level[v]-2*level[c];
}

int get(int u, int d)
{
    for(int i=17; i>=0; i--)
        if(d>=(1<<i))
            u=P[u][i], d-=1<<i;
    return u;
}

bool onpath(int u, int v, int w)
{
    return dist(u, w)+dist(w, v)==dist(u, v);
}

int main()
{
    scanf("%d", &N);
    int a, b;
    for(int i=1; i<N; i++)
    {
        scanf("%d%d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1, 1);
    scanf("%d", &M);
    while(M--)
    {
        scanf("%d%d", &a, &b);
        if(level[a]<level[b])
            swap(a, b);
        int d=dist(a, b);
        if(d&1)
            printf("0\n");
        else
        {
            int u=get(a, d/2);
            int ans=0;
            if(d==0)
                ans=N;
            else if(level[a]==level[b])
            {
                ans+=N;
                ans-=sz[get(a, d/2-1)];
                ans-=sz[get(b, d/2-1)];
            }
            else
            {
                ans+=sz[u];
                ans-=sz[get(a, d/2-1)];
            }
            printf("%d\n", ans);
        }
    }
    return 0;
}