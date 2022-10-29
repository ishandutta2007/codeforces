#include <bits/stdc++.h>
#define pb push_back
#define long long long
using namespace std;
long n,k,a[2001][2001]={0},ans=0,h=1e9+7,i,j,x,y,t;
vector < long > f[2002];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>k;
    for(i=1;i<=n;++i)
    {
        for(j=1;j*j<=i;++j)
        if(i%j==0)
        {
            f[i].pb(j);
            if(j*j!=i)
            f[i].pb(i/j);
        }
    }
    for(i=1;i<=n;++i)
    a[i][1]=1;
    for(i=n;i>=1;i--)
    {
        for(j=1;j<=k;++j)
        {
            t=f[i].size();
            for(y=0;y<t;++y)
            {
                x=f[i][y];
                a[x][j]+=a[i][j-1];
                a[x][j]%=h;
            }
        }
    }
    for(i=1;i<=n;++i)
    ans=(ans+a[i][k])%h;
    cout<<ans;
    return 0;
}