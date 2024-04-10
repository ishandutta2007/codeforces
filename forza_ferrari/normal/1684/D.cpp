#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
#define int long long
int t,n,m,a[200001],ans;
signed main()
{
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        ans=0;
        for(int i=1;i<=n;++i)
        {
            cin>>a[i];
            ans+=a[i];
            a[i]-=n-i;
        }
        sort(a+1,a+n+1);
        reverse(a+1,a+n+1);
        for(int i=1;i<=m&&a[i]+i-1>=0;++i)
            ans-=a[i]+i-1;
        cout<<ans<<'\n';
    }
    return 0;
}