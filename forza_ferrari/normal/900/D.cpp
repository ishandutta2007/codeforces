#include<iostream>
#include<cstdio>
#include<map>
using namespace std;
const int mod=1000000007;
int n,m;
map<int,int> mp;
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
inline int f(int n)
{
    if(mp.count(n))
        return mp[n];
    mp[n]=(pw(2,n-1)-f(1)+mod)%mod;
    for(int i=2;i*i<=n;++i)
        if(n%i==0)
        {
            mp[n]=(mp[n]-f(i)+mod)%mod;
            if(i*i!=n)
                mp[n]=(mp[n]-f(n/i)+mod)%mod;
        }
    return mp[n];
}
int main()
{
    cin>>m>>n;
    mp[1]=1;
    if(n%m)
    {
        puts("0");
        return 0;
    }
    cout<<f(n/m)<<'\n';
    return 0;
}