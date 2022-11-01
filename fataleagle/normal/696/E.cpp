#include <bits/stdc++.h>

using namespace std;

vector<pair<long long, int>> A[100001];

struct node
{
    pair<long long, int> val;
    long long lazy;
} seg[262144];

node combine(node a, node b)
{
    node c;
    c.val=min(a.val, b.val);
    c.lazy=0;
    return c;
}

void down(int idx)
{
    if(seg[idx].lazy)
    {
        seg[idx*2].val.first+=seg[idx].lazy;
        seg[idx*2].lazy+=seg[idx].lazy;
        seg[idx*2+1].val.first+=seg[idx].lazy;
        seg[idx*2+1].lazy+=seg[idx].lazy;
        seg[idx].lazy=0;
    }
}

void build(int idx, int begin, int end)
{
    if(begin==end)
        seg[idx].val=A[begin].back();
    else
    {
        int mid=(begin+end)/2;
        build(idx*2, begin, mid);
        build(idx*2+1, mid+1, end);
        seg[idx]=combine(seg[idx*2], seg[idx*2+1]);
    }
}

pair<long long, int> query(int idx, int begin, int end, int l, int r)
{
    if(r<begin || end<l)
        return make_pair(0x3f3f3f3f3f3f3f3fLL, -1);
    if(l<=begin && end<=r)
        return seg[idx].val;
    down(idx);
    int mid=(begin+end)/2;
    return min(query(idx*2, begin, mid, l, r),
               query(idx*2+1, mid+1, end, l, r));
}

void update(int idx, int begin, int end, int x)
{
    if(x<begin || end<x)
        return;
    if(begin==end)
    {
        A[begin].pop_back();
        seg[idx].val=A[begin].back();
        seg[idx].val.first+=seg[idx].lazy;
    }
    else
    {
        down(idx);
        int mid=(begin+end)/2;
        update(idx*2, begin, mid, x);
        update(idx*2+1, mid+1, end, x);
        seg[idx]=combine(seg[idx*2], seg[idx*2+1]);
    }
}

void update2(int idx, int begin, int end, int l, int r, int v)
{
    if(r<begin || end<l)
        return;
    if(l<=begin && end<=r)
    {
        seg[idx].val.first+=v;
        seg[idx].lazy+=v;
    }
    else
    {
        down(idx);
        int mid=(begin+end)/2;
        update2(idx*2, begin, mid, l, r, v);
        update2(idx*2+1, mid+1, end, l, r, v);
        seg[idx]=combine(seg[idx*2], seg[idx*2+1]);
    }
}

int N, M, Q;
vector<int> adj[100001];
int sz[300001];
int parent[300001];
int level[300001];
int son[300001];
int top[300001];
int newid[300001];
int nextid;
int endid[300001];
int loc[100001];

void dfs(int u, int p)
{
    sz[u]=1;
    for(auto& v: adj[u])
    {
        if(v==p)
            continue;
        parent[v]=u;
        level[v]=level[u]+1;
        dfs(v, u);
        sz[u]+=sz[v];
        if(sz[v]>sz[son[u]])
            son[u]=v;
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
    for(auto& v: adj[u])
    {
        if(v==p || v==son[u])
            continue;
        dfs2(v, u);
    }
    endid[u]=nextid;
}

void gen_path(vector<pair<int, int>>& ret, int u, int v)
{
    ret.clear();
    while(top[u]!=top[v])
    {
        if(level[top[u]]>level[top[v]])
        {
            ret.push_back({newid[top[u]], newid[u]});
            u=parent[top[u]];
        }
        else
        {
            ret.push_back({newid[top[v]], newid[v]});
            v=parent[top[v]];
        }
    }
    if(level[u]>level[v])
        ret.push_back({newid[v], newid[u]});
    else
        ret.push_back({newid[u], newid[v]});
}

int main()
{
    scanf("%d%d%d", &N, &M, &Q);
    for(int i=1; i<N; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1, 1);
    dfs2(1, 1);
    for(int i=0; i<M; i++)
    {
        int a;
        scanf("%d", &a);
        a=newid[a];
        loc[i]=a;
        A[a].push_back(make_pair(i, i));
    }
    for(int i=1; i<=N; i++)
        A[i].push_back({0x3f3f3f3f3f3f3f3fLL, -1});
    for(int i=1; i<=N; i++)
        sort(A[i].rbegin(), A[i].rend());
    build(1, 1, N);
    vector<pair<int, int>> p;
    vector<int> ans;
    while(Q--)
    {
        int t;
        scanf("%d", &t);
        if(t==1)
        {
            int u, v, k;
            scanf("%d%d%d", &u, &v, &k);
            gen_path(p, u, v);
            ans.clear();
            for(int i=0; i<k; i++)
            {
                pair<long long, int> girl={0x3f3f3f3f3f3f3f3fLL, -1};
                for(auto& it: p)
                    girl=min(girl, query(1, 1, N, it.first, it.second));
                if(girl.second==-1)
                    break;
                ans.push_back(girl.second);
                update(1, 1, N, loc[girl.second]);
            }
            printf("%d", ans.size());
            for(int i=0; i<(int)ans.size(); i++)
                printf(" %d", ans[i]+1);
            printf("\n");
        }
        else
        {
            int u, v;
            scanf("%d%d", &u, &v);
            update2(1, 1, N, newid[u], endid[u], v);
        }
    }
    return 0;
}