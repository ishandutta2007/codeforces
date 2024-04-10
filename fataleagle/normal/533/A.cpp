#include <iostream>
#include <algorithm>
#include <cstdio>
#include <set>
#include <vector>
#include <cassert>

using namespace std;

int N, M;
int A[500001];
int B[500001];
vector<int> adj[500001];
int X[500001];
pair<int, int> order[500001];
int join[500001];
vector<pair<pair<int, int>, int>> intervals;
vector<int> adj2[500001];

struct dsu
{
    int parent[500001];
    int sz[500001];
    vector<int> actual[500001];
    dsu()
    {
        for(int i=0; i<500001; i++)
            parent[i]=i, sz[i]=1, actual[i].push_back(i);
    }
    int find(int u)
    {
        if(parent[u]!=u)
            parent[u]=find(parent[u]);
        return parent[u];
    }
    void merge(int u, int v, int now)
    {
        u=find(u);
        v=find(v);
        if(u==v)
            return;
        if(v==find(0))
            swap(u, v);
        if(u==find(0))
            for(auto& it: actual[v])
            {
                assert(join[it]==M+1);
                join[it]=now;
            }
        if(actual[u].size()<actual[v].size())
            actual[u].swap(actual[v]);
        for(auto& it: actual[v])
            actual[u].push_back(it);
        actual[v].clear();
        sz[u]+=sz[v];
        parent[v]=u;
    }
} ds, ds2;

int seg[1<<20];
int lazy[1<<20];

void init(int idx, int begin, int end)
{
    if(begin==end)
        seg[idx]=X[begin];
    else
    {
        int mid=(begin+end)/2;
        init(idx*2, begin, mid);
        init(idx*2+1, mid+1, end);
        seg[idx]=min(seg[idx*2], seg[idx*2+1]);
    }
}

void down(int idx)
{
    if(lazy[idx])
    {
        seg[idx*2]+=lazy[idx];
        lazy[idx*2]+=lazy[idx];
        seg[idx*2+1]+=lazy[idx];
        lazy[idx*2+1]+=lazy[idx];
        lazy[idx]=0;
    }
}

void update(int idx, int begin, int end, int l, int r, int v)
{
    if(r<begin || end<l)
        return;
    if(l<=begin && end<=r)
    {
        seg[idx]+=v;
        lazy[idx]+=v;
    }
    else
    {
        down(idx);
        int mid=(begin+end)/2;
        update(idx*2, begin, mid, l, r, v);
        update(idx*2+1, mid+1, end, l, r, v);
        seg[idx]=min(seg[idx*2], seg[idx*2+1]);
    }
}

void dfs(int u, int p, int mini)
{
    int l=lower_bound(B+1, B+M+1, A[u], greater<int>())-B;
    mini=max(mini, l);
    if(mini<join[u])
        intervals.push_back({{mini, join[u]-1}, ds2.sz[u]});
    for(auto& v: adj2[u]) if(v!=p)
        dfs(v, u, mini);
}

int main()
{
    scanf("%d", &N);
    for(int i=1; i<=N; i++)
        scanf("%d", A+i), order[i]=make_pair(A[i], i);
    int a, b;
    for(int i=1; i<N; i++)
    {
        scanf("%d%d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    adj[0].push_back(1);
    adj[1].push_back(0);
    A[0]=0x3f3f3f3f;
    order[0]=make_pair(A[0], 0);
    ds.sz[0]=0;
    scanf("%d", &M);
    for(int i=1; i<=M; i++)
        scanf("%d", B+i);
    for(int i=1; i<=N; i++)
        join[i]=M+1;
    sort(order, order+1+N, greater<pair<int, int>>());
    sort(B+1, B+1+M, greater<int>());
    int pos=1;
    int first=M+1;
    for(int i=1; i<=M; i++)
    {
        while(pos<=N && B[i]<=order[pos].first)
        {
            int u=order[pos].second;
            for(auto& v: adj[u]) if(B[i]<=A[v])
                ds.merge(u, v, i);
            pos++;
        }
        X[i]=ds.sz[ds.find(0)]-i;
        if(X[i]<0 && first==M+1)
        {
            first=i;
            ds2=ds;
        }
    }
    if(first==M+1)
        return printf("0\n"), 0;
    for(int u=0; u<=N; u++)
        for(auto& v: adj[u]) if(ds2.find(u)!=ds2.find(v))
            adj2[ds2.find(u)].push_back(ds2.find(v));
    init(1, 1, M);
    int ans=0x3f3f3f3f;
    for(auto& u: adj2[ds2.find(0)])
    {
        assert(A[u]<B[first]);
        assert(ds2.sz[ds2.find(u)]==1);
        assert(ds2.find(u)!=ds2.find(0));
        intervals.clear();
        int inc=B[first]-A[u];
        A[u]+=inc;
        dfs(u, ds2.find(0), -0x3f3f3f3f);
        A[u]-=inc;
        for(auto& it: intervals)
            update(1, 1, M, it.first.first, it.first.second, it.second);
        if(seg[1]>=0)
            ans=min(ans, inc);
        for(auto& it: intervals)
            update(1, 1, M, it.first.first, it.first.second, -it.second);
    }
    if(ans==0x3f3f3f3f)
        printf("-1\n");
    else
        printf("%d\n", ans);
    return 0;
}