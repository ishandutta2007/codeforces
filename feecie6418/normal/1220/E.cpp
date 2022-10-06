#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,bel[200005],C,dfn[200005],low[200005],sign,st[200005],top,w[200005],rt;
int fa[200005],F[200005],sz[200005];
ll ans=0,sum[200005],dis[200005];
struct E{
	int to,id;
};
vector<E> g1[200005];
vector<int> g[200005];
map<ll,int> mp;
void Tarjan(int x,int prt){
	dfn[x]=low[x]=++sign,st[++top]=x;
	for(E i:g1[x]){
		if(i.id==prt)continue;
		int y=i.to;
		if(!dfn[y])Tarjan(y,i.id),low[x]=min(low[x],low[y]);
		else low[x]=min(low[x],dfn[y]);
	}
	if(low[x]==dfn[x]){
		int tmp=0;
		C++;
		while(tmp!=x)tmp=st[top--],bel[tmp]=C,sz[C]++,sum[C]+=w[tmp];
	}
}
int gf(int x){
	return x==fa[x]?x:fa[x]=gf(fa[x]);
}
void dfs(int x,int f){
	F[x]=f;
	if(sz[x]>1){
		int tx=x;
		while(gf(x)!=gf(rt)){
			fa[gf(tx)]=gf(F[tx]);
			tx=F[tx];
		}
	}
	//cout<<"S:"<<x<<' '<<sz[x]<<'\n';
	for(int y:g[x])if(y^f)dfs(y,x);
}
void dfs2(int x,int f){
	if(gf(x)!=gf(rt))dis[x]=dis[f]+sum[x];
	else dis[x]=dis[f];
	ans=max(ans,dis[x]);
	//cout<<"FA:"<<x<<' '<<f<<'\n';
	for(int y:g[x])if(y^f)dfs2(y,x);
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&w[i]);
	for(int i=1,x,y;i<=m;i++)scanf("%d%d",&x,&y),g1[x].push_back({y,i}),g1[y].push_back({x,i});
	scanf("%d",&rt);
	Tarjan(1,0);
	for(int i=1;i<=n;i++){
		//cout<<"B:"<<i<<' '<<bel[i]<<'\n';
		for(E j:g1[i]){
			int x=bel[i],y=bel[j.to];
			if(x>y)swap(x,y);
			if(x==y||mp[200005ll*x+y])continue;
			mp[200005ll*x+y]=1,g[x].push_back(y),g[y].push_back(x);
		}
	}
	rt=bel[rt];
	for(int i=1;i<=C;i++)fa[i]=i;
	dfs(rt,0),dfs2(rt,0);
	//cout<<ans<<'\n';
	for(int i=1;i<=C;i++)if(gf(i)==gf(rt))ans+=sum[i];
	cout<<ans;
}