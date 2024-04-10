#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;
const int mod=998244353;
string s,t;
int n,m,dp[3001][3001],ans;
int main()
{
    cin>>s>>t;
    n=s.length();
    m=t.length();
    while(t.length()<s.length())
        t.push_back('?');
    s=" "+s;
    t=" "+t;
    for(int i=1;i<=n;++i)
    {
        dp[i][i]=(t[i]=='?'||s[1]==t[i])<<1;
        if(i==1&&m==1)
            ans=(ans+dp[i][i])%mod;
    }
    for(int len=2;len<=n;++len)
        for(int i=1,j=len;j<=n;++i,++j)
        {
            if(t[i]=='?'||s[len]==t[i])
                dp[i][j]=(dp[i][j]+dp[i+1][j])%mod;
            if(t[j]=='?'||s[len]==t[j])
                dp[i][j]=(dp[i][j]+dp[i][j-1])%mod;
            if(i==1&&j>=m)
                ans=(ans+dp[i][j])%mod;
        }
    cout<<ans<<endl;
    return 0;
}