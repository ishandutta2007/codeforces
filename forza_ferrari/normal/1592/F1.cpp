#include<iostream>
#include<cstdio>
using namespace std;
int n,m,ans;
bool mp[501][501],tmp[501][501],vis[501][501],sum[505][505];
int main()
{
    cin>>n>>m;
    for(register int i=1;i<=n;++i)
        for(register int j=1;j<=m;++j)
        {
            char c;
            cin>>c;
            if(c=='B')
                mp[i][j]=1;
        }
    for(register int i=n;i;--i)
        for(register int j=m;j;--j)
        {
            sum[i][j]^=sum[i+1][j]^sum[i][j+1]^sum[i+1][j+1];
            if(tmp[i][j]^sum[i][j]^mp[i][j])
            {
                ++ans;
                sum[i][j]^=1;
                vis[i][j]=1;
            }
        }
    /*for(register int i=1;i<=n;++i,cout<<endl)
        for(register int j=1;j<=m;++j)
            cout<<vis[i][j];*/
    if(vis[n][m])
        for(register int i=1;i<n;++i)
            for(register int j=1;j<m;++j)
                if(vis[i][m]&&vis[n][j]&&vis[i][j])
                {
                    cout<<ans-1<<endl;
                    return 0;
                }
    cout<<ans<<endl;
    return 0;
}