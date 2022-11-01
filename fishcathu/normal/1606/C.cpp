#include<bits/stdc++.h>
#define ls i<<1
#define rs i<<1|1
#define pb push_back
using namespace std;
typedef __int128 ll;
typedef array<int,2> pii;
const int N=20;
const int inf=1<<30;
auto min(auto l,auto r){return l<r?l:r;}
auto max(auto l,auto r){return l>r?l:r;}
void cmin(auto &l,auto r){l=l<r?l:r;}
void cmax(auto &l,auto r){l=l>r?l:r;}
ll read()
{
    ll a=0;
    char b=1,c;
    do if((c=getchar())==45)b=-1;while(c<48||c>57);
    do a=(a<<3)+(a<<1)+(c&15);while((c=getchar())>47&&c<58);
    return a*b;
}
void write(ll x,char c)
{
    if(x<0)putchar(45),x=-x;
    char a[40],s=0;
    do a[++s]=x%10|48;while(x/=10);
    do putchar(a[s]);while(--s);
    putchar(c);
}
ll a[N],b[N],c[N];
void solve()
{
    int n=read(),m=read()+1;
    for(int i=1;i<N;++i)a[i]=0;
    while(n--)a[read()+1]=1;
    for(int i=1;i<N;++i)
    {
        if(!a[i])a[i]=a[i-1]*10;
        b[i]=b[i-1]+a[i]*9LL;
    }
    ll ans=0;
    for(int i=N;i>=1;--i)
    {
        ll x=m-b[i-1]-1;
        if(x<0)continue;
        int t=x/a[i]+1;
        m-=t*1LL*a[i];
        ans+=t*1LL*c[i];
    }
    write(ans,'\n');
}
int main()
{
    c[1]=1;
    for(int i=2;i<N;++i)c[i]=c[i-1]*10;
    for(int x=read();x--;)
    {
        solve();
    }
}