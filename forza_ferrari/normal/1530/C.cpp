#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int t,n,a[100001],b[100001];
inline bool check(int len)
{
    int m=len-(len>>2);
    long long x=0,y=min(m,(len-n))*100;
    for(int i=1;i<=min(m,n);++i)
        x+=a[i];
    for(int i=1;i<=m-(len-n);++i)
        y+=b[i];
    return x<=y;
}
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=1;i<=n;++i)
            cin>>b[i];
        for(int i=1;i<=n;++i)
            cin>>a[i];
        sort(a+1,a+n+1);
        sort(b+1,b+n+1);
        reverse(a+1,a+n+1);
        reverse(b+1,b+n+1);
        int l=0,r=n,mid,ans=0;
        while(l<=r)
        {
            mid=(l+r)>>1;
            if(check(n+mid))
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