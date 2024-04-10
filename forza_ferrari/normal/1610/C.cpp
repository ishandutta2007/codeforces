#include<iostream>
#include<cstdio>
using namespace std;
int t,n,a[200001],b[200001];
inline bool check(int x)
{
    int l=x-1,r=0,cnt=0;
    for(int i=1;i<=n;++i)
    {
        if(a[i]>=l&&b[i]>=r)
        {
            ++cnt;
            if(cnt==x)
                return 1;
            --l;
            ++r;
        }
    }
    return 0;
}
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=1;i<=n;++i)
            cin>>a[i]>>b[i];
        int l=1,r=n,mid,ans=0;
        while(l<=r)
        {
            mid=(l+r)>>1;
            if(check(mid))
            {
                ans=mid;
                l=mid+1;
            }
            else
                r=mid-1;
        }
        cout<<ans<<'\n';
    }
    return 0;
}