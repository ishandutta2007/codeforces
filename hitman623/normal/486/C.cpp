#include <bits/stdc++.h>

using namespace std;

int main()
{
    long n,p,ans=0,i,y[100005]={0},l=-1,u=-1;
    char a[100005];
    cin>>n>>p;
    cin>>a;
    for(i=0;i<n;++i)
    {
        if(a[i]!=a[n-i-1]) y[i]=1;
        ans+=min(abs(a[i]-a[n-i-1]),26-abs(a[i]-a[n-i-1]));
    }
    ans/=2;
    if(p>n/2) p=n-p+1;
    for(i=p-1;i<n/2;++i)
    if(y[i]==1) u=i;
    for(i=p-1;i>=0;--i)
    if(y[i]==1) l=i;
    if(l==-1 && u==-1) {cout<<0;exit(0);}
    else if(l==-1) l=u;
    else if(u==-1) u=l;
    ans+=u-l+min(abs(p-1-l),abs(u-p+1));
    cout<<ans;
    return 0;
}