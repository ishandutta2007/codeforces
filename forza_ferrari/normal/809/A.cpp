#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int mod=1000000007;
int n,a[300001],ans,p;
int main()
{
    cin>>n;
    for(int i=1;i<=n;++i)
        cin>>a[i];
    sort(a+1,a+n+1);
    p=(mod+1)>>1;
    for(int i=1;i<=n;++i)
        a[i]=(a[i]+a[i-1])%mod;
    for(int i=1;i<n;++i)
    {
        int len=max(i+1,n-i+1),sum=((a[n]-a[len-1]+mod)%mod-a[n-len+1]+mod)%mod;
        p=(p<<1)%mod;
        ans=(ans+1ll*p*sum%mod)%mod;
    }
    cout<<ans<<'\n';
    return 0;
}