#include <bits/stdc++.h>

using namespace std;

const int MOD=1000000007;
int N, K;
int A[1000];
int sz[1000];
int C[1001][1001];
vector<int> adj[1001];

int solve(int u)
{
    sz[u]=1;
    int ret=1;
    for(auto& v: adj[u])
    {
        int res=solve(v);
        sz[u]+=sz[v];
        ret=1LL*ret*res%MOD*C[sz[u]-1][sz[v]]%MOD;
    }
    return ret;
}

int main()
{
    for(int i=0; i<=1000; i++)
    {
        C[i][0]=1;
        for(int j=1; j<=i; j++)
            C[i][j]=(C[i-1][j]+C[i-1][j-1])%MOD;
    }
    scanf("%d", &K);
    int a;
    for(int i=0; i<K; i++)
    {
        scanf("%d", &a);
        for(int j=0; j<a-1; j++)
            adj[N+1].push_back(N), N++;
        A[i]=N++;
    }
    for(int i=1; i<K; i++)
        adj[A[i]].push_back(A[i-1]);
    printf("%d\n", solve(A[K-1]));
    return 0;
}