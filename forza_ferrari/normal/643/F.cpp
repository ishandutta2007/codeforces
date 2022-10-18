#include<iostream>
#include<cstdio>
using namespace std;
#define int unsigned int
const long long mod=1ll<<32;
int n,p,q,val[201],ans;
inline void exgcd(long long a,long long b,long long &x,long long &y)
{
    if(!b)
    {
        x=1;
        y=0;
        return;
    }
    exgcd(b,a%b,y,x);
    y-=a/b*x;
}
inline int inv(long long w)
{
    long long x,y;
    exgcd(w,mod,x,y);
    return (int)((x+mod)%mod);
}
inline int calc(int m)
{
    int cnt=0,res=1;
    for(int i=n;i>=n-m+1;--i)
    {
        int len=__builtin_ctz(i);
        cnt+=len;
        res*=i>>len;
    }
    for(int i=1;i<=m;++i)
    {
        int len=__builtin_ctz(i);
        cnt-=len;
        res*=inv(i>>len);
    }
    return res*(1u<<cnt);
}
signed main()
{
    cin>>n>>p>>q;
    p=min(p,n-1);
    for(int i=0;i<=p;++i)
        val[i]=calc(i);
    for(int i=1;i<=q;++i)
    {
        int res=0,w=1;
        for(int j=0;j<=p;++j)
        {
            res+=w*val[j];
            w*=i;
        }
        ans^=i*res;
    }
    cout<<ans<<'\n';
    return 0;
}