#include<bits/stdc++.h>
#define ls i<<1
#define rs i<<1|1
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef long long ll;
typedef array<int,2> pii;
const int N=20;
const int inf=1<<30;
auto min(auto l,auto r){return l<r?l:r;}
auto max(auto l,auto r){return l>r?l:r;}
bool cmin(auto &l,auto r){return l>r?l=r,1:0;}
bool cmax(auto &l,auto r){return l<r?l=r,1:0;}
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
const int p=1E9+7;
ll a[N];
int f(ll x,int n)
{
    if(x<0)return 0;
    x%=p;
    int ans=1;
    for(int i=1;i<=n;++i)ans=ans*(x+i)%p;
    return ans;
}
int main()
{
    int n=read();
    ll s=read();
    for(int i=0;i<n;++i)a[i]=read()+1;
    int ans=0;
    for(int k=1<<n;k--;)
    {
        ll x=s;
        for(int i=0;i<n;++i)if(k>>i&1)x-=a[i];
        if(__builtin_parity(k))ans=(ans-f(x,n-1)+p)%p;
        else ans=(ans+f(x,n-1))%p;
    }
    int x=1;
    for(int i=2;i<n;++i)x=x*1LL*i%p;
    for(int i=p-2;i;i>>=1)
    {
        if(i&1)ans=ans*1LL*x%p;
        x=x*1LL*x%p;
    }
    write(ans,'\n');
}