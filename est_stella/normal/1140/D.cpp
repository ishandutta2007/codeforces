#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    scanf("%d", &n);

    long long int dp[501];
    dp[3]=6;

    for(int i=4; i<=n; i++)
    {
        dp[i]=dp[i-1]+i*(i-1);
    }

    cout<<dp[n];
}