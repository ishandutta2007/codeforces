#include <bits/stdc++.h>

using namespace std;

int N, M;
int ea[100001], eb[100001];
int in[100001];
vector<int> adj[100001];
int seen[100001];

int dfs(int u)
{
    if(seen[u]!=-1)
        return seen[u];
    int ret=0;
    for(auto& v: adj[u])
        ret=max(ret, dfs(v)+1);
    return seen[u]=ret;
}

bool solve(int m)
{
    for(int i=1; i<=N; i++)
    {
        in[i]=0;
        adj[i].clear();
        seen[i]=-1;
    }
    for(int i=0; i<m; i++)
    {
        in[eb[i]]++;
        adj[ea[i]].push_back(eb[i]);
    }
    int root=-1;
    for(int i=1; i<=N; i++) if(in[i]==0)
    {
        if(root==-1)
            root=i;
        else
            return false;
    }
    if(root==-1)
        return false;
    return dfs(root)==N-1;
}

int main()
{
    scanf("%d%d", &N, &M);
    for(int i=0; i<M; i++)
        scanf("%d%d", ea+i, eb+i);
    solve(4);
    int lo=1, mid, hi=M+1;
    while(lo<hi)
    {
        mid=(lo+hi)/2;
        if(solve(mid))
            hi=mid;
        else
            lo=mid+1;
    }
    if(lo==M+1)
        printf("-1\n");
    else
        printf("%d\n", lo);
    return 0;
}