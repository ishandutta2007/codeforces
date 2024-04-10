#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,ll> pr;
int n,m,a[3005],sz[3005];
pr f[3005][3005],t[3005];
vector<int> g[3005];
void upd(pr &x,pr y){
	x=max(x,y);
}
void dfs(int x,int fa){
	sz[x]=1,f[x][0]=pr(0,0);
	for(int y:g[x]){
		if(y==fa)continue;
		dfs(y,x);
		for(int i=0;i<sz[x]+sz[y];i++)t[i]=pr(-1,0);
		for(int i=0;i<sz[x];i++){
			for(int j=0;j<sz[y];j++){
				upd(t[i+j],pr(f[x][i].first+f[y][j].first,f[x][i].second+f[y][j].second));
				upd(t[i+j+1],pr(f[x][i].first+f[y][j].first+(f[y][j].second>0),f[x][i].second));
			}
		}
		sz[x]+=sz[y];
		for(int i=0;i<sz[x];i++)f[x][i]=t[i];
	}
	for(int i=0;i<sz[x];i++)f[x][i].second+=a[x];
}
void Solve(){
	scanf("%d%d",&n,&m);
	for(int i=1,x;i<=n;i++)scanf("%d",&x),a[i]-=x;
	for(int i=1,x;i<=n;i++)scanf("%d",&x),a[i]+=x;
	for(int i=1,x,y;i<n;i++)scanf("%d%d",&x,&y),g[x].push_back(y),g[y].push_back(x);
	dfs(1,0),cout<<f[1][m-1].first+(f[1][m-1].second>0)<<'\n';
	for(int i=1;i<=n;i++){
		g[i].clear(),a[i]=0;
		for(int j=0;j<=n;j++)f[i][j]=pr(-1,0);
	}
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--)Solve();
}