#include<bits/stdc++.h>
#define ls i<<1
#define rs i<<1|1
#define pb push_back
using namespace std;
typedef long long ll;
typedef array<int,2> pii;
const int N=1E5+10;
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
const int p=998244353;
int a[N];
pii u[N],v[N];
void solve()
{
    int n=read();
    for(int i=1;i<=n;++i)a[i]=read();
    int res=0;
    for(int i=n,l=0;i>=1;--i)
    {
        int s=0,r=0;
        for(int j=1;j<=l;++j)
        {
            int t=(a[i]-1)/u[j][0]+1;
            s=(s+(t-1LL)*u[j][1])%p;
            v[++r]={a[i]/t,u[j][1]};
        }
        v[++r]={a[i],1};
        sort(v+1,v+1+r);
        l=0;
        for(int j=1;j<=r;++j)
        {
            if(v[j][0]^v[j-1][0])u[++l]=v[j];
            else u[l][1]+=v[j][1];
        }
        res=(res+s*1LL*i)%p;
    }
    write(res,'\n');
}
int main()
{
    for(int x=read();x--;)
    {
        solve();
    }
}