#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
#define int long long
int t,n,a[400005];
signed main()
{
    cin>>t;
    while(t--)
    {
        cin>>n;
        int ans=0;
        a[0]=a[n+1]=0;
        for(int i=1;i<=n;++i)
        {
            cin>>a[i];
            ans+=abs(a[i]-a[i-1]);
        }
        ans+=a[n];
        for(int i=1;i<=n;++i)
            if(max(a[i-1],a[i+1])<a[i])
                ans-=a[i]-max(a[i-1],a[i+1]);
        cout<<ans<<'\n';
    }
    return 0;
}