#include<iostream>
#include<cstdio>
using namespace std;
int t,n,ans,a[3];
inline bool check(int mid)
{
    a[0]=a[1]=a[2]=mid/3;
    for(int i=0;i<mid%3;++i)
        ++a[i];
    return 2ll*(1ll*a[0]*a[1]+1ll*a[0]*a[2]+1ll*a[1]*a[2])>=n;
}
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n;
        ans=0;
        int l=1,r=1e9,mid;
        while(l<=r)
        {
            mid=(l+r)>>1;
            if(check(mid))
            {
                ans=mid;
                r=mid-1;
            }
            else
                l=mid+1;
        }
        cout<<ans<<'\n';
    }
    return 0;
}