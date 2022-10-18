#include<iostream>
#include<cstdio>
using namespace std;
const int mod=1000000007;
int t,n,a[100001],p[100001],ans;
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=1;i<=n;++i)
        {
            cin>>a[i];
            p[a[i]]=i;
        }
        ans=1;
        int l=min(p[0],p[1]),r=max(p[0],p[1]);
        for(int i=2;i<n;++i)
        {
            if(p[i]>l&&p[i]<r)
                ans=1ll*ans*(r-l+1-i)%mod;
            else
            {
                l=min(l,p[i]);
                r=max(r,p[i]);
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}