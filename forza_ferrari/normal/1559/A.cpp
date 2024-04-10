#include<iostream>
#include<cstdio>
using namespace std;
#define int long long
int t,n,a,ans;
signed main()
{
    cin>>t;
    while(t--)
    {
        cin>>n;
        ans=(1<<30)-1;
        for(register int i=1;i<=n;++i)
        {
            cin>>a;
            ans&=a;
        }
        cout<<ans<<endl;
    }
    return 0;
}