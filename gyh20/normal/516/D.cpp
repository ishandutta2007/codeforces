#include<cstdio>
#include<algorithm>
using namespace std;
#define re register
inline long long read(){
	re long long t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int n,m,head[100002],cnt,p[100002],mx,d1,d2,f[100002],siz[100002],fa[100002],q,ans;
struct edge{int to,next,w;}e[200002];
inline void add(re int x,re int y,re int z){e[++cnt]=(edge){y,head[x],z},head[x]=cnt;}
inline int root(re int x){return x==fa[x]?x:fa[x]=root(fa[x]);}
long long dis[100002],d[100002];
inline void dfs(re int x,re int y,re long long w){
	if((d[x]=w)>d[mx])mx=x;dis[x]=max(dis[x],d[x]);
	for(re int i=head[x];i;i=e[i].next)if(e[i].to^y)dfs(e[i].to,x,w+e[i].w);
}
inline void dfs(re int x,re int y){f[x]=y;for(re int i=head[x];i;i=e[i].next)if(e[i].to^y)dfs(e[i].to,x);}
inline bool cmp(re int x,re int y){return dis[x]>dis[y];}
int main(){
	n=read();for(re int i=1;i<=n;++i)p[i]=i;
	for(re int i=1,x,y,z;i<n;++i)x=read(),y=read(),z=read(),add(x,y,z),add(y,x,z);
	dfs(1,1,0),d1=mx,mx=0,dfs(d1,d1,0),d2=mx,dfs(d2,d2,0),sort(p+1,p+n+1,cmp),dfs(p[n],p[n]),q=read();
	while(q--){
		re long long x=read();ans=1;
		for(re int i=1;i<=n;++i)fa[i]=i,siz[i]=1;
		re int l=1;
		for(re int i=1;i<=n;++i){
			while(dis[p[l]]-dis[p[i]]>x)--siz[root(p[l])],++l;
			ans=max(ans,siz[p[i]]),fa[p[i]]=f[p[i]],siz[root(f[p[i]])]+=siz[p[i]];
		}
		printf("%d\n",ans);
	}
}