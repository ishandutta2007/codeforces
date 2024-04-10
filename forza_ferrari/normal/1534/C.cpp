#include<iostream>
#include<cstdio>
using namespace std;
const int mod=1000000007;
int t,n,a[400001],p[400001];
bool vis[400001];
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=1;i<=n;++i)
            cin>>a[i];
        for(int i=1;i<=n;++i)
        {
            vis[i]=0;
            cin>>p[a[i]];
        }
        int ans=1;
        for(int i=1;i<=n;++i)
            if(!vis[i])
            {
                for(int j=i;!vis[j];j=p[j])
                    vis[j]=1;
                ans=(ans<<1)%mod;
            }
        cout<<ans<<'\n';
    }
    return 0;
}