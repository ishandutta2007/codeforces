#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pr;
const int B=150005;
int n,m,dis[200005],X[200005],Y[200005],Z[200005],fa[200005],col[200005];
struct E{
	int to,val;
};
vector<E> g[200005];
vector<int> gg[200005];
bool nok;
int gf(int x){
	return x==fa[x]?x:fa[x]=gf(fa[x]);
}
void dfs2(int x,int c){
	col[x]=c;
	for(int y:gg[x]){
		if(-1==col[y])dfs2(y,1-c);
		else if(col[y]==col[x])nok=1;
	}
}
void Solve(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)g[i].clear(),gg[i].clear(),dis[i]=0;
	for(int i=1;i<=n;i++)fa[i]=i,col[i]=-1;
	for(int i=1,x,y,z;i<n;i++){
		scanf("%d%d%d",&x,&y,&z);
		g[x].push_back({y,z});
		g[y].push_back({x,z});
		if(z!=-1&&__builtin_popcount(z)%2==0)fa[gf(y)]=gf(x);
	}
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&X[i],&Y[i],&Z[i]);
		if(Z[i]==0)fa[gf(X[i])]=gf(Y[i]);
	}
	for(int i=1;i<=n;i++){
		for(E j:g[i])if(j.val!=-1&&__builtin_popcount(j.val)%2==1)gg[gf(i)].push_back(gf(j.to));
	}
	for(int i=1;i<=m;i++){
		if(Z[i]==1)gg[gf(X[i])].push_back(gf(Y[i])),gg[gf(Y[i])].push_back(gf(X[i]));
	}
	nok=0;
	for(int i=1;i<=n;i++)if(col[gf(i)]==-1)dfs2(gf(i),0);
	for(int i=1;i<=n;i++)dis[i]=col[gf(i)];
	if(nok)puts("No");
	else {
		puts("Yes");
		for(int i=1;i<=n;i++){
			for(E j:g[i]){
				if(j.to<i)continue;
				if(j.val!=-1)cout<<i<<' '<<j.to<<' '<<j.val<<'\n';
				else cout<<i<<' '<<j.to<<' '<<(dis[i]^dis[j.to])<<'\n';
			}
		}
	}
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--)Solve();
}