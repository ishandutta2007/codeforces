#include <bits/stdc++.h>

using namespace std;

int N, x, y;
int deg[200001];
vector<int> adj[200001];
int dp[200001][2]; // free, not free

void solve(int u, int p)
{
    vector<int> change;
    int sum=0;
    for(auto& v: adj[u]) if(v!=p)
    {
        solve(v, u);
        sum+=dp[v][1]+1;
        change.push_back(dp[v][0]-dp[v][1]);
    }
    dp[u][0]=dp[u][1]=sum;
    sort(change.begin(), change.end());
    if(change.size()>=1)
        dp[u][0]=min(dp[u][0], dp[u][0]-1+change[0]);
    if(change.size()>=2)
        dp[u][1]=min(dp[u][1], dp[u][1]-2+change[0]+change[1]);
    dp[u][1]=min(dp[u][1], dp[u][0]);
}

int main()
{
    scanf("%d%d%d", &N, &x, &y);
    int a, b;
    for(int i=0; i<N-1; i++)
    {
        scanf("%d%d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
        deg[a]++;
        deg[b]++;
    }
    if(x==y)
        printf("%lld\n", 1LL*x*(N-1));
    else if(x>y)
    {
        bool star=false;
        for(int i=1; i<=N; i++) if(deg[i]==N-1)
            star=true;
        long long ans=1LL*y*(N-1);
        if(star)
            ans+=x-y;
        printf("%lld\n", ans);
    }
    else
    {
        solve(1, 1);
        printf("%lld\n", 1LL*(N-1)*x+1LL*dp[1][1]*(y-x));
    }
    return 0;
}