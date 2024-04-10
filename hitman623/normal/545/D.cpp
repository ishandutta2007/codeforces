#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long n,a[100005],i,c=0,t=0,x;
    cin>>n;
    for(i=0;i<n;++i)
    cin>>a[i];
    sort(a,a+n);
    for(i=0;i<n;++i)
    if(a[i]>=t)
    {t+=a[i];c++;}
    cout<<c;
    return 0;
}