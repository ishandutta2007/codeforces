#include<iostream>
#include<cstdio>
using namespace std;
const int mod=1000000007;
int t,n,a[100001],b[100001],c[100001],p[100001][2],ans;
bool vis[100001];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    while(t--)
    {
        ans=1;
        cin>>n;
        for(int i=1;i<=n;++i)
        {
            cin>>a[i];
            p[a[i]][0]=i;
        }
        for(int i=1;i<=n;++i)
        {
            cin>>b[i];
            p[b[i]][1]=i;
            vis[i]=0;
        }
        for(int i=1;i<=n;++i)
            cin>>c[i];
        for(int i=1;i<=n;++i)
            if(!vis[i]&&c[i])
            {
                if(c[i]!=a[i]&&c[i]!=b[i])
                    ans=0;
                if(c[i]==a[i])
                    for(int j=i;!vis[j];j=p[b[j]][0])
                    {
                        if(c[j]&&c[j]!=a[j])
                            ans=0;
                        vis[j]=1;
                    }
                else
                    for(int j=i;!vis[j];j=p[a[j]][1])
                    {
                        if(c[j]&&c[j]!=b[j])
                            ans=0;
                        vis[j]=1;
                    }
            }
        for(int i=1;i<=n;++i)
            if(!vis[i])
            {
                int cnt=0;
                for(int j=i;!vis[j];j=p[b[j]][0])
                {
                    vis[j]=1;
                    ++cnt;
                }
                if(cnt>1)
                    ans=(ans<<1)%mod;
            }
        cout<<ans<<endl;
    }
    return 0;
}