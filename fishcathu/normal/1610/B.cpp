#include<bits/stdc++.h>
#define ls i<<1
#define rs i<<1|1
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef long long ll;
typedef array<int,2> pii;
const int N=2E5+10;
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
int a[N],b[N],n;
bool check(int x)
{
    int m=0;
    for(int i=1;i<=n;++i)if(a[i]^x)b[++m]=a[i];
    for(int l=1,r=m;l<r;++l,--r)
    {
        if(b[l]^b[r])
        {
            return 0;
        }
    }
    return 1;
}
bool solve()
{
    n=read();
    for(int i=1;i<=n;++i)a[i]=read();
    for(int l=1,r=n;l<r;++l,--r)
    {
        if(a[l]^a[r])
        {
            return check(a[l])||check(a[r]);
        }
    }
    return 1;
}
int main()
{
    for(int x=read();x--;)
    {
        puts(solve()?"YES":"NO");
    }
}