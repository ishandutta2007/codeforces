#include<iostream>
#include<cstring>
#include<cstdio>
#define MN 100000
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
long long Ans[MN+5],c[MN+5];
int n,m,head[MN+5],cnt=1,vis[MN+5],C[MN+5],num=0;
int Fa[MN+5],q[MN+5],top=0,col[MN+5],inq[MN+5],from;
struct edge{int to,next;}e[MN*2+5];
inline void ins(int f,int t)
{
	e[++cnt]=(edge){t,head[f]};head[f]=cnt;
	e[++cnt]=(edge){f,head[t]};head[t]=cnt;
}
void dfs(int x,int fa)
{
//	cout<<"Dfs"<<x<<" "<<fa<<endl;
	vis[x]=1;
	for(int i=head[x];i;i=e[i].next)
		if(!vis[e[i].to]) dfs(e[i].to,x),Ans[i>>1]=c[e[i].to],c[x]-=c[e[i].to],c[e[i].to]=0;
}
void Find(int x,int fa)
{
//	cout<<"F"<<x<<" "<<fa<<endl;
	vis[x]=1;q[++top]=x;inq[x]=top;Fa[x]=fa;
	for(int i=head[x];i&&!num;i=e[i].next)
		if(e[i].to!=fa)
		{
			if(vis[e[i].to])
			{
				if(col[x]^col[e[i].to]) continue;
				int t;from=x;
				//cout<<"Get"<<x<<" "<<vis[e[i].to]<<" "<<e[i].to<<endl;
				for(t=e[i].to;!inq[t];t=Fa[t]) C[++num]=t;
				for(int j=inq[t];j<=top;++j) C[++num]=q[j];
			}
			else col[e[i].to]=col[x]^1,Find(e[i].to,x);
		}
	--top;inq[x]=0;
}
int E(int x,int y)
{
	for(int i=head[x];i;i=e[i].next)
		if(e[i].to==y) return i>>1;	
}
int main()
{
	n=read();m=read();
	for(int i=1;i<=n;++i) c[i]=read();
	for(int i=1;i<=m;++i) ins(read(),read());
	Find(1,0);memset(vis,0,sizeof(vis));
	int rt=from?from:1;dfs(rt,0);
	if(c[rt]&&!from) return 0*puts("NO");
	if(c[rt])
	{
	//	cout<<"c="<<c[rt]<<endl;
		long long s=c[rt]>>1;
		for(int i=1;i<=num;++i) Ans[E(C[i],C[i%num+1])]+=(i==num?1:((i&1)?-1:1))*s;
	}
	puts("YES");
	for(int i=1;i<=m;++i) printf("%lld\n",Ans[i]);
	return 0;
}