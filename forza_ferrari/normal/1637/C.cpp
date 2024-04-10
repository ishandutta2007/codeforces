#include<iostream>
#include<cstdio>
using namespace std;
#define int long long
int t,n,a[100001],ans,maxn;
signed main()
{
    cin>>t;
    while(t--)
    {
        cin>>n;
        maxn=0;
        for(int i=1;i<=n;++i)
        {
            cin>>a[i];
            if(i!=1&&i!=n)
                maxn=max(maxn,a[i]);
        }
        ans=0;
        if(maxn<2||(n==3&&(a[2]&1)))
        {
            puts("-1");
            continue;
        }
        for(int i=2;i<n;++i)
            ans+=(a[i]+1)>>1;
        cout<<ans<<endl;
    }
    return 0;
}