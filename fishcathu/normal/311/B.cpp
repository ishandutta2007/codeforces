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
const int N=1E5+10;
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
#define slope(x) (f[i]+sum[i]-f[x]-sum[x])*1.0/(i-x)
#define calc(x) f[x]+a[i]*1LL*(i-x)-sum[i]+sum[x]
int dis[N],a[N],q[N];
ll sum[N],f[N],g[N];
int main()
{
    int n=read(),m=read(),s=read();
    for(int i=2;i<=n;++i)dis[i]=dis[i-1]+read();
    for(int i=1;i<=m;++i)
    {
        int x=read();
        a[i]=read()-dis[x];
    }
    sort(a+1,a+1+m);
    for(int i=1;i<=m;++i)sum[i]=sum[i-1]+a[i];
    memset(f+1,0x7f,m<<3);
    while(s--)
    {
        for(int l=0,r=0,i=1;i<=m;++i)
        {
            while(l<r&&calc(q[l])>=calc(q[l+1]))++l;
            int j=q[l];
            g[i]=calc(q[l]);
            while(l<r&&slope(q[r])<slope(q[r-1]))--r;
            q[++r]=i;
        }
        memcpy(f+1,g+1,m<<3);
    }
    write(f[m],'\n');
}