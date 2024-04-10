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
int f[N],a[30];
int main()
{
    const int p=1E9+7;
    int n=read();
    f[0]=1;
    for(int i=1;i<=n;++i)f[i]=f[i-1]*2%p;
    for(int i=n;i--;)++a[__builtin_ctz(read())];
    int ans=0,s=n-a[0];
    ans=(f[a[0]]-1LL)*f[s]%p;
    for(int i=1;i<30;++i)if(a[i])
    {
        s-=a[i];
        ans=(ans+(f[a[i]-1]-1LL)*f[s])%p;
    }
    write(ans,'\n');
}