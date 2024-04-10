#include<iostream>
#include<cstdio>
#include<string>
#include<stack>
using namespace std;
#define int long long
const int mod=1000000007;
string s;
stack<int> t;
int n,a[1001],cnt,dp[1001][1001][3][3],ans;
bool tag[1001][1001];
signed main()
{
    cin>>s;
    n=s.length();
    s=" "+s;
    for(int i=1;i<=n;++i)
        if(s[i]=='(')
            t.emplace(a[i]=++cnt);
        else
        {
            a[i]=t.top();
            t.pop();
        }
    for(int i=1;i<n;++i)
        if(a[i]==a[i+1])
        {
            dp[i][i+1][0][1]=dp[i][i+1][0][2]=dp[i][i+1][1][0]=dp[i][i+1][2][0]=1;
            tag[i][i+1]=1;
        }
    for(int len=4;len<=n;len+=2)
        for(int i=1,j=len;j<=n;++i,++j)
            if(a[i]==a[j])
            {
                tag[i][j]=tag[i+1][j-1];
                for(int x=0;x<3;++x)
                    for(int y=0;y<3;++y)
                        if((!x||!y)&&(x|y))
                            for(int l=0;l<3;++l)
                                if(!x||x!=l)
                                    for(int r=0;r<3;++r)
                                        if(!y||y!=r)
                                            dp[i][j][x][y]=(dp[i][j][x][y]+dp[i+1][j-1][l][r])%mod;
            }
            else
                for(int k=i+1;k<j;k+=2)
                    if(tag[i][k]&&tag[k+1][j])
                    {
                        tag[i][j]=1;
                        for(int x=0;x<3;++x)
                            for(int y=0;y<3;++y)
                                if(dp[i][k][x][y])
                                    for(int l=0;l<3;++l)
                                        if(!y||y!=l)
                                            for(int r=0;r<3;++r)
                                                if(dp[k+1][j][l][r])
                                                    dp[i][j][x][r]=(dp[i][j][x][r]+dp[i][k][x][y]*dp[k+1][j][l][r]%mod)%mod;
                        break;
                    }
    for(int i=0;i<3;++i)
        for(int j=0;j<3;++j)
            ans=(ans+dp[1][n][i][j])%mod;
    cout<<ans<<'\n';
    return 0;
}