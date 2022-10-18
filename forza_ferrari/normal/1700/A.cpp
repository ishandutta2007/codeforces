#include<iostream>
#include<cstdio>
using namespace std;
#define int long long
int t,n,m,ans;
signed main()
{
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        ans=0;
        for(int i=1;i<=m;++i)
            ans+=i;
        for(int i=2;i<=n;++i)
            ans+=i*m;
        cout<<ans<<'\n';
    }
    return 0;
}