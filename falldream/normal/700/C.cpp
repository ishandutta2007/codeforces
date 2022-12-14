#include<iostream>
#include<cstring>
#include<cstdio>
#define MN 1000
#define MM 30000
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int n,m,s[MN+5],head[MN+5],cnt=0,S,T,q[MN+5],top,Q[MN+5],num,cut[MM+5],dfn[MN+5],dn,low[MN+5],mn,from;
struct Edge{int to,next,w,id;}e[MM*2+5];
struct edge{int x,y,w;}E[MM+5];
inline int gf(int x){return s[x]?s[x]=gf(s[x]):x;} 

inline void ins(int f,int t,int w,int id=0)
{
	e[++cnt]=(Edge){t,head[f],w,id};head[f]=cnt;
	e[++cnt]=(Edge){f,head[t],w,id};head[t]=cnt;	
}

void dfs(int x,int fa)
{ 
	if(x==T){memcpy(Q,q,sizeof(q));num=top;}
	for(int i=head[x];i;i=e[i].next) 
		if(e[i].to!=fa) q[++top]=e[i].w,dfs(e[i].to,x),--top;
}

void Tarjan(int x,int fa)
{
	dfn[x]=low[x]=++dn;
	for(int i=head[x];i;i=e[i].next)
		if(e[i].id!=fa)
		{
			if(!dfn[e[i].to]) 
			{
				Tarjan(e[i].to,e[i].id),low[x]=min(low[x],low[e[i].to]);
				if(low[e[i].to]>dfn[x]) 
					if(dfn[T]&&dfn[T]>=dfn[e[i].to]&&e[i].w<mn) mn=e[i].w,from=e[i].id;	
			}
			else low[x]=min(low[x],dfn[e[i].to]);	  
		}
	
}
#define INF 2100000000
int ans=INF,Anum,a,b;
void Merge(int x,int y){if(x!=y) s[x]=y;}
void R(int res,int nn,int A,int B=0) {if(res<ans) ans=res,Anum=nn,a=A,b=B;} 
#define ms(x) memset(x,0,sizeof(x))
int main()
{
	n=read();m=read();S=read();T=read(); 
	for(int i=1;i<=m;++i)
	{
		E[i].x=read();E[i].y=read();E[i].w=read();
		if(gf(E[i].x)!=gf(E[i].y)) s[gf(E[i].x)]=gf(E[i].y),ins(E[i].x,E[i].y,i);
	}
	if(gf(S)!=gf(T)) return 0*puts("0\n0"); 
	dfs(S,0); 
	for(int i=1;i<=num;++i)
	{
		ms(head);ms(cut);ms(dfn);ms(low);ms(s);cnt=dn=0;
		for(int j=1;j<=m;++j) if(j!=Q[i]) ins(E[j].x,E[j].y,E[j].w,j);	
		mn=INF;Tarjan(S,0);
		if(!dfn[T]) R(E[Q[i]].w,1,Q[i]);
		else if(mn<INF) R(E[Q[i]].w+mn,2,Q[i],from);
	}
	if(ans==INF) return 0*puts("-1");
	printf("%d\n%d\n%d",ans,Anum,a);
	if(Anum==2) printf(" %d",b);
	return 0;
}