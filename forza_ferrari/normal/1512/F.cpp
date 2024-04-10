#include<iostream>
#include<cstdio>
using namespace std;
#define int long long
int t,n,m,a[200001],b[200001],ans,d[200001],w[200001];
signed main()
{
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        for(int i=1;i<=n;++i)
            cin>>a[i];
        for(int i=2;i<=n;++i)
            cin>>b[i];
        ans=1e9+7;
        for(int i=1;i<=n;++i)
        {
            ans=min(ans,d[i]+max(0ll,(m-w[i]+a[i]-1)/a[i]));
            if(i==n)
                break;
            d[i+1]=d[i]+max(0ll,(b[i+1]-w[i]+a[i]-1)/a[i])+1;
            w[i+1]=w[i]+max(0ll,(b[i+1]-w[i]+a[i]-1)/a[i])*a[i]-b[i+1];
        }
        cout<<ans<<'\n';
    }
    return 0;
}