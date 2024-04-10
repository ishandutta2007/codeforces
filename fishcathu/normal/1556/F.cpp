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
const int M=14,N=1<<M;
const int inf=1<<30;
auto max(auto l,auto r){return l>r?l:r;}
auto min(auto l,auto r){return l<r?l:r;}
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
int a[M],b[M][M],c[M][N];
int f[N],g[N];
int main()
{
    const int p=1E9+7;
    int m=read(),n=(1<<m)-1;
    for(int i=0;i<m;++i)a[i]=read();
    for(int i=0;i<m;++i)
    {
        for(int j=0;j<m;++j)
        {
            b[i][j]=a[i];
            for(int k=p-2,t=a[i]+a[j];k;k>>=1)
            {
                if(k&1)b[i][j]=b[i][j]*1LL*t%p;
                t=t*1LL*t%p;
            }
        }
    }
    for(int i=0;i<m;++i)
    {
        c[i][0]=1;
        for(int j=1;j<=n;++j)
        {
            if(j>>i&1)continue;
            int t=__lg(j);
            c[i][j]=c[i][j^1<<t]*1LL*b[i][t]%p;
        }
    }
    f[0]=-1;
    int ans=0;
    for(int i=1;i<=n;++i)
    {
        g[i]=1;
        for(int j=i,k=n^i;(--j&=i)^i;)
        {
            int t=__lg(j^i);
            g[j]=g[j^1<<t]*1LL*c[t][k]%p;
            f[i]=(f[i]+(p-f[j])*1LL*g[j])%p;
        }
        ans=(ans+f[i]*1LL*__builtin_popcount(i))%p;
    }
    write(ans,'\n');
}