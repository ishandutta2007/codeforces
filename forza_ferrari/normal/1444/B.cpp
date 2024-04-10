#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int mod=998244353;
int n,a[300001],ans;
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
inline int c(int x,int y)
{
    int res=1;
    for(int i=x;i>=x-y+1;--i)
        res=1ll*res*i%mod;
    for(int i=1;i<=y;++i)
        res=1ll*res*pw(i,mod-2)%mod;
    return res;
}
int main()
{
    cin>>n;
    for(int i=1;i<=n<<1;++i)
        cin>>a[i];
    sort(a+1,a+(n<<1)+1);
    for(int i=1;i<=n;++i)
        ans=(ans+a[i+n]-a[i])%mod;
    cout<<1ll*ans*c(n<<1,n)%mod<<'\n';
    return 0;
}