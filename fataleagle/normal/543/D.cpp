#include <bits/stdc++.h>

using namespace std;

const int MOD=1000000007;
int N;
vector<int> adj[200001];
vector<int> L[200001];
vector<int> R[200001];
int dp[200001];
int ans[200001];

inline void addmod(int& x, int v)
{
    x+=v;
    if(x>=MOD)
        x-=MOD;
}

void dfs(int u, int p)
{
    for(auto& v: adj[u]) if(v!=p)
        dfs(v, u);
    dp[u]=1;
    L[u].resize(adj[u].size());
    R[u].resize(adj[u].size());
    int tmp=1;
    for(size_t i=0; i<adj[u].size(); i++)
    {
        int v=adj[u][i];
        if(v==p)
        {
            if(i==0)
                L[u][i]=1;
            else
                L[u][i]=L[u][i-1];
            continue;
        }
        tmp=1LL*tmp*(dp[v]+1)%MOD;
        L[u][i]=tmp;
    }
    tmp=1;
    for(int i=adj[u].size()-1; i>=0; i--)
    {
        int v=adj[u][i];
        if(v==p)
        {
            if(i==(int)adj[u].size()-1)
                R[u][i]=1;
            else
                R[u][i]=R[u][i+1];
            continue;
        }
        tmp=1LL*tmp*(dp[v]+1)%MOD;
        R[u][i]=tmp;
    }
    dp[u]=R[u][0];
}

void dfs2(int u, int p, int x)
{
    ans[u]=dp[u];
    for(size_t i=0; i<adj[u].size(); i++)
    {
        int v=adj[u][i];
        if(v==p)
            continue;
        int tmpu=dp[u];
        int tmpv=dp[v];
        dp[u]=1LL*(i?L[u][i-1]:1)*(i+1<adj[u].size()?R[u][i+1]:1)%MOD*x%MOD;
        dp[v]=1LL*dp[v]*(dp[u]+1)%MOD;
        dfs2(v, u, dp[u]+1);
        dp[u]=tmpu;
        dp[v]=tmpv;
    }
}

int main()
{
    scanf("%d", &N);
    int a;
    for(int i=2; i<=N; i++)
    {
        scanf("%d", &a);
        adj[a].push_back(i);
        adj[i].push_back(a);
    }
    dfs(1, -1);
    dfs2(1, -1, 1);
    for(int i=1; i<=N; i++)
        printf("%d%c", ans[i], " \n"[i==N]);
    return 0;
}