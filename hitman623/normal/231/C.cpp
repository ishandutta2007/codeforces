#include <bits/stdc++.h>
#define long long long
using namespace std;
long n,i,a[100005],k,p[100005];
long check(long mid)
{
    long i,l;
    for(i=mid-1;i<n;++i)
    if((a[i]-a[0])*mid-p[i]+((i>=mid)?p[i-mid]:0)<=k) return i;
    return -1;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>k;
    for(i=0;i<n;++i)
    cin>>a[i];
    sort(a,a+n);
    p[0]=0;
    for(i=1;i<n;++i)
    p[i]=a[i]-a[0];
    for(i=1;i<n;++i)
    p[i]+=p[i-1];
    long hi=n+1,lo=0,mid=(lo+hi)/2;
    for(i=0;i<60;++i)
    {
        mid=(lo+hi)/2;
        if(check(mid)>=0) lo=mid;
        else hi=mid;
    }
    if(check(hi)>=0) mid=hi;
    cout<<mid<<" "<<a[check(mid)];
    return 0;
}