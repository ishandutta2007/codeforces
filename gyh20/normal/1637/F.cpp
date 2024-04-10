#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int t,n,m,a[1000002],A,B,f[1000002],head[1000002],cnt,g[1000002],h[1000002];
char s[1000002];
long long ans;
vector<int>V[1000002];
struct edge{int to,next;}e[2000002];
inline void add(re int x,re int y){
	e[++cnt]=(edge){y,head[x]},head[x]=cnt;
}
inline void dfs(re int x,re int y){
	for(re int i=head[x];i;i=e[i].next)
		if(e[i].to^y){
			dfs(e[i].to,x);
			re int z=max(f[e[i].to],a[e[i].to]);V[x].push_back(z);
			if(z>f[x])g[x]=f[x],f[x]=z;
			else if(z>g[x])g[x]=z;
		}
}
inline void dfs1(re int x,re int y){
	V[x].push_back(h[x]);
	sort(V[x].begin(),V[x].end());
	reverse(V[x].begin(),V[x].end());
	V[x].push_back(0);
	ans+=max(0,a[x]-V[x][0]),ans+=max(0,a[x]-V[x][1]);
	for(re int i=head[x];i;i=e[i].next)
		if(e[i].to^y){
			re int z=h[x];z=max(z,a[x]);
			if(max(f[e[i].to],a[e[i].to])==f[x])z=max(z,g[x]);
			else z=max(z,f[x]);h[e[i].to]=z;
			dfs1(e[i].to,x);
		}
}
int main(){
	n=read();
	for(re int i=1;i<=n;++i)a[i]=read();
	for(re int i=1;i<n;++i){
		re int x=read(),y=read();
		add(x,y),add(y,x);
	}
	dfs(1,1),dfs1(1,1);printf("%lld",ans);
}