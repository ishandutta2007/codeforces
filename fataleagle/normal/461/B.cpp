#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

const int MOD=1000000007;
int N;
int A[100000];
vector<int> adj[100000];
int dp[100000][2];

void dfs(int u)
{
    if(A[u]==1)
        dp[u][0]=0, dp[u][1]=1;
    else
        dp[u][0]=1, dp[u][1]=0;
    int sum=dp[u][1], tmp=dp[u][0];
    for(auto& v: adj[u])
    {
        dfs(v);
        dp[u][0]=1LL*dp[u][0]*(dp[v][0]+dp[v][1])%MOD;
        if(A[u]==1)
            sum=1LL*sum*(dp[v][0]+dp[v][1])%MOD;
        else
        {
            sum=(1LL*sum*(dp[v][0]+dp[v][1])+1LL*tmp*dp[v][1])%MOD;
            tmp=1LL*tmp*(dp[v][0]+dp[v][1])%MOD;
        }
    }
    dp[u][1]=sum;
}

int main()
{
    scanf("%d", &N);
    int a;
    for(int i=1; i<N; i++)
    {
        scanf("%d", &a);
        adj[a].push_back(i);
    }
    for(int i=0; i<N; i++)
        scanf("%d", A+i);
    dfs(0);
    printf("%d\n", dp[0][1]);
    return 0;
}