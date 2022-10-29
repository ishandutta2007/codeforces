#include <bits/stdc++.h>
#define pb push_back
#define long long long
#define pll pair < long , long >
#define vll vector < pll >
#define vl vector < long >
#define io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
long h=1e9+7;
long n,s,i,f[22],v[22]={0},fa[22],m,j,d,ans=0,c;
long po(long a, long b)
{
    if(a==0) return 0;
    if(a==1 || b==0) return 1;
    long m=po(a,b/2);
    if(b%2) return (((m*m)%h)*a)%h;
    return (m*m)%h;
}
long ncr(long n,long r)
{
    if(r<0) return 0;
    long i;
    if(n+r-1<r) return 0;
    long a=fa[n-1];
    for(i=0;i<n-1;++i)
    a=(a*((n+r-1-i)%h))%h;
    return a;
}
int main()
{
    io
    fa[0]=1;
    fa[1]=1;
    for(i=2;i<=21;++i)
    fa[i]=(fa[i-1]*po(i,h-2))%h;
    cin>>n>>s;
    for(i=0;i<n;i++)
    cin>>f[i];
    m=(1<<n);
    for(i=0;i<m;++i)
    {
        c=0;
        memset(v,0,sizeof(v));
        for(j=0;j<n;++j)
        if(i&(1<<j))
        v[j]=1,c++;
        d=s;
        for(j=0;j<n;++j)
        if(v[j])
        d-=(f[j]+1);
        if((n-c)%2)
        ans=(ans+h-(ncr(n,d)%h))%h;
        else ans=(ans+ncr(n,d)%h)%h;
    }
    if(n%2)
    cout<<(h-ans)%h;
    else cout<<ans;
    return 0;
}