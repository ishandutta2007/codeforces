#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
#define int long long
int t,n,a[200005],d[200005];
signed main()
{
    cin>>t;
    while(t--)
    {
        cin>>n;
        int ans=0,val=0;
        for(int i=1;i<=n;++i)
        {
            cin>>a[i];
            d[i]=a[i]-a[i-1];
        }
        d[n+1]=-a[n];
        for(int i=2;i<=n;++i)
            if(d[i]>=0)
                ans+=d[i];
            else
            {
                val-=d[i];
                ans-=d[i];
            }
        ans+=abs(d[1]-val);
        cout<<ans<<'\n';
    }
    return 0;
}