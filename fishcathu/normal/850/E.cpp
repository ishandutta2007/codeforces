#include<bits/stdc++.h>
#define ls i<<1
#define rs i<<1|1
#define pb push_back
using namespace std;
typedef long long ll;
typedef array<int,2> pii;
const int N=1<<20;
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
const int p=1E9+7;
int a[N],n;
void fwt()
{
    for(int i=2,j=1;j<n;i<<=1,j<<=1)
    {
        for(int x=0;x<n;x+=i)
        {
            for(int y=0;y<j;++y)
            {
                int u=a[x+y],v=a[x+y+j];
                a[x+y]=(u+v)%p;
                a[x+y+j]=(u-v+p)%p;
            }
        }
    }
}
int main()
{
    int m=read();
    n=1<<m;
    for(int i=0;i<n;++i)scanf("%1d",a+i);
    fwt();
    for(int i=0;i<n;++i)a[i]=a[i]*1LL*a[i]%p;
    fwt();
    int ans=0;
    for(int i=0;i<n;++i)ans=(ans+a[i]*(1LL<<m-__builtin_popcount(i)))%p;
    for(int i=p-2,j=n;i;i>>=1)
    {
        if(i&1)ans=ans*1LL*j%p;
        j=j*1LL*j%p;
    }
    write(ans*3LL%p,'\n');
}