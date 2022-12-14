#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
#include<cstdio>
#include<cmath>
#include<queue>
#include<map>
#include<set>
#define N 131072
#define MN 100000
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
long long ans=0,dep[MN+5];set<int> st[MN+5];
int n,head[MN+5],cnt=0,mx[MN+5],size[MN+5],mn=1e9,rt,now,p[MN+5],bel[MN+5];
struct edge{int to,next,w;}e[MN*2+5];
pair<int,int> T[N*2+5];int t[N*2+5];

inline void ins(int f,int t,int w)
{
    e[++cnt]=(edge){t,head[f],w};head[f]=cnt;
    e[++cnt]=(edge){f,head[t],w};head[t]=cnt;
}

void GetRt(int x,int fa)
{
    size[x]=1;mx[x]=0;
    for(int i=head[x];i;i=e[i].next)
        if(e[i].to!=fa)
        {
            GetRt(e[i].to,x);
            size[x]+=size[e[i].to];
            mx[x]=max(mx[x],size[e[i].to]);
        }
    if(max(n-size[x],mx[x])<mn) mn=max(n-size[x],mx[x]),rt=x;
}

void dfs(int x,int fa)
{
    ans+=2*dep[x];size[x]=1;st[bel[x]=now].insert(x);
    for(int i=head[x];i;i=e[i].next)
        if(e[i].to!=fa) dep[e[i].to]=dep[x]+e[i].w,dfs(e[i].to,x),size[x]+=size[e[i].to];
}
void Renew(int x,int ad){for(T[x+=N].first+=ad;x>>=1;)T[x]=max(T[x<<1],T[x<<1|1]);}
void renew(int x,int v){for(t[x+=N]=v;x>>=1;)t[x]=min(t[x<<1],t[x<<1|1]);}
int Query(int l,int r)
{
    int res=1e9;
    for(l+=N-1,r+=N+1;l^r^1;l>>=1,r>>=1)
    {
        if(~l&1) res=min(res,t[l+1]);
        if( r&1) res=min(res,t[r-1]);
    }
    return res;
}
inline void Up(int x){renew(x,st[x].size()?*st[x].begin():1e9);}
int main()
{
    n=read();memset(t,63,sizeof(t));
    for(int i=1,j,k;i<n;++i) j=read(),k=read(),ins(j,k,read());
    GetRt(1,0);
    for(int i=1;i<=n;++i) T[i+N].second=i;
    for(int i=head[rt];i;i=e[i].next)
    {
        dep[e[i].to]=e[i].w;dfs(now=e[i].to,rt);
        Renew(e[i].to,2*size[e[i].to]);Up(e[i].to);
    }
    bel[rt]=rt;st[rt].insert(rt);Up(rt);
    for(int i=1,v;i<=n;++i)
    {
        Renew(bel[i],-1);
        if(T[1].first>n-i) v=*st[T[1].second].begin();
        else
        {
            v=n+1;
            if(bel[i]>1) v=min(v,Query(1,bel[i]-1));
            if(bel[i]<n) v=min(v,Query(bel[i]+1,n));
            if(i==rt) v=min(v,i);
        }
        Renew(bel[v],-1),st[bel[v]].erase(st[bel[v]].find(v)),Up(bel[v]);p[i]=v;
    }
    printf("%lld\n",ans);
    for(int i=1;i<=n;++i) printf("%d ",p[i]);
    return 0;
}