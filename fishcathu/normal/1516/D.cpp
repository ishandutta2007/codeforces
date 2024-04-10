#include<bits/stdc++.h>
#define ls i<<1
#define rs i<<1|1
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int N=1E5+1;
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
int pre[N],pri[9593];
int b[N];
int head[N],nex[N],to[N],cnt;
int fa[N],siz[N],top[N],dep[N],son[N];
vector<int>q[N];
void init()
{
    for(int i=2,s=0;i<N;++i)
    {
        if(!pre[i])
        {
            pri[++s]=i;
            pre[i]=i;
        }
        for(int j=1;j<=s;++j)
        {
            int t=i*pri[j];
            if(t>=N)break;
            pre[t]=pri[j];
            if(!(i%pri[j]))break;
        }
    }
}
void add(int u,int v)
{
    nex[++cnt]=head[u];
    head[u]=cnt;
    to[cnt]=v;
}
void dfs1(int x)
{
    siz[x]=1;
    son[x]=x;
    for(int i=head[x];i;i=nex[i])
    {
        int t=to[i];
        dep[t]=dep[x]+1;
        dfs1(t);
        if(siz[t]>=siz[son[x]])son[x]=t;
        siz[x]+=siz[t];
    }
}
void dfs2(int x,int p)
{
    top[x]=p;
    q[p].push_back(x);
    for(int i=head[x];i;i=nex[i])
    {
        int t=to[i];
        dfs2(t,t==son[x]?p:t);
    }
}
int main()
{
    init();
    int n=read(),m=read();
    for(int i=1;i<=n;++i)
    {
        fa[i]=fa[i-1];
        int x=read();
        while(x!=1)
        {
            int t=pre[x];
            do x/=t;while(!(x%t));
            fa[i]=max(fa[i],b[t]);
            b[t]=i;
        }
        add(fa[i],i);
    }
    dfs1(0);
    dfs2(0,0);
    while(m--)
    {
        int l=read(),r=read();
        int k=top[r];
        while(k&&fa[k]>=l)
        {
            k=top[fa[k]];
        }
        l=*lower_bound(q[k].begin(),q[k].end(),l);
        write(dep[r]-dep[l]+1,'\n');
    }
}