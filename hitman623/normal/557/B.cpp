#include <bits/stdc++.h>
#define pb push_back

using namespace std;
long long n,w,i;
long double a[200005];
int check(long double mid)
{
    long long i,c1=0,c2=0;
    long double x=mid/(3*n);
    for(i=0;i<2*n;++i)
    {
        if(a[i]-x>=-0.0000001) c1++;
        if(a[i]-2*x>=-0.0000001) c2++;
    }
    if(c2>=n && c1==2*n) return 1;
    return 0;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>w;
    for(i=0;i<2*n;++i)
    cin>>a[i];
    long double hi=w,lo=0,mid;
    cout<<setprecision(8);
    while(hi-lo>0.00000001)
    {
        mid=(lo+hi)/2;
        if(check(mid))
            lo=mid;
        else hi=mid;
    }
    if(check(hi)) cout<<hi;
    else if(check(mid)) cout<<mid;
    else cout<<lo;
    return 0;
}