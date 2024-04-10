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
#define MOD 1000000007
int a[1111],dp[1111],n; 
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)
    {
        dp[i+1]=(2*dp[i]+2-dp[a[i]])%MOD;
        if(dp[i+1]<0)dp[i+1]+=MOD;
    }
    cout<<dp[n+1];
//  system("pause");
     return 0;
}