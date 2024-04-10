#include <bits/stdc++.h>

using namespace std;

struct dsu
{
    int parent[200001];
    dsu()
    {
        for(int i=0; i<200001; i++)
            parent[i]=i;
    }
    int find(int u)
    {
        if(u!=parent[u])
            parent[u]=find(parent[u]);
        return parent[u];
    }
    bool merge(int u, int v)
    {
        u=find(u), v=find(v);
        if(u==v)
            return false;
        parent[u]=v;
        return true;
    }
} ds1, ds2, ds3;

int N, M, Q;
vector<int> adj[200001];
vector<int> adj2[200001];
vector<pair<int, int>> extra;
int P[18][200001];
int mark[200001];
int markA[200001];
int markB[200001];
int level[200001];
map<int, int> newid;
int nextid;
bool seen[200001];

int get_lca(int u, int v)
{
    if(level[u]<level[v])
        swap(u, v);
    for(int i=17; i>=0; i--) if(level[P[i][u]]>=level[v])
        u=P[i][u];
    if(u==v)
        return u;
    for(int i=17; i>=0; i--) if(P[i][u]!=P[i][v])
        u=P[i][u], v=P[i][v];
    return P[0][u];
}

void dfs(int u, int p)
{
    seen[u]=true;
    P[0][u]=p;
    for(int i=1; i<=17; i++)
        P[i][u]=P[i-1][P[i-1][u]];
    for(auto& v: adj[u]) if(v!=p)
    {
        level[v]=level[u]+1;
        dfs(v, u);
    }
}

int dfs2(int u, int p)
{
    for(auto& v: adj[u]) if(v!=p)
        mark[u]+=dfs2(v, u);
    return mark[u];
}

void dfs3(int u, int p)
{
    seen[u]=true;
    P[0][u]=p;
    for(int i=1; i<=17; i++)
        P[i][u]=P[i-1][P[i-1][u]];
    for(auto& v: adj2[u]) if(v!=p)
    {
        level[v]=level[u]+1;
        dfs3(v, u);
    }
}

void dfs4(int u, int p)
{
    for(auto& v: adj2[u]) if(v!=p)
    {
        dfs4(v, u);
        markA[u]+=markA[v];
        markB[u]+=markB[v];
    }
}

int main()
{
    scanf("%d%d%d", &N, &M, &Q);
    int a, b;
    for(int i=0; i<M; i++)
    {
        scanf("%d%d", &a, &b);
        ds3.merge(a, b);
        if(ds1.merge(a, b))
        {
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        else
            extra.push_back({a, b});
    }
    for(int i=1; i<=N; i++) if(!seen[i])
        dfs(i, i);
    for(auto& it: extra)
    {
        int l=get_lca(it.first, it.second);
        mark[it.first]++;
        mark[it.second]++;
        mark[l]-=2;
    }
    for(int i=1; i<=N; i++) if(P[0][i]==i)
        dfs2(i, i);
    for(int i=1; i<=N; i++)
        if(mark[i])
            ds2.merge(i, P[0][i]);
    for(int i=1; i<=N; i++)
    {
        int u=ds2.find(i);
        if(!newid.count(u))
            newid[u]=++nextid;
    }
    for(int i=1; i<=N; i++)
        if(!mark[i])
        {
            int u=newid[ds2.find(i)];
            int v=newid[ds2.find(P[0][i])];
            adj2[u].push_back(v);
            adj2[v].push_back(u);
        }
    memset(seen, 0, sizeof seen);
    for(int i=1; i<=nextid; i++) if(!seen[i])
        dfs3(i, i);
    for(int i=0; i<Q; i++)
    {
        scanf("%d%d", &a, &b);
        if(ds3.find(a)!=ds3.find(b))
        {
            printf("No\n");
            return 0;
        }
        a=newid[ds2.find(a)];
        b=newid[ds2.find(b)];
        int l=get_lca(a, b);
        markA[a]++;
        markA[l]--;
        markB[b]++;
        markB[l]--;
    }
    for(int i=1; i<=nextid; i++) if(P[0][i]==i)
        dfs4(i, i);
    for(int i=1; i<=nextid; i++) if(markA[i] && markB[i])
    {
        printf("No\n");
        return 0;
    }
    printf("Yes\n");
    return 0;
}