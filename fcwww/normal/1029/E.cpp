#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define N 200050
int head[N],to[N<<1],nxt[N<<1],cnt,n;
int f[N],g[N],h[N],dep[N],ans;
inline void add(int u,int v) {
	to[++cnt]=v; nxt[cnt]=head[u]; head[u]=cnt;
}
void dfs(int x,int y) {
	int i;
	dep[x]=dep[y]+1;
	int mn=1<<30;
	g[x]=1;
	for(i=head[x];i;i=nxt[i]) if(to[i]!=y) {
		dfs(to[i],x);
		f[x]+=min(f[to[i]],g[to[i]]);
		mn=min(mn,max(0,g[to[i]]-f[to[i]]));
		g[x]+=min(f[to[i]],min(g[to[i]],h[to[i]]));
		h[x]+=min(f[to[i]],g[to[i]]);
	}
	if(dep[x]>3) f[x]+=mn;
}
int main() {
	scanf("%d",&n);
	int i,x,y;
	for(i=1;i<n;i++) scanf("%d%d",&x,&y),add(x,y),add(y,x);
	dep[1]=1;
	dfs(1,0);
	for(i=1;i<=n;i++) if(dep[i]==3) ans+=min(f[i],g[i]);
	printf("%d\n",ans);
}