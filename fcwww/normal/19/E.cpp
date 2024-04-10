#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
#define N 200050
int head[N],to[N<<1],nxt[N<<1],vis[N],cnt=1,n,m,lst;
int odd[N],even[N],fa[N],dep[N],pp[N],ans[N],can[N];
inline void add(int u,int v) {
	to[++cnt]=v; nxt[cnt]=head[u]; head[u]=cnt;
}
void dfs(int x,int y,int idx) {
	pp[x]=idx>>1;
	fa[x]=y; dep[x]=dep[y]+1; vis[x]=1;
	int i;
	for(i=head[x];i;i=nxt[i]) {
		if((i^1)==idx) continue;
		if(!vis[to[i]]) {
			dfs(to[i],x,i);
			even[x]+=even[to[i]];
			odd[x]+=odd[to[i]];
		}else {
			if(dep[to[i]]>dep[x]) continue;
			int d=dep[x]-dep[to[i]];
			if(d&1) {
				even[x]++; even[to[i]]--; even[0]++;
			}else {
				odd[x]++; odd[to[i]]--; odd[0]++; lst=i>>1;
			}
		}
	}
}
int main() {
	scanf("%d%d",&n,&m);
	int i,x,y;
	for(i=1;i<=m;i++) {
		scanf("%d%d",&x,&y);
		add(x,y); add(y,x);
	}
	for(i=1;i<=n;i++) {
		if(!vis[i]) {
			dfs(i,0,0);
		}
	}
	for(i=1;i<=n;i++) {
		if(fa[i]&&odd[i]==odd[0]&&!even[i]) ans[0]++,can[pp[i]]=1;
	}
	if(odd[0]==0) {
		printf("%d\n",m);
		for(i=1;i<=m;i++) {printf("%d",i); if(i!=m) putchar(' ');} return 0;
	}
	if(odd[0]==1) ans[0]++,can[lst]=1;
	printf("%d\n",ans[0]);
	for(i=1;i<=m;i++) if(can[i]) {printf("%d ",i);}
}