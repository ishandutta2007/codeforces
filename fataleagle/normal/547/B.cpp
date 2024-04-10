#include <bits/stdc++.h>

using namespace std;

int N;
int A[300000];
int sz[300000];
int parent[300000];
int maxi[300000];

int find(int u)
{
    if(u!=parent[u])
        parent[u]=find(parent[u]);
    return parent[u];
}

void merge(int u, int v)
{
    u=find(u);
    v=find(v);
    if(u==v)
        return;
    sz[u]+=sz[v];
    parent[v]=u;
}

int main()
{
    scanf("%d", &N);
    vector<pair<int, int>> order;
    for(int i=1; i<=N; i++)
        scanf("%d", A+i), parent[i]=i, sz[i]=1, order.push_back({A[i], i});
    sort(order.rbegin(), order.rend());
    for(auto& it: order)
    {
        int idx=it.second;
        if(idx>1 && A[idx-1]>=A[idx])
            merge(idx-1, idx);
        if(idx<N && A[idx+1]>=A[idx])
            merge(idx, idx+1);
        int x=find(idx);
        maxi[sz[x]]=max(maxi[sz[x]], A[idx]);
    }
    for(int i=N-1; i>=1; i--)
        maxi[i]=max(maxi[i], maxi[i+1]);
    for(int i=1; i<=N; i++)
        printf("%d%c", maxi[i], " \n"[i==N]);
    return 0;
}