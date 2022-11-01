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
const int N=1048580,M=46580;
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
int a[N],b[2000010],vt[N],tot;
int head[N],nex[M],to[M],val[M],cnt=1;
int dis[N],pre[N],las[N];
bool op[M],st[N];
queue<int>q;
void add(int u,int v,int w,bool p)
{
    nex[++cnt]=head[u];
    head[u]=cnt;
    to[cnt]=v;
    val[cnt]=w;
    op[cnt]=p;
}
void push(int x,int d,int p,int l)
{
    if(d<=dis[x])return;
    dis[x]=d;
    pre[x]=p;
    las[x]=l;
    if(!st[x])q.push(x),st[x]=1;
}
int main()
{
    int n=read(),y=1<<n,z=y+1,s=min(read(),y>>1);
    for(int i=0;i<y;++i)
    {
        a[i]=read();
        for(int j=y;j>>=1;)if(i&j)++b[a[i]+a[i^j]];
    }
    for(int i=0,t=n*y/2-(n*2-1)*(s-1)-1;t>0;)b[i]?--b[i],--t:++i;
    for(int i=0;i<y;++i)
    {
        for(int j=y;j>>=1;)
        {
            if(i&j)continue;
            int u=i,v=i^j,w=a[u]+a[v];
            if(!b[w])continue;
            if(__builtin_popcount(u)&1)swap(u,v);
            if(!st[u])add(y,u,0,1),add(u,y,0,0),st[u]=1;
            if(!st[v])add(v,z,0,1),add(z,v,0,0),st[v]=1;
            add(u,v,w,1),add(v,u,-w,0);
            --b[w];
        }
    }
    for(int i=0;i<y;++i)if(st[i])st[vt[++tot]=i]=0;
    vt[++tot]=y,vt[++tot]=z;
    int ans=0;
    while(s--)
    {
        for(int i=1;i<=tot;++i)dis[vt[i]]=-inf;
        push(y,0,0,0);
        while(!q.empty())
        {
            int x=q.front();
            q.pop();
            st[x]=0;
            for(int i=head[x];i;i=nex[i])if(op[i])push(to[i],dis[x]+val[i],x,i);
        }
        ans+=dis[z];
        for(int i=z;i^y;i=pre[i])op[las[i]]^=1,op[las[i]^1]^=1;
    }
    write(ans,'\n');
}