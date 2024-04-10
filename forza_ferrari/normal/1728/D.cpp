#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
int t,n;
string s;
bool dp[2001][2001];
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>s;
        n=s.length();
        s=" "+s;
        for(int i=1;i<=n;++i)
            for(int j=1;j<=n;++j)
                dp[i][j]=0;
        for(int i=1;i<n;++i)
            dp[i][i+1]=s[i]!=s[i+1];
        for(int len=4;len<=n;len+=2)
            for(int i=1,j=len;j<=n;++i,++j)
            {
                bool x=dp[i+1][j-1]||s[i]!=s[j],y=dp[i+2][j]||s[i]!=s[i+1],z=dp[i][j-2]||s[j-1]!=s[j];
                if((!x||!y)&&(!x||!z))
                    dp[i][j]=0;
                else
                    dp[i][j]=1;
            }
        cout<<(dp[1][n]? "Alice":"Draw")<<'\n';
    }
    return 0;
}