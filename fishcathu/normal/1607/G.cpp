#include<bits/stdc++.h>
#define ls i<<1
#define rs i<<1|1
#define pb push_back
using namespace std;
typedef long long ll;
typedef array<int,2> pii;
const int N=2E5+10;
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
    char a[20],s=0;
    do a[++s]=x%10|48;while(x/=10);
    do putchar(a[s]);while(--s);
    putchar(c);
}
int a[N],b[N],l[N],r[N];
ll u[N],v[N];
void solve()
{
    int n=read(),m=read();
    for(int i=1;i<=n;++i)
    {
        a[i]=read();
        b[i]=read();
        l[i]=max(a[i]-b[i]-m,m-a[i]-b[i]);
        r[i]=min(a[i]-b[i]+m,a[i]+b[i]-m);
        u[i]=u[i-1]+l[i];
        v[i]=v[i-1]+r[i];
    }
    ll ans;
    if(u[n]<0&&v[n]>0)ans=u[n]&1;
    else ans=abs(u[n])<abs(v[n])?u[n]:v[n];
    write(abs(ans),'\n');
    for(int i=n;i>=1;--i)
    {
        int t;
        if(ans-l[i]<=v[i-1])t=l[i];
        else t=ans-v[i-1];
        l[i]=m-t+a[i]-b[i]>>1;
        r[i]=m+t-a[i]+b[i]>>1;
        ans-=t;
    }
    for(int i=1;i<=n;++i)printf("%d %d\n",l[i],r[i]);
}
int main()
{
    for(int x=read();x--;)
    {
        solve();
    }
}