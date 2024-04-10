#include<iostream>
#include<cstdio>
using namespace std;
int t,n,m,a[100005],b[100005],ans;
inline bool check(int x)
{
    int cnt=0;
    for(int i=1;i<=n;++i)
    {
        b[i]=a[i];
        if(b[i]+b[i]<x)
        {
            b[i]=1e9;
            ++cnt;
        }
    }
    bool flag1=1,flag2=1;
    for(int i=1;i<=n;++i)
    {
        if(i>1&&min(b[i],b[i-1])>=x)
            flag1=0;
        if(b[i]>=x)
            flag2=0;
    }
    return cnt+flag1+flag2<=m;
}
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        for(int i=1;i<=n;++i)
            cin>>a[i];
        int l=0,r=1e9,mid;
        ans=0;
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