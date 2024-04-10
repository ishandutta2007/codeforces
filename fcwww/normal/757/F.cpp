#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <queue>
using namespace std;
typedef long long ll;
#define N 200050
#define M 600050
int head[N],to[M],nxt[M],val[M],cnt,n,m,S,f[20][N],dep[N];
ll dis[N]; int vis[N],siz[N],Q[N],du[N],xx[M],yy[M],zz[M];
priority_queue<pair<ll,int> >q;
inline void add(int u,int v,int w) {
	to[++cnt]=v; nxt[cnt]=head[u]; head[u]=cnt; val[cnt]=w;
}
int lca(int x,int y) {
	if(!x) return y;
	int i;
	if(dep[x]<dep[y]) swap(x,y);
	for(i=19;i>=0;i--) if(f[i][x]&&dep[f[i][x]]>=dep[y]) x=f[i][x];
	if(x==y) return x;
	for(i=19;i>=0;i--) if(f[i][x]!=f[i][y]) x=f[i][x],y=f[i][y];
	return f[0][x];
}
int main() {
	scanf("%d%d%d",&n,&m,&S);
	int i,x,y,z;
	for(i=1;i<=m;i++) {
		scanf("%d%d%d",&x,&y,&z);
		add(x,y,z); add(y,x,z); xx[i]=x,yy[i]=y,zz[i]=z;
	}
	memset(dis+1,0x3f,n<<3);
	dis[S]=1;
	q.push(make_pair(0,S));
	while(!q.empty()) {
		x=q.top().second;q.pop();if(vis[x])continue;
		vis[x]=1;for(i=head[x];i;i=nxt[i]) if(dis[to[i]]>dis[x]+val[i]) {
			dis[to[i]]=dis[x]+val[i]; q.push(make_pair(-dis[to[i]],to[i]));
		}
	}
	memset(head,0,sizeof(head)); cnt=0;
	for(i=1;i<=m;i++) {
		if(dis[xx[i]]+zz[i]==dis[yy[i]]) add(yy[i],xx[i],0),du[xx[i]]++;
		if(dis[yy[i]]+zz[i]==dis[xx[i]]) add(xx[i],yy[i],0),du[yy[i]]++;
	}
	int l=0,r=0;
	for(i=1;i<=n;i++) if(!du[i]) Q[r++]=i;
	while(l<r) {
		x=Q[l++];
		for(i=head[x];i;i=nxt[i]) {
			du[to[i]]--; if(!du[to[i]]) Q[r++]=to[i];
		}
	}
	int k;
	for(k=n-1;k>=0;k--) {
		x=Q[k]; int l=0;
		for(i=head[x];i;i=nxt[i]) {
			l=lca(l,to[i]);
		}
		f[0][x]=l; dep[x]=dep[l]+1;
		for(i=1;i<=19;i++) f[i][x]=f[i-1][f[i-1][x]];
	}
	for(k=0;k<n;k++) {
		x=Q[k]; siz[x]++;
		siz[f[0][x]]+=siz[x];
	}
	int ans=0;
	for(i=0;i<n-1;i++) if(dis[Q[i]]<=(1ll<<60)&&Q[i]!=S) ans=max(ans,siz[Q[i]]);
	printf("%d\n",ans);
}