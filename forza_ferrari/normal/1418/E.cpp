#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int mod=998244353;
int n,m,a[200001],sum[200001];
inline int pw(int a,int b)
{
    int res=1;
    while(b)
    {
        if(b&1)
            res=1ll*res*a%mod;
        b>>=1;
        a=1ll*a*a%mod;
    }
    return res;
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;++i)
        cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;++i)
        sum[i]=(sum[i-1]+a[i])%mod;
    while(m--)
    {
        int x,y;
        cin>>x>>y;
        int pos=lower_bound(a+1,a+n+1,y)-a;
        if(pos>n||n-pos+1<x)
        {
            cout<<"0\n";
            continue;
        }
        cout<<(1ll*(sum[n]-sum[pos-1]+mod)%mod*(n-pos+1-x)%mod*pw(n-pos+1,mod-2)%mod+1ll*sum[pos-1]*(n-pos+2-x)%mod*pw(n-pos+2,mod-2)%mod)%mod<<'\n';
    }
    return 0;
}