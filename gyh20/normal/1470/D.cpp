#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int n,m,t,head[600002],cnt,vis[300002],fa[300002],d[300002],v[300002],f[300002];
inline int root(re int x){return x==fa[x]?x:fa[x]=root(fa[x]);}
struct edge{int to,next;}e[600002];
inline void add(re int x,re int y){
	e[++cnt]=(edge){y,head[x]};
	head[x]=cnt,++d[x];
}
inline void dfs(re int x,re int y){
	f[x]=y;
	for(re int i=head[x];i;i=e[i].next)if(!f[e[i].to])dfs(e[i].to,x);
}
inline void dfs1(re int x,re int y){
	re bool ia=1;
	for(re int i=head[x];i;i=e[i].next)if(vis[e[i].to])ia=0;
	if(ia)vis[x]=1;
	for(re int i=head[x];i;i=e[i].next)if(f[e[i].to]==x)dfs1(e[i].to,x);
}
int main(){
	t=read();
	while(t--){
		n=read(),m=read(),cnt=0;
		for(re int i=1;i<=n;++i)fa[i]=i,head[i]=vis[i]=d[i]=v[i]=f[i]=0;
		for(re int i=1,x,y;i<=m;++i)x=read(),y=read(),add(x,y),add(y,x),fa[root(x)]=root(y);
		re bool ia=1;
		for(re int i=1;i<=n;++i)if(root(i)^root(1))ia=0;
		if(!ia){
			puts("NO");
			continue;
		}
		f[1]=1,dfs(1,1),dfs1(1,1);
		puts("YES");
		re int s=0;
		for(re int i=1;i<=n;++i)s+=vis[i];
		printf("%d\n",s);
		for(re int i=1;i<=n;++i)if(vis[i])printf("%d ",i);
		puts("");
	}
}