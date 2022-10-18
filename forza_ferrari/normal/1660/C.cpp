#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
int t,n,dp[200001][27];
string s;
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>s;
        n=s.length();
        s=" "+s;
        for(int i=0;i<=n;++i)
            for(int j=0;j<=26;++j)
                dp[i][j]=1e9;
        dp[0][0]=0;
        for(int i=0;i<n;++i)
            for(int j=0;j<=26;++j)
                if(dp[i][j]<1e9)
                    if(j==0)
                    {
                        dp[i+1][s[i+1]-'a'+1]=min(dp[i+1][s[i+1]-'a'+1],dp[i][j]);
                        dp[i+1][0]=min(dp[i+1][0],dp[i][j]+1);
                    }
                    else
                    {
                        if(s[i+1]-'a'+1==j)
                            dp[i+1][0]=min(dp[i+1][0],dp[i][j]);
                        dp[i+1][j]=min(dp[i+1][j],dp[i][j]+1);
                    }
        cout<<dp[n][0]<<'\n';
    }
    return 0;
}