#include <bits/stdc++.h>
#define long long long
using namespace std;
long n,i,a[500005];
long check(long mid)
{
    long i;
    for(i=mid;i>=0;--i)
    if(2*a[i]>a[n-1-(mid-i)]) return 0;
    return 1;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(i=0;i<n;++i)
    cin>>a[i];
    sort(a,a+n);
    long hi=n,lo=-1,mid=(lo+hi)/2;
    for(i=0;i<60;++i)
    {
        mid=(lo+hi)/2;
        if(check(mid)) lo=mid;
        else hi=mid;
    }
    if(check(hi)) mid=hi;
    if(!check(mid)) mid=lo;
    cout<<max(n-1-mid,(n+1)/2);
    return 0;
}