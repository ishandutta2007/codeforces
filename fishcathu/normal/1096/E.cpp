#include<bits/stdc++.h>
#define ls i<<1
#define rs i<<1|1
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long ll;
typedef vector<int> vct;
typedef pair<int,int> pii;
const int N=5100,M=100;
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
const int p=998244353;
int u[N],d[N],ny[N];
void init()
{
    u[0]=d[0]=ny[0]=ny[1]=1;
    for(int i=2;i<N;++i)ny[i]=(p-p/i)*1LL*ny[p%i]%p;
    for(int i=1;i<N;++i)
    {
        u[i]=u[i-1]*1LL*i%p;
        d[i]=d[i-1]*1LL*ny[i]%p;
    }
}
int c(int l,int r)
{
    if(l==r)return 1;
    if(r<0||r>l)return 0;
    return u[l]*1LL*d[r]%p*d[l-r]%p;
}
int f(int s,int n,int m)
{
    int res=0;
    for(int i=0,j=1;i<=n;++i,j=p-j)
    {
        res=(res+j*1LL*c(n,i)%p*c(s-i*m-i+n-1,n-1))%p;
    }
    return res;
}
int main()
{
    init();
    int n=read()-1,s=read(),y=read();
    int ans=0;
    for(int i=y;i<=s;++i)
    {
        for(int j=0;j<=n;++j)
        {
            ans=(ans+ny[j+1]*1LL*c(n,j)%p*f(s-i*j-i,n-j,i-1))%p;
        }
    }
    for(int i=p-2,j=c(s-y+n,n);i;i>>=1)
    {
        if(i&1)ans=ans*1LL*j%p;
        j=j*1LL*j%p;
    }
    write(ans,'\n');
}