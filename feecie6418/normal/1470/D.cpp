#include<bits/stdc++.h>
using namespace std;
int n,m,fa[300005],is[300005],v[300005],cnt;
vector<int> g[300005];
int gf(int x){
	return x==fa[x]?x:fa[x]=gf(fa[x]);
}
void dfs(int x){
	int flag=0;
	for(int y:g[x])flag|=is[y];
	if(!flag)is[x]=1,cnt++;
	v[x]=1;
	for(int y:g[x])if(!v[y])dfs(y);
}
void Solve(){
	cin>>n>>m,cnt=0;
	for(int i=1;i<=n;i++)g[i].clear(),fa[i]=i,is[i]=v[i]=0;
	for(int i=1,x,y;i<=m;i++)cin>>x>>y,g[x].push_back(y),g[y].push_back(x),fa[gf(x)]=gf(y);
	for(int i=1;i<=n;i++)if(gf(i)!=gf(1))return puts("NO"),void();
	dfs(1),cout<<"YES\n"<<cnt<<'\n';
	for(int i=1;i<=n;i++)if(is[i])cout<<i<<' ';
	cout<<'\n';
}
int main(){
	int t;
	cin>>t;
	while(t--)Solve();
}