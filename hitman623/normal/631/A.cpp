#include <bits/stdc++.h>
#define ll long long
#define pb push_back

using namespace std;

int main()
{
    ll n,a[1003],b[1003],i,m=0,j;
    cin>>n;
    for(i=0;i<n;++i)
        {cin>>a[i];
        if(i>0)
        a[i]|=a[i-1];}
    for(i=0;i<n;++i)
        {cin>>b[i];
        if(i>0)
            b[i]|=b[i-1];}
    for(i=0;i<n;++i)
    {
        m=max(m,b[i]+a[i]);
    for(j=i+1;j<n;++j)
        m=max(m,b[j]&(!b[i])+a[j]&(!a[i]));
    }
    cout<<m;
    return 0;
}