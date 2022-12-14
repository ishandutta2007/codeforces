#include<algorithm>
#include<iostream>
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
int n,head[MN+5],Q,cnt=0,from[MN+5],From[MN+5],From2[MN+5],ans,A,B,C,Ans[105],rk[MN+5],fa[MN+5],size[MN+5],Fat[MN+5];
long long dep[MN+5],mx[MN+5],mx2[MN+5],s[MN+5],mxlen,qu[105];
struct edge{int to,next,w;}e[MN*2+5];
bool cmp(int x,int y){return s[x]==s[y]?(x==C)<(y==C):s[x]>s[y];}
inline void ins(int f,int t,int w)
{
	e[++cnt]=(edge){t,head[f],w};head[f]=cnt;
	e[++cnt]=(edge){f,head[t],w};head[t]=cnt; 
}	
inline void Add(int x,int y,int Y,long long z)
{
	if(z>mx[x]) mx2[x]=mx[x],mx[x]=z,From2[x]=From[x],from[x]=y,From[x]=Y;
	else if(z>mx2[x]) mx2[x]=z,From2[x]=Y;
}
void Pre(int x,int fa)
{
	mx[x]=mx2[x]=dep[x];From[x]=From2[x]=from[x]=x;Fat[x]=fa;
	for(int i=head[x];i;i=e[i].next)
		if(e[i].to!=fa) dep[e[i].to]=dep[x]+e[i].w,Pre(e[i].to,x),Add(x,e[i].to,From[e[i].to],mx[e[i].to]);	
	if(mx[x]+mx2[x]-2*dep[x]>mxlen) mxlen=mx[x]+mx2[x]-2*dep[x],A=From[x],B=From2[x];
}
void Dfs(int x,int fa,long long y)
{
	s[x]=max(y,mx[x]-2*dep[x])+dep[x];
	for(int i=head[x];i;i=e[i].next)
		if(e[i].to!=fa) Dfs(e[i].to,x,max(y,(e[i].to==from[x]?mx2[x]:mx[x])-2*dep[x]));
}
long long Mx=1e18;
bool Find(int x,int fa)
{
	bool fg=x==B;rk[x]=x;
	for(int i=head[x];i;i=e[i].next)
		if(e[i].to!=fa) dep[e[i].to]=dep[x]+e[i].w,fg|=Find(e[i].to,x);
	if(fg&&s[x]<Mx) Mx=s[x],C=x;
	return fg;
}
inline int getfa(int x){return fa[x]?fa[x]=getfa(fa[x]):x;}
int main()
{
	n=read();
	for(int i=1,j,k;i<n;++i) j=read(),k=read(),ins(j,k,read());
	Pre(1,0);Dfs(1,0,0);Find(A,dep[A]=0);Pre(C,0);
	Q=read();sort(rk+1,rk+n+1,cmp);
	for(;Q;--Q)
	{
		long long len;scanf("%lld",&len);int ans=0;
		for(int i=1;i<=n;++i) size[i]=1,fa[i]=0;
		for(int i=1,j=1;i<=n;++i)
		{
			for(;j<=n&&s[rk[j]]-len>s[rk[i]];++j) --size[getfa(rk[j])];
			int x=getfa(rk[i]),y=getfa(Fat[rk[i]]);
			ans=max(ans,size[x]);size[y]+=size[x];fa[x]=y;
		}
		printf("%d\n",ans);
	}
	return 0;
}