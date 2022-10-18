#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
using namespace std;
vector<int> dp[100005];
int n,m,pi[100005];
string s,t;
int main()
{
    cin>>s>>t;
    n=s.length();
    m=t.length();
    s=" "+s;
    t=" "+t;
    for(int i=2;i<=m;++i)
    {
        int j=pi[i-1];
        while(j>0&&t[i]!=t[j+1])
            j=pi[j];
        if(t[i]==t[j+1])
            ++j;
        pi[i]=j;
    }
    dp[0].resize(m+1);
    for(int i=1;i<=m;++i)
        dp[0][i]=-0x3f3f3f3f;
    for(int i=1;i<=n;++i)
    {
        dp[i].resize(m+1);
        dp[i][0]=max(dp[i-1][0],dp[i][0]);
        for(int j=1;j<=m;++j)
        {
            if(s[i]==t[j]||s[i]=='?')
            {
                dp[i][j]=dp[i-1][j-1];
                if(j==m)
                {
                    ++dp[i][j];
                    for(int k=m;k;k=pi[k])
                        dp[i][k]=max(dp[i][k],dp[i][j]);
                }
            }
            else
                dp[i][j]=-0x3f3f3f3f;
            dp[i][0]=max(dp[i][0],max(dp[i-1][j],dp[i][j]));
        }
    }
    cout<<dp[n][0]<<endl;
    return 0;
}