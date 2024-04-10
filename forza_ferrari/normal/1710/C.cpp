#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
const int mod=998244353;
int n,dp[200001][2][2][2][2][2][2];
string s;
int main()
{
    cin>>s;
    n=s.length();
    s=" "+s;
    dp[0][1][1][1][0][0][0]=1;
    for(int i=1;i<=n;++i)
        for(int x=0;x<2;++x)
            for(int y=0;y<2;++y)
                for(int z=0;z<2;++z)
                    for(int a=0;a<2;++a)
                        for(int b=0;b<2;++b)
                            for(int c=0;c<2;++c)
                                if(dp[i-1][x][y][z][a][b][c])
                                {
                                    //cout<<i-1<<" "<<((x<<2)|(y<<1)|z)<<" "<<((a<<2)|(b<<1)|c)<<" "<<dp[i-1][x][y][z][a][b][c]<<'\n';
                                    dp[i][x&&s[i]=='0'][y&&s[i]=='0'][z&&s[i]=='0'][a][b][c]=(dp[i][x&&s[i]=='0'][y&&s[i]=='0'][z&&s[i]=='0'][a][b][c]+dp[i-1][x][y][z][a][b][c])%mod;
                                    if((!x||s[i]=='1')&&(!y||s[i]=='1')&&(!z||s[i]=='1'))
                                        dp[i][x][y][z][a][b][c]=(dp[i][x][y][z][a][b][c]+dp[i-1][x][y][z][a][b][c])%mod;
                                    if(!x||s[i]=='1')
                                        dp[i][x][y&&s[i]=='0'][z&&s[i]=='0'][1][b][c]=(dp[i][x][y&&s[i]=='0'][z&&s[i]=='0'][1][b][c]+dp[i-1][x][y][z][a][b][c])%mod;
                                    if(!y||s[i]=='1')
                                        dp[i][x&&s[i]=='0'][y][z&&s[i]=='0'][a][1][c]=(dp[i][x&&s[i]=='0'][y][z&&s[i]=='0'][a][1][c]+dp[i-1][x][y][z][a][b][c])%mod;
                                    if(!z||s[i]=='1')
                                        dp[i][x&&s[i]=='0'][y&&s[i]=='0'][z][a][b][1]=(dp[i][x&&s[i]=='0'][y&&s[i]=='0'][z][a][b][1]+dp[i-1][x][y][z][a][b][c])%mod;
                                    if((!x||s[i]=='1')&&(!y||s[i]=='1'))
                                        dp[i][x][y][z&&s[i]=='0'][a][b][1]=(dp[i][x][y][z&&s[i]=='0'][a][b][1]+dp[i-1][x][y][z][a][b][c])%mod;
                                    if((!x||s[i]=='1')&&(!z||s[i]=='1'))
                                        dp[i][x][y&&s[i]=='0'][z][a][1][c]=(dp[i][x][y&&s[i]=='0'][z][a][1][c]+dp[i-1][x][y][z][a][b][c])%mod;
                                    if((!y||s[i]=='1')&&(!z||s[i]=='1'))
                                        dp[i][x&&s[i]=='0'][y][z][1][b][c]=(dp[i][x&&s[i]=='0'][y][z][1][b][c]+dp[i-1][x][y][z][a][b][c])%mod;
                                }
    int ans=0;
    for(int x=0;x<2;++x)
        for(int y=0;y<2;++y)
            for(int z=0;z<2;++z)
            {
                //cout<<dp[n][x][y][z][1][1][1]<<'\n';
                ans=(ans+dp[n][x][y][z][1][1][1])%mod;
            }
    cout<<ans<<'\n';
    return 0;
}