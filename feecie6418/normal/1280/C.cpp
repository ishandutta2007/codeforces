#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1e9+7;
int n,sz[200005];
ll ans1,ans2;
struct E{
	int to,val;
};
vector<E> g[200005];
void dfs(int x,int fa){
	sz[x]=1;
	for(E i:g[x]){
		int y=i.to;
		if(y==fa)continue;
		dfs(y,x),sz[x]+=sz[y];
		if(sz[y]&1)ans1+=i.val;
		ans2+=1ll*i.val*min(2*n-sz[y],sz[y]);
	}
}
void Solve(){
	scanf("%d",&n),ans1=0,ans2=0;
	for(int i=1,x,y,z;i<2*n;i++){
		scanf("%d%d%d",&x,&y,&z);
		g[x].push_back({y,z}),g[y].push_back({x,z});
	}
	dfs(1,0);
	cout<<ans1<<' '<<ans2<<'\n';
	for(int i=1;i<=2*n;i++)g[i].clear();
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--)Solve();
}