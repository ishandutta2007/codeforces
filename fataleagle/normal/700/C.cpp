#include <bits/stdc++.h>

using namespace std;

struct edge
{
    int u, v, c;
} edges[30000];

struct e
{
    int v, c, i;
};

int N, M;
int S, T;
vector<e> adj[1001];
vector<e> adj2[1001];
bool seen[1001];
int pre[1001];
int val[1001];
int P[1001];
bool used[30000];
int V[1001];
int dep[1001];
int idx[1001];
int idx2[1001];
int F[10][1001];
int mark[1001];
vector<int> gans;

int find(int u)
{
    if(u!=P[u])
        P[u]=find(P[u]);
    return P[u];
}

int merge(int u, int v)
{
    u=find(u), v=find(v);
    if(u==v)
        return 0;
    P[u]=v;
    return 1;
}

void dfs(int u, int p)
{
    F[0][u]=p;
    for(int i=1; i<=9; i++)
        F[i][u]=F[i-1][F[i-1][u]];
    for(auto& it: adj2[u])
    {
        int v=it.v, c=it.c, i=it.i;
        if(v==p)
            continue;
        dep[v]=dep[u]+1;
        idx2[v]=i;
        dfs(v, u);
        V[v]=c;
    }
}

int lca(int u, int v)
{
    if(dep[u]<dep[v])
        swap(u, v);
    for(int i=9; i>=0; i--) if(dep[F[i][u]]>=dep[v])
        u=F[i][u];
    if(u==v)
        return u;
    for(int i=9; i>=0; i--) if(F[i][u]!=F[i][v])
        u=F[i][u], v=F[i][v];
    return F[0][u];
}

void dfs2(int u, int p)
{
    for(auto& it: adj2[u])
    {
        int v=it.v, c=it.c, i=it.i;
        if(v==p)
            continue;
        dfs2(v, u);
        mark[u]+=mark[v];
    }
}

long long solve(int ridx)
{
    for(int i=1; i<=N; i++)
        P[i]=i, adj2[i].clear(), mark[i]=0;
    for(int i=0; i<M; i++)
        used[i]=false;
    for(int i=0; i<M; i++)
    {
        int u=edges[i].u, v=edges[i].v, c=edges[i].c;
        if(i==ridx)
        {
            used[i]=true;
            continue;
        }
        if(merge(u, v))
        {
            used[i]=true;
            adj2[u].push_back({v, c, i});
            adj2[v].push_back({u, c, i});
        }
    }
    if(find(S)!=find(T))
        return 0;
    dep[S]=0;
    dfs(S, S);
    for(int i=0; i<M; i++) if(!used[i])
    {
        int u=edges[i].u, v=edges[i].v;
        if(find(u)!=find(S))
            continue;
        int w=lca(u, v);
        mark[u]++;
        mark[v]++;
        mark[w]-=2;
    }
    dfs2(S, S);
    long long ret=0x3f3f3f3f3f3f3f3fLL;
    int ret2=-1;
    int x=T;
    while(x!=S)
    {
        if(mark[x]==0)
        {
            if(V[x]<ret)
            {
                ret=V[x];
                ret2=idx2[x];
            }
        }
        x=F[0][x];
    }
    gans.push_back(ret2);
    return ret;
}

int main()
{
    scanf("%d%d", &N, &M);
    scanf("%d%d", &S, &T);
    int a, b, c;
    for(int i=0; i<M; i++)
    {
        scanf("%d%d%d", &a, &b, &c);
        adj[a].push_back({b, c, i});
        adj[b].push_back({a, c, i});
        edges[i]=(edge){a, b, c};
    }
    queue<int> Q;
    Q.push(S);
    seen[S]=true;
    while(!Q.empty())
    {
        int u=Q.front();
        Q.pop();
        for(auto& it: adj[u])
        {
            int v=it.v, c=it.c, i=it.i;
            if(!seen[v])
            {
                seen[v]=true;
                pre[v]=u;
                val[v]=c;
                idx[v]=i;
                Q.push(v);
            }
        }
    }
    if(!seen[T])
    {
        printf("0\n0\n\n");
        return 0;
    }
    long long ans=0x3f3f3f3f3f3f3f3fLL;
    vector<int> ans2;
    int x=T;
    while(x!=S)
    {
        gans.clear();
        gans.push_back(idx[x]);
        long long z=val[x]+solve(idx[x]);
        if(z<ans)
        {
            ans=z;
            ans2=gans;
        }
        x=pre[x];
    }
    if(ans>2100000000)
        printf("-1\n");
    else
    {
        printf("%lld\n", ans);
        printf("%d\n", (int)ans2.size());
        for(auto& it: ans2)
            printf("%d ", it+1);
        printf("\n");
    }
    return 0;
}