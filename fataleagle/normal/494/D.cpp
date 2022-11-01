#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

const int MOD=1000000007;
int N, Q;
vector<pair<int, int>> adj[100001];
size_t ppos[100001];
int sz[100001];
int sum[100001];
int sqsum[100001];
int depth[100001];
int dist[100001];
int start[100001];
int euler[200003], neuler;
int seg[524288];
vector<pair<int, int>> ask[100001];
int ans[100001];
int ans2[100001];
int u_i[100001];

inline bool cmpdepth(int a, int b)
{
    if(a==-1)
        return false;
    if(b==-1)
        return true;
    return depth[a]<depth[b];
}

void init(int idx, int begin, int end)
{
    if(begin==end)
        seg[idx]=euler[begin];
    else
    {
        int mid=(begin+end)/2;
        init(idx*2, begin, mid);
        init(idx*2+1, mid+1, end);
        seg[idx]=min(seg[idx*2], seg[idx*2+1], cmpdepth);
    }
}

int query(int idx, int begin, int end, int i, int j)
{
    if(j<begin || end<i)
        return -1;
    if(i<=begin && end<=j)
        return seg[idx];
    int mid=(begin+end)/2;
    return min(query(idx*2, begin, mid, i, j),
               query(idx*2+1, mid+1, end, i, j), cmpdepth);
}

void dfs(int u, int p)
{
    sz[u]=1;
    euler[++neuler]=u;
    start[u]=neuler;
    for(size_t i=0; i<adj[u].size(); i++)
    {
        int v=adj[u][i].first;
        int c=adj[u][i].second;
        if(v==p)
        {
            ppos[u]=i;
            continue;
        }
        depth[v]=depth[u]+1;
        dist[v]=(dist[u]+c)%MOD;
        dfs(v, u);
        sz[u]+=sz[v];
        sum[u]=(sum[u]+1LL*c*sz[v]%MOD)%MOD;
        sum[u]=(sum[u]+sum[v])%MOD;
        sqsum[u]=(sqsum[u]+1LL*c*c%MOD*sz[v]%MOD)%MOD;
        sqsum[u]=(sqsum[u]+2LL*c*sum[v]%MOD)%MOD;
        sqsum[u]=(sqsum[u]+sqsum[v])%MOD;
        euler[++neuler]=u;
    }
}

void moveroot(int u, int v, int c)
{
    sz[u]-=sz[v];
    sum[u]=(sum[u]-1LL*c*sz[v]%MOD+MOD)%MOD;
    sum[u]=(sum[u]-sum[v]+MOD)%MOD;
    sqsum[u]=(sqsum[u]-1LL*c*c%MOD*sz[v]%MOD+MOD)%MOD;
    sqsum[u]=(sqsum[u]-2LL*c*sum[v]%MOD+MOD)%MOD;
    sqsum[u]=(sqsum[u]-sqsum[v]+MOD)%MOD;
    sz[v]+=sz[u];
    sum[v]=(sum[v]+1LL*c*sz[u]%MOD)%MOD;
    sum[v]=(sum[v]+sum[u])%MOD;
    sqsum[v]=(sqsum[v]+1LL*c*c%MOD*sz[u]%MOD)%MOD;
    sqsum[v]=(sqsum[v]+2LL*c*sum[u]%MOD)%MOD;
    sqsum[v]=(sqsum[v]+sqsum[u])%MOD;
}

void dfs2(int u, int p)
{
    ans2[u]=sqsum[u];
    for(auto& it: ask[u])
    {
        int v=it.first;
        int idx=it.second;
        int dab=ans[idx];
        ans[idx]=sqsum[u];
        if(v==1)
            continue;
        int w=adj[v][ppos[v]].first;
        dab=(dab+adj[v][ppos[v]].second)%MOD;
        ans[idx]=(ans[idx]-1LL*dab*dab%MOD*sz[w]%MOD+MOD)%MOD;
        ans[idx]=(ans[idx]-2LL*dab*sum[w]%MOD+MOD)%MOD;
        ans[idx]=(ans[idx]-sqsum[w]+MOD)%MOD;
    }
    for(size_t i=0; i<adj[u].size(); i++)
    {
        int v=adj[u][i].first;
        int c=adj[u][i].second;
        if(v==p)
            continue;
        moveroot(u, v, c);
        dfs2(v, u);
        moveroot(v, u, c);
    }
}

int main()
{
    scanf("%d", &N);
    int a, b, c;
    for(int i=1; i<N; i++)
    {
        scanf("%d%d%d", &a, &b, &c);
        adj[a].push_back(make_pair(b, c));
        adj[b].push_back(make_pair(a, c));
    }
    dfs(1, -1);
    init(1, 1, neuler);
    scanf("%d", &Q);
    for(int i=1; i<=Q; i++)
    {
        scanf("%d%d", &a, &b);
        u_i[i]=a;
        int lca=query(1, 1, neuler, min(start[a], start[b]), max(start[a], start[b]));
        int dab=(dist[a]+dist[b])%MOD;
        dab=(dab-2LL*dist[lca]%MOD+MOD)%MOD;
        if(lca==b)
        {
            ask[a].push_back(make_pair(b, i));
            ans[i]=dab;
        }
        else
        {
            ans[i]=1LL*dab*dab%MOD*sz[b]%MOD;
            ans[i]=(ans[i]+2LL*dab*sum[b]%MOD)%MOD;
            ans[i]=(ans[i]+sqsum[b])%MOD;
        }
    }
    dfs2(1, -1);
    for(int i=1; i<=Q; i++)
        printf("%d\n", (ans[i]-(ans2[u_i[i]]-ans[i]+MOD)%MOD+MOD)%MOD);
    return 0;
}