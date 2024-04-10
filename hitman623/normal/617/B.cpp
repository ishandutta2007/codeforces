#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long n,a[100],i,f=0,j=0,s=0,p=1,g=0;
    cin>>n;
    for(i=0;i<n;++i)
    {
        cin>>a[i];
        if(a[i]) g=1;
        if(!f && a[i]) {j=i;f=1;}
    }
    if(!g) {cout<<0;exit(0);}
    for(i=j;i<n;++i)
    {
        s+=a[i];
        if(s>1) {p*=i-j;s=1;j=i;}
    }
    cout<<p;
    return 0;
}