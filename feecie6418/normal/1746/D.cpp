#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pr; 
int n,K,mx[200005],mn[200005];
ll f[200005][2],a[200005];
vector<int> g[200005];
void dfs(int x,int L,int R){
	f[x][0]=1ll*L*a[x];
	f[x][1]=1ll*R*a[x];
	//cout<<x<<' '<<f[x][0]<<' '<<f[x][1]<<' '<<L<<' '<<R<<'\n';
	if(!g[x].size())return ;
	for(int y:g[x]){
		dfs(y,L/g[x].size(),(R+g[x].size()-1)/g[x].size());
	}
	sort(g[x].begin(),g[x].end(),[](int x,int y){
		return f[x][0]-f[x][1]>f[y][0]-f[y][1];
	});
	//0 1
	int nd1=L%g[x].size(),nd0=g[x].size()-nd1;
	for(int i=0;i<nd0;i++)f[x][0]+=f[g[x][i]][0]; 
	for(int i=nd0;i<g[x].size();i++)f[x][0]+=f[g[x][i]][1];
	
	if(L!=R){
		nd0--;
	}
	for(int i=0;i<nd0;i++)f[x][1]+=f[g[x][i]][0]; 
	for(int i=nd0;i<g[x].size();i++)f[x][1]+=f[g[x][i]][1];
	//cout<<x<<' '<<f[x][0]<<' '<<f[x][1]<<' '<<L<<' '<<R<<'\n';
}
void Solve(){
	scanf("%d%d",&n,&K);
	for(int i=2,x;i<=n;i++){
		scanf("%d",&x),g[x].push_back(i);
	}
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	dfs(1,K,K),cout<<f[1][0]<<'\n';
	for(int i=0;i<=n;i++){
		mx[i]=mn[i]=f[i][0]=f[i][1]=a[i]=0;
		g[i].clear();
	}
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--)Solve();
}