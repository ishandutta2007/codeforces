#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
namespace FLOW
{
    #define S 0
    #define T 9100  
    #define MM 4000000
    #define INF 2000000000
    int d[T+5],q[T+5],head[T+5],c[T+5],cnt,top;
    struct edge{int to,next,w;}e[MM+5];
    void init(){cnt=1;memset(head,0,sizeof(head));}
    inline void ins(int f,int t,int w)
    {
        e[++cnt]=(edge){t,head[f],w};head[f]=cnt;    
        e[++cnt]=(edge){f,head[t],0};head[t]=cnt;
    }
    bool bfs()
    {
        memset(d,0,sizeof(d));int i,j;
        for(d[q[top=i=1]=S]=1;i<=top;++i)
            for(j=c[q[i]]=head[q[i]];j;j=e[j].next)
                if(e[j].w&&!d[e[j].to]) d[q[++top]=e[j].to]=d[q[i]]+1;
        return d[T];    
    }
    int dfs(int x,int f)
    {
        if(x==T) return f;int used=0;    
        for(int&i=c[x];i;i=e[i].next)
            if(e[i].w&&d[e[i].to]==d[x]+1)
            {
                int w=dfs(e[i].to,min(f-used,e[i].w));
                e[i].w-=w;e[i^1].w+=w;used+=w;
                if(used==f) return f;    
            }
        return d[x]=-1,used;
    }
    int dinic()
    {
        int ans=0;
        while(bfs()) ans+=dfs(S,INF);
        return ans;
    }
    #undef MM
}
#define MN 3000
int n,head[MN+5],cnt=0,tot,num[MN+5],P[MN+5],p[MN+5],vis[MN+5];
struct edge{int to,next,w;}e[MN*2+5]; 
inline void ins(int f,int t,int w)
{
	e[++cnt]=(edge){t,head[f],w};head[f]=cnt;
	e[++cnt]=(edge){f,head[t],w};head[t]=cnt;	
}

void Dfs(int x,int mid)
{
	P[tot]+=p[x];++num[tot];vis[x]=1;
	for(int i=head[x];i;i=e[i].next)
		if(e[i].w<mid&&!vis[e[i].to]) Dfs(e[i].to,mid);
}

void Build(int x,int l,int r)
{
	if(l==r) FLOW::ins(x+tot,T,P[l]);	
	else 
	{
		int mid=l+r>>1;
		FLOW::ins(x+tot,(x<<1)+tot,INF);Build(x<<1,l,mid);
		FLOW::ins(x+tot,(x<<1|1)+tot,INF);Build(x<<1|1,mid+1,r);
	}
}

void Insert(int x,int lt,int rt,int l,int r,int from)
{
	if(lt==l&&rt==r) {FLOW::ins(from,x+tot,INF);return;} 
	int mid=lt+rt>>1;
	if(r<=mid) Insert(x<<1,lt,mid,l,r,from);
	else if(l>mid) Insert(x<<1|1,mid+1,rt,l,r,from);
	else Insert(x<<1,lt,mid,l,mid,from),Insert(x<<1|1,mid+1,rt,mid+1,r,from);
} 

int main()
{
	n=read();
	for(int i=1,j,k;i<n;++i) j=read(),k=read(),ins(j,k,read());
	for(int i=1;i<=n;++i) p[i]=read();
	int l=1,r=10000,mid,res=0;
	while(l<=r)
	{
		mid=l+r>>1;
		memset(vis,0,sizeof(vis));
		tot=0;FLOW::init();
		for(int i=1;i<=n;++i) if(!vis[i]) P[++tot]=0,num[tot]=0,Dfs(i,mid);
		Build(1,1,tot);
		for(int i=1;i<=tot;++i) 
		{
			FLOW::ins(S,i,num[i]);
			if(i>1) Insert(1,1,tot,1,i-1,i);
			if(i<tot) Insert(1,1,tot,i+1,tot,i);
		}
		if(FLOW::dinic()==n) res=mid,l=mid+1;
		else r=mid-1;
	}
	printf("%d\n",res);
	return 0;
}