#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> adj[200001];
int A[200001];
long long dp[200001][2];

void solve(int u)
{
    vector<long long> change;
    long long sum=0;
    for(auto& v: adj[u])
    {
        solve(v);
        sum+=dp[v][0];
        change.push_back(-dp[v][0]+dp[v][1]);
    }
    sort(change.begin(), change.end());
    dp[u][0]=sum;
    while(change.size()>=2)
    {
        sum+=change.back();
        change.pop_back();
        dp[u][1]=max(dp[u][1], sum);
        sum+=change.back();
        change.pop_back();
        dp[u][0]=max(dp[u][0], sum);
    }
    while(change.size()>=1)
    {
        sum+=change.back();
        change.pop_back();
        dp[u][1]=max(dp[u][1], sum);
        if(!change.empty())
        {
            sum+=change.back();
            change.pop_back();
        }
    }
    dp[u][1]=max(dp[u][1], dp[u][0]+A[u]);
}

int main()
{
    scanf("%d", &N);
    int a, b;
    for(int i=1; i<=N; i++)
    {
        scanf("%d%d", &a, &b);
        if(a!=-1)
            adj[a].push_back(i);
        A[i]=b;
    }
    solve(1);
    printf("%lld\n", max(dp[1][0], dp[1][1]));
    return 0;
}