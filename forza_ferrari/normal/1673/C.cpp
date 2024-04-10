#include<iostream>
#include<cstdio>
using namespace std;
const int mod=1000000007;
int t,n,dp[40001];
inline bool check(int x)
{
    int y=0,tmp=x;
    while(tmp)
    {
        y=(y<<1)+(y<<3)+tmp%10;
        tmp/=10;
    }
    return x==y;
}
int main()
{
    dp[0]=1;
    for(int i=1;i<=40000;++i)
        if(check(i))
            for(int j=i;j<=40000;++j)
                dp[j]=(dp[j]+dp[j-i])%mod;
    cin>>t;
    while(t--)
    {
        cin>>n;
        cout<<dp[n]<<'\n';
    }
    return 0;
}