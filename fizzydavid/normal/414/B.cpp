#include<algorithm>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<string>
#include<ctime>
#include<utility>
#include<vector>
using namespace std;
#define ll long long
const int MOD=1000000007;
int dp[2111][2111];
ll cal(int n,int k)
{
    if(n==1)return 1;if(k==1)return n;
    if(dp[n][k]!=0)return dp[n][k];
    ll res=0;
    for(int i=1;i<=n;i++)res=(res+cal(n/i,k-1))%MOD;
    dp[n][k]=res;return res;
}
int main()
{
    int n,k;
    cin>>n>>k;
    cout<<cal(n,k);
    return 0;
}