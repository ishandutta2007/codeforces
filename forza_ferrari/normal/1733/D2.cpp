#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
#define int long long
int t,n,X,Y,dp[2][5001][2][3],w[5001],now,cnt;
string a,b;
signed main()
{
    cin>>t;
    while(t--)
    {
        cin>>n>>X>>Y>>a>>b;
        a=" "+a;
        b=" "+b;
        cnt=0;
        for(int i=1;i<=n;++i)
            cnt+=(w[i]=a[i]!=b[i]);
        if(cnt&1)
        {
            cout<<"-1\n";
            continue;
        }
        now=0;
        for(int i=0;i<=n;++i)
            dp[0][i][0][0]=dp[0][i][0][1]=dp[0][i][0][2]=dp[0][i][1][0]=dp[0][i][1][1]=dp[0][i][1][2]=1e18;
        dp[0][0][0][0]=0;
        for(int i=1;i<=n;++i)
        {
            now^=1;
            for(int j=0;j<=n;++j)
                dp[now][j][0][0]=dp[now][j][0][1]=dp[now][j][0][2]=dp[now][j][1][0]=dp[now][j][1][1]=dp[now][j][1][2]=1e18;
            for(int j=0;j<=n;++j)
                for(int x=0;x<2;++x)
                    for(int y=0;y<3&&j+y<=n;++y)
                        if(dp[now^1][j][x][y]<1e18)
                            for(int l=0;l<2;++l)
                                for(int r=0;r<3;++r)
                                {
                                    if(w[i]^x^l^(r&1))
                                    {
                                        if(j&&j-1+y+r<=n)
                                            dp[now][j-1+y][l][r]=min(dp[now][j-1+y][l][r],dp[now^1][j][x][y]+l*X+r*Y);
                                    }
                                    else
                                    {
                                        if(j+y+r<=n)
                                            dp[now][j+y][l][r]=min(dp[now][j+y][l][r],dp[now^1][j][x][y]+l*X+r*Y);
                                        if(j>=2&&j-2+y+r<=n)
                                            dp[now][j-2+y][l][r]=min(dp[now][j-2+y][l][r],dp[now^1][j][x][y]+l*X+r*Y);
                                    }
                                }
        }
        cout<<dp[now][0][0][0]<<'\n';
    }
    return 0;
}