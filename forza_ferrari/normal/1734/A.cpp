#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int t,n,ans,a[301];
int main()
{
    cin>>t;
    while(t--)
    {
        ans=2e9;
        cin>>n;
        for(int i=1;i<=n;++i)
            cin>>a[i];
        for(int i=1;i<=n;++i)
            for(int j=1;j<=n;++j)
                for(int k=1;k<=n;++k)
                    if(i!=j&&i!=k&&j!=k)
                        ans=min(ans,abs(a[i]-a[j])+abs(a[i]-a[k]));
        cout<<ans<<'\n';
    }
    return 0;
}