#include<iostream>
#include<cstdio>
using namespace std;
const int mod=1000000007;
int n,m,p;
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
    cin>>n>>m>>p;
    cout<<1ll*c(n-1,p<<1)*c(m-1,p<<1)%mod<<'\n';
    return 0;
}