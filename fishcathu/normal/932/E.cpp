#include<bits/stdc++.h>
#define ls i<<1
#define rs i<<1|1
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef long long ll;
typedef array<int,2> pii;
const int N=5010;
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
int f[N][N];
int qpow(int x,int n){int ans=1;while(n){if(n&1)ans=ans*1LL*x%p;x=x*1LL*x%p,n>>=1;}return ans;}
int main()
{
    int n=read(),m=read(),ans=0;
    f[0][0]=1;
    for(int i=1;i<=m;++i)for(int j=1;j<=i;++j)f[i][j]=(f[i-1][j-1]+f[i-1][j]*1LL*j)%p;
    for(int i=min(n,m);i>=1;--i)
    {
        int res=f[m][i]*1LL*qpow(2,n-i)%p;
        for(int j=0;j<i;++j)res=res*1LL*(n-j)%p;
        ans=(ans+res)%p;
    }
    write(ans,'\n');
}