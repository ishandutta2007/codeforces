#include<iostream>
#include<cstdio>
#include<map>
using namespace std;
#define int long long
int n,m,val[21],ans;
bool vis[1000001*20];
signed main()
{
    cin>>n>>m;
    for(int i=1;i<=20;++i)
    {
        val[i]=val[i-1];
        for(int j=1;j<=m;++j)
            if(!vis[i*j])
            {
                ++val[i];
                vis[i*j]=1;
            }
    }
    for(int i=1;i<=20*m;++i)
        vis[i]=0;
    for(int i=2;i<=n;++i)
        if(!vis[i])
        {
            int cnt=0;
            for(int j=i;j<=n;j*=i,++cnt)
                vis[j]=1;
            ans+=val[cnt];
        }
    cout<<++ans<<'\n';
    return 0;
}