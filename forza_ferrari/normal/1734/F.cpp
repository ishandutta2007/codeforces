#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define int long long
int t,n,m,dp[63][2][2][2];
signed main()
{
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        memset(dp,0,sizeof dp);
        dp[0][0][0][1]=1;
        for(int i=0;i<=60;++i)
        {
            int x=n>>i&1,y=m>>i&1;
            for(int j=0;j<2;++j)
                for(int l=0;l<2;++l)
                    for(int r=0;r<2;++r)
                        if(dp[i][j][l][r])
                            for(int k=0;k<2;++k)
                                dp[i+1][j^x^l][k+x+l>1][k==y? r:(k>y)]+=dp[i][j][l][r];
        }
        cout<<dp[61][1][0][0]+dp[61][1][1][0]<<'\n';
    }
    return 0;
}