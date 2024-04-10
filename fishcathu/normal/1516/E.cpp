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
const int N=410;
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
int f[N][N>>1],c[N][N],d[N];
int main()
{
    const int p=1E9+7;
    int y=read(),m=read(),n=min(y,m<<1);
    c[0][0]=d[0]=d[1]=1;
    for(int i=1;i<=n;++i)
    {
        c[i][0]=1;
        for(int j=1;j<=i;++j)
        {
            c[i][j]=(c[i-1][j-1]+c[i-1][j])%p;
        }
    }
    for(int i=2;i<=n;++i)d[i]=(p-p/i)*1LL*d[p%i]%p;
    for(int i=1;i<=n;++i)d[i]=d[i]*1LL*d[i-1]%p*(y-i+1)%p;
    for(int i=0;i<=m;i+=2)f[0][i]=1;
    for(int i=1;i<=n;++i)
    {
        f[i][0]=1;
        for(int j=1;j<=m;++j)
        {
            f[i][j]=(f[i-1][j]+(i-1)*1LL*f[i-1][j-1])%p;
        }
    }
    for(int j=1;j<=m;++j)
    {
        for(int i=n;i>=1;--i)
        {
            for(int k=i,op=-1;k--;op=-op)
            {
                f[i][j]=(f[i][j]+c[i][k]*1LL*f[k][j]*op)%p;
            }
        }
    }
    for(int j=1;j<=m;++j)
    {
        int ans=0;
        for(int i=0;i<=n;++i)
        {
            ans=(ans+d[i]*1LL*f[i][j])%p;
        }
        write((ans+p)%p,' ');
    }
}