#include<bits/stdc++.h>
#define ls i<<1
#define rs i<<1|1
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int N=2E5+10;
const int inf=1<<30;
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
ll a[N],f[N][18];
ll g(int l,int r)
{
    int t=__lg(r-l+1);
    return __gcd(f[l][t],f[r-(1<<t)+1][t]);
}
void solve()
{
    int n=read();
    for(int i=1;i<=n;++i)a[i]=read();
    --n;
    for(int i=1;i<=n;++i)f[i][0]=abs(a[i+1]-a[i]);
    for(int j=1,k=2;k<=n;++j,k<<=1)
    {
        for(int i=n-k+1;i>=1;--i)
        {
            f[i][j]=__gcd(f[i][j-1],f[i+k/2][j-1]);
        }
    }
    int ans=-1;
    for(int l=1,r=1;r<=n;++r)
    {
        while(l<=r&&g(l,r)==1)++l;
        ans=max(ans,r-l);
    }
    write(ans+2,'\n');
}
int main()
{
    for(int x=read();x--;)
    {
        solve();
    }
}