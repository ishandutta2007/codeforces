#include <bits/stdc++.h>

using namespace std;

int N, M, Q;
vector<int> adj[300001];
int parent[300001];
int center[300001];
int diam[300001];
int radius[300001];
int path[300001];
bool seen[300001];

int find(int u)
{
    if(u!=parent[u])
        parent[u]=find(parent[u]);
    return parent[u];
}

void uni(int u, int v)
{
    u=find(u);
    v=find(v);
    if(u==v)
        return;
    parent[u]=parent[v];
    int ru=radius[u], rv=radius[v];
    int fd=max(max(diam[u], diam[v]), ru+rv+1), fc, fr;
    radius[u]=max(radius[u], rv+1);
    radius[v]=max(radius[v], ru+1);
    if(radius[u]<radius[v])
        fc=u, fr=radius[u];
    else
        fc=v, fr=radius[v];
    diam[find(u)]=fd;
    center[find(u)]=fc;
    radius[find(u)]=fr;
}

pair<int, int> dfs(int u, int p)
{
    seen[u]=true;
    pair<int, int> ret=make_pair(0, u);
    for(auto v: adj[u])
        if(v!=p)
        {
            auto r=dfs(v, u);
            if(r.first+1>ret.first)
            {
                ret.first=r.first+1;
                ret.second=r.second;
                path[u]=v;
            }
        }
    return ret;
}

int main()
{
    //freopen("in.txt", "r", stdin);
    scanf("%d%d%d", &N, &M, &Q);
    for(int i=1; i<=N; i++)
        parent[i]=i;
    int a, b, c;
    for(int i=0; i<M; i++)
    {
        scanf("%d%d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
        parent[find(a)]=parent[find(b)];
    }
    for(int i=1; i<=N; i++)
        if(!seen[i])
        {
            auto r1=dfs(i, -1);
            auto r2=dfs(r1.second, -1);
            diam[find(i)]=r2.first;
            int d1=0, d2=r2.first;
            int u=r1.second;
            while(d1<d2)
                u=path[u], d1++, d2--;
            center[find(i)]=u;
            radius[find(i)]=max(d1, d2);
        }
    for(int i=0; i<Q; i++)
    {
        scanf("%d%d", &a, &b);
        if(a==1)
            printf("%d\n", diam[find(b)]);
        else
        {
            scanf("%d", &c);
            uni(b, c);
        }
    }
    return 0;
}