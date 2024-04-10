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
const int N=601;
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
int head[N],nex[N*N],to[N*N],val[N*N];
int dis[N],q[N],f[N],s,n;
void push(int x,int val)
{
    if(val>=dis[x])return;
    dis[x]=val;
    int i=f[x]?f[x]:++s;
    while(val<dis[q[i>>1]])
    {
        f[q[i]=q[i>>1]]=i;
        i>>=1;
    }
    f[q[i]=x]=i;
}
void pop()
{
    int x=q[s--],i=1;
    while(ls<=s)
    {
        int t=ls==s||dis[q[ls]]<dis[q[rs]]?ls:rs;
        if(dis[q[t]]>=dis[x])break;
        f[q[i]=q[t]]=i;
        i=t;
    }
    f[q[i]=x]=i;
}
void dij(int y)
{
    memset(dis,0x3f,n<<2);
    push(y,0);
    while(s)
    {
        int x=q[1];
        pop();
        f[x]=0;
        if(x!=y)push((x+1)%n,dis[x]+1);
        for(int i=head[x];i;i=nex[i])
        {
            int u=(to[i]+dis[x])%n,v=dis[x]+val[i];
            push(u,v);
            push((y+1)%n,v+(y+1-u+n)%n);
        }
    }
    for(int i=0;i<n;++i)write(dis[i],' ');
    putchar('\n');
}
int main()
{
    n=read();
    for(int m=read(),cnt=0;m--;)
    {
        int u=read();
        nex[++cnt]=head[u];
        head[u]=cnt;
        to[cnt]=read();
        val[cnt]=read();
    }
    q[0]=n+1;
    for(int i=0;i<n;++i)dij(i);
}