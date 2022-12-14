#include<iostream>
#include<cstdio>
#define MN 300000
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int n,m,Q,s[MN+5],len[MN+5],head[MN+5],cnt=0,f[MN+5],mx[MN+5],vis[MN+5];
struct edge{int to,next;}e[MN*2+5];
#define S(x) ((x+1)/2)
inline int getfa(int x){return s[x]?s[x]=getfa(s[x]):x;}
inline void Merge(int x,int y){len[y]=max(max(len[x],len[y]),S(len[y])+1+S(len[x])),s[x]=y;}
inline void ins(int f,int t)
{
	e[++cnt]=(edge){t,head[f]};head[f]=cnt;
	e[++cnt]=(edge){f,head[t]};head[t]=cnt;	
}
void Dp(int x,int fa)
{
	vis[x]=1;
	for(int i=head[x];i;i=e[i].next)
		if(e[i].to!=fa)
		{
			Dp(e[i].to,x);
			f[x]=max(f[x],f[e[i].to]);
			f[x]=max(f[x],mx[x]+1+mx[e[i].to]);
			mx[x]=max(mx[x],mx[e[i].to]+1);
		}
}	

int main()
{
	n=read();m=read();Q=read();
	for(int i=1;i<=m;++i) 
	{
		int x=read(),y=read();
		ins(x,y);s[getfa(x)]=getfa(y);
	}
	for(int i=1;i<=n;++i) if(!vis[i]) Dp(i,0),len[getfa(i)]=f[i];
	for(int i=1;i<=Q;++i)
		if(read()==1) printf("%d\n",len[getfa(read())]);
		else 
		{
			int x=read(),y=read();
			if(getfa(x)!=getfa(y)) Merge(getfa(x),getfa(y));
		}	
	return 0;
}