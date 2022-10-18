#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
#define int long long
int n,a[1000005],b[1000005];
signed main()
{
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        cin>>a[i];
        b[i]=a[i]-a[1]+1;
    }
    b[n+1]=1e9;
    for(int i=1;;++i)
    {
        int ql=max(0ll,a[1]-i*i),qr=1e9,l=0,r=0,mid=0;
        for(int j=i;;++j)
        {
            l=r+1;
            mid=l+j;
            r=mid+j;
            if(l>2000000)
            {
                cout<<i*i+ql-a[1]<<'\n';
                return 0;
            }
            int pos=upper_bound(b+1,b+n+2,mid)-b;
            if(b[pos]<=r)
                ql=max(ql,r-b[pos]+1);
            if(b[pos-1]>=l)
                qr=min(qr,mid-b[pos-1]);
            if(ql>qr)
                break;
        }
    }
    return 0;
}