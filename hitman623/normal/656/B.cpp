#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll gcd(ll a,ll b)
{
    if(a==0) return b;
    if(a>b) return gcd(a%b,b);
    return gcd(b%a,a);
}
int main()
{
    long n,m[17],r[17],i,g=1,p=1,c=0,j;
    cin>>n;
    for(i=0;i<n;++i)
        {cin>>m[i];g=gcd(p,m[i]);p=(p*m[i])/g;}
    for(i=0;i<n;++i)
        cin>>r[i];
    for(i=1;i<=p;++i)
    {
        for(j=0;j<n;++j)
        if(i%m[j]==r[j]) {c++;break;}
    }
    //cout<<c<<p;
    long double an=(long double)c / (long double)p;
    cout<<an;
    return 0;
}