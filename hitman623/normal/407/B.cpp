#include <bits/stdc++.h>
#define pb push_back
#define long long long
using namespace std;
int main()
{
    long n,i,a[1003],r[1003]={0},h=1e9+7,j,ans=0;
    cin>>n;
    for(i=1;i<=n;++i)
    cin>>a[i];
    r[1]=1;
    for(i=2;i<=n;++i)
    {
        for(j=a[i];j<i;++j)
        r[i]=(r[i]+r[j]+1)%h;
        r[i]=(r[i]+1)%h;
    }
    for(i=1;i<=n;++i)
    ans=(ans+r[i]+1)%h;
    cout<<ans%h;
    return 0;
}