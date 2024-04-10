#include<bits/stdc++.h>
#define MN 2000
#define S 0
#define T 1001
#define eps 1e-9
#define ld long double
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
ld d[T+5],in[T+5];
int n,m,q[T+5],head[T+5],cnt,top,c[T+5];
struct Edge{int u,v,a,b,c,d;}s[MN+5];
struct edge{int to,next;ld w;}e[100005];
inline void ins(int f,int t,ld w)
{
	e[++cnt]=(edge){t,head[f],w};head[f]=cnt;
	e[++cnt]=(edge){f,head[t],0};head[t]=cnt;	
}
bool bfs()
{
	for(int i=1;i<=T;++i) d[i]=1e9;int i,j;
	for(d[q[top=i=1]=S]=0;i<=top;++i)
		for(j=c[q[i]]=head[q[i]];j;j=e[j].next)
			if(e[j].w>eps&&d[q[i]]+1<d[e[j].to])
				d[q[++top]=e[j].to]=d[q[i]]+1;
	return d[T]<1e8;
}
ld dfs(int x,ld f)
{
	if(x==T) return f;ld used=0;
	for(int&i=c[x];i;i=e[i].next)
		if(e[i].w>eps&&d[e[i].to]==d[x]+1)
		{
			ld w=dfs(e[i].to,min(f-used,e[i].w));
			used+=w;e[i].w-=w;e[i^1].w+=w;
			if(f-used<eps) return f;	
		}
	return used;
}
ld Solve(ld t)
{
	cnt=1;memset(head,0,sizeof(head));
	memset(in,0,sizeof(in));
	for(int i=1;i<=m;++i)
	{
		ld l=t*s[i].a+s[i].b,r=t*s[i].c+s[i].d;
		ins(s[i].u,s[i].v,r-l);
		in[s[i].v]+=l;in[s[i].u]-=l;
	}
	ld res=0;
	for(int i=1;i<=n;++i) 
		if(in[i]>0) res+=in[i],ins(S,i,in[i]);
		else ins(i,T,-in[i]);
	while(bfs()) res-=dfs(S,1e9);
	return res;
}
int main()
{
	n=read();m=read();
	for(int i=1;i<=m;++i) 
		s[i].u=read(),s[i].v=read(),
		s[i].a=read(),s[i].b=read(),
		s[i].c=read(),s[i].d=read();
	ld l=0,r=1,ok=-1;
	for(int i=1;i<=50;++i)
	{
		ld m1=l+(r-l)/3,m2=m1+(r-l)/3;
		ld r1=Solve(m1),r2=Solve(m2);
		if(r1<eps) {ok=m1;break;}
		if(r2<eps) {ok=m2;break;}
		if(r1<r2) r=m2; else l=m1;
	}
	if(ok<0) return 0*puts("0");
	l=0,r=ok;ld L=ok,R=ok;
	for(int i=1;i<=50;++i)
	{
		ld mid=(l+r)*0.5;
		if(Solve(mid)<eps) L=mid,r=mid;
		else l=mid;	
	}
	l=ok;r=1;
	for(int i=1;i<=50;++i)
	{
		ld mid=(l+r)*0.5;
		if(Solve(mid)<eps) R=mid,l=mid;
		else r=mid;	
	}
	printf("%.10lf\n",(double)(R-L));
	return 0;
}