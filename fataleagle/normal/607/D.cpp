#include <bits/stdc++.h>

using namespace std;

const int MOD=1000000007;
int N;
int V1, Q;
int op[200000];
int qa[200000];
int qb[200000];
int parent[200001];
vector<int> adj[200001];
int deg[200001];
int in[200001];
int out[200001];
int now;

int powmod(int a, int b)
{
    int ret=1;
    for(; b>0; b/=2)
    {
        if(b&1)
            ret=1LL*ret*a%MOD;
        a=1LL*a*a%MOD;
    }
    return ret;
}

int inv(int x)
{
    return powmod(x, MOD-2);
}

struct node
{
    int A, B, lazy;
} seg[1<<19];

void apply(int idx, int val)
{
    seg[idx].A=1LL*seg[idx].A*val%MOD;
    seg[idx].B=1LL*seg[idx].B*val%MOD;
    seg[idx].lazy=1LL*seg[idx].lazy*val%MOD;
}

void down(int idx)
{
    if(seg[idx].lazy!=1)
    {
        apply(idx*2, seg[idx].lazy);
        apply(idx*2+1, seg[idx].lazy);
        seg[idx].lazy=1;
    }
}

node combine(node a, node b)
{
    node c;
    c.A=(a.A+b.A)%MOD;
    c.B=(a.B+b.B)%MOD;
    c.lazy=1;
    return c;
}

void updateLabel(int idx, int begin, int end, int x, int v)
{
    if(x<begin || end<x)
        return;
    if(begin==end)
        seg[idx].A=1LL*v*seg[idx].B%MOD;
    else
    {
        down(idx);
        int mid=(begin+end)/2;
        updateLabel(idx*2, begin, mid, x, v);
        updateLabel(idx*2+1, mid+1, end, x, v);
        seg[idx]=combine(seg[idx*2], seg[idx*2+1]);
    }
}

void update(int idx, int begin, int end, int l, int r, int v)
{
    if(r<begin || end<l)
        return;
    if(l<=begin && end<=r)
        apply(idx, v);
    else
    {
        down(idx);
        int mid=(begin+end)/2;
        update(idx*2, begin, mid, l, r, v);
        update(idx*2+1, mid+1, end, l, r, v);
        seg[idx]=combine(seg[idx*2], seg[idx*2+1]);
    }
}

node query(int idx, int begin, int end, int l, int r)
{
    if(r<begin || end<l)
        return (node){0, 0, 1};
    if(l<=begin && end<=r)
        return seg[idx];
    down(idx);
    int mid=(begin+end)/2;
    return combine(query(idx*2, begin, mid, l, r),
                   query(idx*2+1, mid+1, end, l, r));
}

void build(int idx, int begin, int end)
{
    if(begin==end)
    {
        if(begin==1)
            seg[idx]=(node){V1, 1, 1};
        else
            seg[idx]=(node){0, 1, 1};
    }
    else
    {
        int mid=(begin+end)/2;
        build(idx*2, begin, mid);
        build(idx*2+1, mid+1, end);
        seg[idx]=combine(seg[idx*2], seg[idx*2+1]);
    }
}

void dfs(int u)
{
    in[u]=++now;
    for(auto& v: adj[u])
        dfs(v);
    out[u]=now;
}

int main()
{
    scanf("%d%d", &V1, &Q);
    N=1;
    for(int i=0; i<Q; i++)
    {
        scanf("%d", op+i);
        if(op[i]==1)
        {
            scanf("%d%d", qa+i, qb+i);
            N++;
            adj[qa[i]].push_back(N);
            parent[N]=qa[i];
            qa[i]=N;
        }
        else
            scanf("%d", qa+i);
    }
    dfs(1);
    build(1, 1, N);
    for(int i=1; i<=N; i++)
        deg[i]=1;
    for(int i=0; i<Q; i++)
    {
        if(op[i]==1)
        {
            int u=qa[i];
            int x=qb[i];
            int p=parent[u];
            updateLabel(1, 1, N, in[u], x);
            deg[p]++;
            update(1, 1, N, in[p], out[p], 1LL*deg[p]*inv(deg[p]-1)%MOD);
        }
        else
        {
            int u=qa[i];
            int p=parent[u];
            int bval=1;
            if(u!=1)
                bval=query(1, 1, N, in[p], in[p]).B;
            int ans=inv(bval);
            ans=1LL*ans*query(1, 1, N, in[u], out[u]).A%MOD;
            printf("%d\n", ans);
        }
    }
    return 0;
}