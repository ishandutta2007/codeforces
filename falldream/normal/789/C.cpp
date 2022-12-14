#include<iostream>
#include<cstdio>
#include<cmath>
#include<queue>
#include<cstring>
#include<queue>
#include<algorithm>
#define ll long long
#define INF 1000000000
#define MN 100000000
using namespace std;
inline ll read()
{
    ll x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0'; ch=getchar();}
    return x*f;
}

int n;
int a[100005];
ll f[100005],f2[100005];
ll ans=0;
int abs(int x){return x<0?-x:x;}

int main()
{
    n=read();
    for(int i=1;i<=n;i++)a[i]=read();
    for(int i=1;i<=n;i++) f[i]=f[i-1]+1LL*(i&1?1:-1)*abs(a[i]-a[i+1]);
    for(int i=1;i<=n;i++) f2[i]=f2[i-1]+1LL*(i&1?-1:1)*abs(a[i]-a[i+1]);
    ll minn=0;
    for(int i=1;i<n;i++)
    {
        ans=max(ans,f[i]-minn);
        if(i%2==0)minn=min(minn,f[i]);
    }
    minn=f2[1];
    for(int i=2;i<n;i++)
    {
      //  cout<<i<<" "<<f2[i]<<" "<<ans<<" "<<minn<<endl;
        ans=max(ans,f2[i]-minn);
        if(i&1)minn=min(minn,f2[i]);
    }
    cout<<ans<<endl;
    return 0;
}