#include <bits/stdc++.h>

using namespace std;

struct rmq
{
    int seg[1<<19];
    void update(int idx, int begin, int end, int x, int v)
    {
        if(x<begin || end<x)
            return;
        if(begin==end)
            seg[idx]=v;
        else
        {
            int mid=(begin+end)/2;
            update(idx*2, begin, mid, x, v);
            update(idx*2+1, mid+1, end, x, v);
            seg[idx]=max(seg[idx*2], seg[idx*2+1]);
        }
    }
    int query(int idx, int begin, int end, int l, int r)
    {
        if(r<begin || end<l)
            return 0;
        if(l<=begin && end<=r)
            return seg[idx];
        int mid=(begin+end)/2;
        return max(query(idx*2, begin, mid, l, r),
                   query(idx*2+1, mid+1, end, l, r));
    }
} tree;

int N, M;
int A[200001];
int B[200001];
int C[200001];
int P[200001];
int fa[200001];
int ismst[200001];
vector<pair<int, int>> adj[200001];
int level[200001];
int sz[200001];
int son[200001];
int parent[200001];
int top[200001];
int newid[200001], nextid;

int find(int u)
{
    if(u==fa[u])
        return u;
    return fa[u]=find(fa[u]);
}

int merge(int u, int v)
{
    u=find(u), v=find(v);
    if(u==v)
        return 0;
    fa[u]=v;
    return 1;
}

void dfs(int u, int p)
{
    sz[u]=1;
    for(auto& v: adj[u]) if(v.first!=p)
    {
        parent[v.first]=u;
        level[v.first]=level[u]+1;
        dfs(v.first, u);
        sz[u]+=sz[v.first];
        if(sz[v.first]>sz[son[u]])
            son[u]=v.first;
    }
}

void dfs2(int u, int p)
{
    newid[u]=++nextid;
    if(son[parent[u]]==u)
        top[u]=top[parent[u]];
    else
        top[u]=u;
    if(son[u])
        dfs2(son[u], u);
    for(auto& v: adj[u]) if(v.first!=p)
    {
        if(v.first!=son[u])
            dfs2(v.first, u);
        tree.update(1, 1, N, newid[v.first], v.second);
    }
}

int hld_query(int u, int v)
{
    int ans=0;
    while(top[u]!=top[v])
    {
        if(level[top[u]]<level[top[v]])
            swap(u, v);
        ans=max(ans, tree.query(1, 1, N, newid[top[u]], newid[u]));
        u=parent[top[u]];
    }
    if(level[u]>level[v])
        swap(u, v);
    if(u==v)
        return ans;
    ans=max(ans, tree.query(1, 1, N, newid[son[u]], newid[v]));
    return ans;
}

int main()
{
    scanf("%d%d", &N, &M);
    for(int i=1; i<=N; i++)
        fa[i]=i;
    for(int i=1; i<=M; i++)
        scanf("%d%d%d", A+i, B+i, C+i), P[i]=i;
    sort(P+1, P+1+M, [](int a, int b) {
        return C[a]<C[b];
    });
    long long mst=0;
    for(int i=1; i<=M; i++)
    {
        if(merge(A[P[i]], B[P[i]]))
        {
            mst+=C[P[i]];
            ismst[P[i]]=1;
            adj[A[P[i]]].push_back({B[P[i]], C[P[i]]});
            adj[B[P[i]]].push_back({A[P[i]], C[P[i]]});
        }
    }
    dfs(1, 1);
    dfs2(1, 1);
    for(int i=1; i<=M; i++)
    {
        if(ismst[i])
            printf("%lld\n", mst);
        else
        {
            int x=hld_query(A[i], B[i]);
            printf("%lld\n", mst-x+C[i]);
        }
    }
    return 0;
}