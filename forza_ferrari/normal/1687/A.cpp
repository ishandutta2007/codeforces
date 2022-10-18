#include<iostream>
#include<cstdio>
using namespace std;
#define int long long
int t,n,m,a[200001];
signed main()
{
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        for(int i=1;i<=n;++i)
            cin>>a[i];
        if(m<n)
        {
            int ans=0;
            for(int i=1;i<=n;++i)
                a[i]+=a[i-1];
            for(int i=m;i<=n;++i)
                ans=max(ans,a[i]-a[i-m]);
            cout<<ans+m*(m-1)/2<<'\n';
        }
        else
        {
            int ans=0;
            for(int i=1;i<=n;++i)
                ans+=a[i];
            cout<<ans+(2*m-n-1)*n/2<<'\n';
        }
    }
    return 0;
}