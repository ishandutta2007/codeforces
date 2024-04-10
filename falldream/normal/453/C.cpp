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
int a[MN*10+5],ans,c[MN+5],b[MN+5],s[MN+5],n,m,head[MN+5],cnt=0,num=0,fr,vis[MN+5],dfn[MN+5],dn=0;
struct edge{int to,next;}e[MN*2+5];
inline int gf(int x){return s[x]?s[x]=gf(s[x]):x;}
inline void ins(int f,int t)
{
	if(gf(f)!=gf(t)) s[gf(f)]=gf(t);
	e[++cnt]=(edge){t,head[f]};head[f]=cnt;
	e[++cnt]=(edge){f,head[t]};head[t]=cnt;	
}

void Dfs(int x)
{
//	cout<<"Dfs"<<x<<endl;
	vis[a[++ans]=x]=1;c[x]^=1;dfn[x]=++dn;
	for(int i=head[x];i;i=e[i].next)
		if(!vis[e[i].to]) Dfs(e[i].to),a[++ans]=x,c[x]^=1; 
	if(c[x])
	{
		for(int i=head[x];i;i=e[i].next)	
			if(dfn[e[i].to]<dfn[x]) {a[++ans]=e[i].to;c[e[i].to]^=1;a[++ans]=x;c[x]^=1;return;}
		if(x==fr&&head[x]) a[++ans]=e[head[x]].to,a[++ans]=x,a[++ans]=e[head[x]].to,c[x]^=1;
		else puts("-1");//exit(0);
	}
}

int main()
{
	n=read();m=read();
	for(int i=1;i<=m;++i) ins(read(),read());
	for(int i=1;i<=n;++i) c[i]=read(),b[gf(i)]|=c[i];
	for(int i=1;i<=n;++i) if(gf(i)==i&&b[i]) ++num,fr=i;
	if(!num) return 0*puts("0");
	if(num>1) return 0*puts("-1");
	Dfs(fr);
	printf("%d\n",ans);
	for(int i=1;i<=ans;++i) printf("%d ",a[i]);
	return 0;
}