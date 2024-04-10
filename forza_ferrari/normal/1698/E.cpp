#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int mod=998244353;
int t,n,m,a[200001],b[200001],p[200001],ans,val[200001],tot,cnt;
bool vis[200001];
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        cnt=tot=0;
        ans=1;
        for(int i=1;i<=n;++i)
            vis[i]=0;
        for(int i=1;i<=n;++i)
        {
            cin>>a[i];
            p[a[i]]=i;
        }
        for(int i=1;i<=n;++i)
        {
            cin>>b[i];
            vis[b[i]]=1;
        }
        for(int i=1;i<=n;++i)
            if(!vis[i])
                val[++cnt]=i;
        for(int i=n;i>=1;--i)
            if(b[p[i]]==-1)
                ans=1ll*ans*(cnt-(lower_bound(val+1,val+cnt+1,i-m)-val)+1-tot++)%mod;
            else if(i-m>b[p[i]])
                ans=0;
        cout<<ans<<'\n';
    }
    return 0;
}