#include<iostream>
#include<cstring>
#include<cstdio>
#define MN 200000
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
long long Ans[MN+5],s[MN+5];char st[MN+5];bool b[MN+5],ok[1<<20];
int n,head[MN+5],cnt,size[MN+5],mx[MN+5],tot,mn=1e9,rt,now;
int q[MN+5],top,a[MN+5],c[MN+5],vis[1<<20],num[1<<20],Fa[MN+5];
struct edge{int to,next;}e[MN*2+5];
inline void ins(int f,int t)
{
	e[++cnt]=(edge){t,head[f]};head[f]=cnt;
	e[++cnt]=(edge){f,head[t]};head[t]=cnt;	
}
void Dfs(int x,int fa)
{
	size[x]=1;mx[x]=0;q[++top]=x;if(ok[c[x]]) ++s[x];
	for(int i=head[x];i;i=e[i].next)
		if(e[i].to!=fa&&!b[e[i].to]) 
			Fa[e[i].to]=x,c[e[i].to]=c[x]^a[e[i].to],Dfs(e[i].to,x),
			size[x]+=size[e[i].to],mx[x]=max(mx[x],size[e[i].to]);	
}
void GetRt(int x,int fa)
{
	for(int i=head[x];i;i=e[i].next)
		if(e[i].to!=fa&&!b[e[i].to]) GetRt(e[i].to,x);	
	int Sz=max(tot-size[x],mx[x]);
	if(Sz<mn) mn=Sz,rt=x;
}
inline int F(int x){return vis[x]==now?num[x]:0;}
void Calcval(int l,int r,int S,int v)
{
	++now;
	for(int i=l;i<=r;++i) 
	{
		if(vis[c[q[i]]]!=now) vis[c[q[i]]]=now,num[c[q[i]]]=0;
		++num[c[q[i]]];	
	}
	for(int i=l;i<=r;++i) 
	{
		int V=c[q[i]]^a[S];s[q[i]]+=v*F(V);s[S]-=v*F(V);
		for(int j=1;j<1<<20;j<<=1) s[S]-=v*F(V^j),s[q[i]]+=v*F(V^j);
	}
}
void Solve(int x)
{
	b[x]=1;top=0;int pretop=0;Fa[x]=0;
	for(int i=head[x];i;i=e[i].next)
		if(!b[e[i].to]) Fa[e[i].to]=x,c[e[i].to]=a[x]^a[e[i].to],Dfs(e[i].to,x),
						Calcval(pretop+1,top,x,-1),pretop=top;	
	Calcval(1,top,x,1);s[x]>>=1;
	for(int i=top;i;--i) Ans[q[i]]+=s[q[i]],s[Fa[q[i]]]+=s[q[i]],s[q[i]]=0;
	Ans[x]+=s[x];s[x]=0;
	for(int i=head[x];i;i=e[i].next)
		if(!b[e[i].to]) tot=size[e[i].to],mn=1e9,GetRt(e[i].to,x),Solve(rt);
}
int main()
{
	ok[0]=1;
	for(int i=1;i<1<<20;i<<=1) ok[i]=1;
	tot=n=read();
	for(int i=1;i<n;++i) ins(read(),read());
	scanf("%s",st+1);
	for(int i=1;i<=n;++i) a[i]=1<<st[i]-'a';
	Dfs(1,0);GetRt(1,0);
	memset(s,0,sizeof(s));Solve(rt);
	for(int i=1;i<=n;++i) printf("%lld ",Ans[i]+1);
	return 0;
}