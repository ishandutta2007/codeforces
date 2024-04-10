#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <map>
#include <queue>
using namespace std;
typedef long long ll;
#define N 100050
int n,fa[N],dep[N],ans,vis[N],f[19][N],g[N],nlf[N],du[N];
ll L,S,w[N],s[19][N];
struct A {
	int x,gx;
	int operator < (const A &u) const {
		return 
		dep[gx]==dep[u.gx]?dep[x]<dep[u.x]:dep[gx]>dep[u.gx];
			// dep[x]-dep[gx]<dep[u.x]-dep[u.gx];
	}
};
priority_queue<A>q;
void del(int x,int gx) {
	if(vis[x]) return ;
	//printf("%d %d\n",x,gx);
	int t;
	for(t=x;!vis[t];t=fa[t]) {
		vis[t]=1;
		if(t==gx) {
			du[fa[t]]--;
			if(fa[t]&&!vis[fa[t]]&&!du[fa[t]]) q.push((A){fa[t],g[fa[t]]}); 
			break;
		}
	}
	ans++;
}
int main() {
	scanf("%d%lld%lld",&n,&L,&S);
	int i,j; ll mx=0;
	for(i=1;i<=n;i++) scanf("%lld",&w[i]),mx=max(mx,w[i]);
	for(i=2;i<=n;i++) scanf("%d",&fa[i]),f[0][i]=fa[i],s[0][i]=w[i],dep[i]=dep[fa[i]]+1,nlf[fa[i]]=1,du[fa[i]]++;
	for(i=1;(1<<i)<=n;i++) {
		for(j=1;j<=n;j++) {
			f[i][j]=f[i-1][f[i-1][j]];
			s[i][j]=s[i-1][j]+s[i-1][f[i-1][j]];
		}
	}
	if(L==0||mx>S) return puts("-1"),0;
	
	for(i=1;i<=n;i++) {
		int x=i;ll sum=0;
		for(j=18;j>=0;j--) {
			if(f[j][x]&&dep[i]-dep[f[j][x]]<L&&s[j][x]+w[f[j][x]]+sum<=S) {
				sum+=s[j][x]; x=f[j][x];
			}
		}
		g[i]=x;
	}
	// for(i=1;i<=n;i++) printf("g[%d]=%d\n",i,g[i]);
	for(i=1;i<=n;i++) {
		if(!nlf[i]) {
			q.push((A){i,g[i]});
		}
	}
	while(!q.empty()) {
		A t=q.top(); q.pop();
		// printf("t.x=%d\n",t.x);
		del(t.x,t.gx);
	}
	printf("%d\n",ans);
}