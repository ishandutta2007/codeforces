#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
#include <set>
#include <ctime>

#define ll long long

using namespace std;

int dp[1001][1001],mod=1000000007;

int solve(int n,int k)
{
    if (k==0) return 1;
    if (dp[n][k]!=-1) return dp[n][k];
    int ret=0;
    for(int l=2*k-1;l<=n-2;l++)
    {
        ret=(ret+1LL*(n-1-l)*solve(l,k-1))%mod;
    }
    return dp[n][k]=ret;
}

int main()
{
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int n,m,k;
    cin >> n >> m >> k;
    memset(dp,-1,sizeof(dp));
    cout << 1LL*solve(n,k)*solve(m,k)%mod << endl;
    return 0;
}