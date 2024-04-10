#include<iostream>
#include<cstdio>
using namespace std;
#define int long long
int t,n,m,a[101],ans;
signed main()
{
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        ans=0;
        for(int i=0;i<m;++i)
            a[i]=0;
        for(int i=1;i<=n;++i)
        {
            int x;
            cin>>x;
            a[i%m]=max(a[i%m],x);
        }
        for(int i=0;i<m;++i)
            ans+=a[i];
        cout<<ans<<'\n';
    }
    return 0;
}