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
int n,m,head[MN+5],cnt=0,a[MN+5],b[MN+5],c[MN+5],ans=0,vis[MN+5],flag[MN+5];
pair<int,int> q[MN+5];
struct edge{int to,next,w;}e[MN*2+5];
inline void ins(int f,int t,int w)
{
	e[++cnt]=(edge){t,head[f],w};head[f]=cnt;	
	e[++cnt]=(edge){f,head[t],w};head[t]=cnt; 
}
void dfs(int x,int fa,int fat)
{ 
	vis[x]=1;int top=0;
	for(int i=head[x];i;i=e[i].next)
		if(!vis[e[i].to]) dfs(e[i].to,e[i].w,x);
	for(int i=head[x];i;i=e[i].next)
		if(e[i].to!=fat&&!flag[e[i].w])
			 q[++top]=make_pair(e[i].to,e[i].w);
	if(fa) q[++top]=make_pair(fat,fa);
	for(int i=2;i<=top;i+=2) a[++ans]=q[i].first,b[ans]=x,c[ans]=q[i-1].first,flag[q[i].second]=flag[q[i-1].second]=1;
}
int main()
{
	n=read();m=read();
	for(int i=1;i<=m;++i) ins(read(),read(),i);
	dfs(1,0,0);
	if(ans*2!=m) return 0*puts("No solution");
	for(int i=1;i<=ans;++i) printf("%d %d %d\n",a[i],b[i],c[i]); 
	return 0;
}