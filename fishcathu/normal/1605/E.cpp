#include<bits/stdc++.h>
#define ls i<<1
#define rs i<<1|1
#define pb push_back
using namespace std;
typedef long long ll;
typedef array<int,2> pii;
const int N=2E5+10,M=1E6+10;
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
int a[N],f[N];
ll q[M];
int main()
{
    int n=read();
    f[1]=1;
    for(int i=1;i<=n;++i)for(int j=i<<1;j<=n;j+=i)f[j]-=f[i];
    for(int i=1;i<=n;++i)a[i]=read();
    for(int i=1;i<=n;++i)a[i]-=read();
    --a[1];
    for(int i=1;i<=n;++i)
    {
        q[0]+=abs(a[i]);
        for(int j=i<<1;j<=n;j+=i)a[j]-=a[i];
        int u=a[i],v=f[i];
        if(!v)continue;
        if(v<0)u=-u,v=-v;
        if(u<=0)q[1]+=v;
        else
        {
            q[1]-=v;
            int t=(u-1)/v+1;
            if(t>M-10)continue;
            int w=abs(u-v*t)-abs(u-v*(t-1));
            q[t]+=w+v;
            q[t+1]+=v-w;
        }
    }
    for(int i=2;i<M;++i)q[i]+=q[i-1];
    for(int i=1;i<M;++i)q[i]+=q[i-1];
    for(int m=read();m--;)write(q[read()],'\n');
}