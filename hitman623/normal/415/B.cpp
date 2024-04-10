#include <bits/stdc++.h>
#define pb push_back
#define long long long
using namespace std;

int main()
{
    long n,a,b,x[100005],i;
    cin>>n>>a>>b;
    for(i=0;i<n;++i)
    cin>>x[i];
    for(i=0;i<n;++i)
    cout<<x[i]-((((x[i]*a)/b)*b)/a+!!((((x[i]*a)/b)*b)%a))<<" ";
    return 0;
}