#include <bits/stdc++.h>
#define pb push_back
#define long long double
#define pair < long , long > pll
using namespace std;
int main()
{
    long m=0,a[1003],l;
    int n,i;
    cin>>n>>l;
    for(i=0;i<n;++i)
    cin>>a[i];
    sort(a,a+n);
    for(i=0;i<n-1;++i)
    m=max(m,a[i+1]-a[i]);
    m=m/2.0;
    m=max(a[0],m);
    m=max(m,l-a[n-1]);
    cout<<fixed;
    cout<<setprecision(10);
    cout<<m;
    return 0;
}