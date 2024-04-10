#include<bits/stdc++.h>
#define ls i<<1
#define rs i<<1|1
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef long long ll;
typedef array<int,2> pii;
const int N=110;
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
int a[N],n;
ll s;
ll f(int x){return x*(x+1LL)>>1;}
ll calc(int x){return x<n?f(x):s-f(n*2-1-x);}
void solve()
{
    n=read();
    s=f(n)+f(n-1);
    ll y=read();
    int l=1,r=n*2-1;
    while(l^r)
    {
        int m=l+0LL+r>>1;
        calc(m)<y?l=m+1:r=m;
    }
    write(l,'\n');
}
int main()
{
    for(int x=read();x--;)
    {
        solve();
    }
}