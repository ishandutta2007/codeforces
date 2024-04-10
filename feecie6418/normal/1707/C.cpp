#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pr;
const int mod=998244353;
using namespace std;
int n,m,fa[200005],X[200005],Y[200005],is[200005],dfn[200005],sz[200005],c[200005],val[200005];
int sign,p[200005][20],d[200005];
int gf(int x){
	return x==fa[x]?x:fa[x]=gf(fa[x]);
}
vector<int> g[200005];
void dfs(int x,int fa){
	dfn[x]=++sign,sz[x]=1,p[x][0]=fa,d[x]=d[fa]+1;
	for(int i=1;i<=18;i++)p[x][i]=p[p[x][i-1]][i-1];
	for(int y:g[x])if(y^fa)dfs(y,x),sz[x]+=sz[y];
}
void dfs2(int x,int fa){
	val[x]=c[x];
	for(int y:g[x]){
		if(y==fa)continue;
		c[y]+=c[x];
		dfs2(y,x);
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=m;i++){
		scanf("%d%d",&X[i],&Y[i]);
		int x=gf(X[i]),y=gf(Y[i]);
		if(x==y)continue;
		fa[x]=y,is[i]=1;
		g[X[i]].push_back(Y[i]);
		g[Y[i]].push_back(X[i]);
	}
	dfs(1,0);
	for(int i=1;i<=m;i++){
		if(is[i])continue;
		int x=X[i],y=Y[i];
		if(dfn[x]>dfn[y])swap(x,y);
		if(dfn[y]<dfn[x]+sz[x]){
			c[1]++;
			int z=y;
			for(int j=18;j>=0;j--)if(d[p[z][j]]>d[x])z=p[z][j];
			c[z]--;
			c[y]++;
		}
		else {
			c[x]++,c[y]++;
		}
	}
	dfs2(1,0);
	for(int i=1;i<=n;i++)if(val[i]==m-n+1)cout<<1;else cout<<0;
}