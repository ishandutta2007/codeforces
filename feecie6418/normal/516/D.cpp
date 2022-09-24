#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,q,h[200005],cnt,L,R,o,p[200005][20],c[200005];
ll disl[200005],disr[200005],f[200005],maxx,ans;
struct Edge {
	int to,next,value;
} e[400005];
void Add_Edge(int u,int v,int w) {
	e[++cnt]= {v,h[u],w},h[u]=cnt;
}
void dfs1(int x,int f,ll di,int&var,ll d[]) {
	if(di>maxx)maxx=di,var=x;
	d[x]=di;
	for(int i=h[x]; i; i=e[i].next) {
		int y=e[i].to;
		if(y==f)continue;
		dfs1(y,x,di+e[i].value,var,d);
	}
}
void dfs2(int x,int fa){
	p[x][0]=fa;
	for(int i=1;i<=16;i++)p[x][i]=p[p[x][i-1]][i-1];
	for(int i=h[x];i;i=e[i].next){
		int y=e[i].to;
		if(y^fa)dfs2(y,x);
	}
}
void dfs3(int x,int fa,ll X){
	int y=x;
	for(int i=16;i>=0;i--)if(p[y][i]&&f[p[y][i]]>=f[x]-X)y=p[y][i];
	c[x]++,c[p[y][0]]--;
	for(int i=h[x];i;i=e[i].next){
		int y=e[i].to;
		if(y^fa)dfs3(y,x,X),c[x]+=c[y];
	}
}
int main() {
	scanf("%d",&n);
	for(int i=1,x,y,z; i<n; i++)scanf("%d%d%d",&x,&y,&z),Add_Edge(x,y,z),Add_Edge(y,x,z);
	maxx=-1,dfs1(1,0,0,L,disl);
	maxx=-1,dfs1(L,0,0,R,disl);
	dfs1(R,0,0,o,disr);
	ll mn=1e18,mnp=0;
	for(int i=1; i<=n; i++){
		f[i]=max(disl[i],disr[i]);
		if(f[i]<mn)mn=f[i],mnp=i;
	}
	dfs2(mnp,0),scanf("%d",&q);
	while(q--){
		ll x,ans=0;
		scanf("%lld",&x),dfs3(mnp,0,x);
		for(int i=1;i<=n;i++)ans=max(ans,(ll)c[i]),c[i]=0;
		printf("%lld\n",ans);
	}
	return 0;
}
/*
5
1 2 3
2 3 4
4 5 3
3 4 2
5
1 2 3 4 5
*/