#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[100005][2],n;
ll f[100005][2];
vector<int> g[100005];
void dfs(int x,int fa){
	f[x][0]=f[x][1]=0;
	for(int y:g[x]){
		if(y==fa)continue;
		dfs(y,x);
		ll w[2]={0};
		for(int i=0;i<2;i++){
			for(int j=0;j<2;j++)w[i]=max(w[i],f[y][j]+abs(a[x][i]-a[y][j]));
			f[x][i]+=w[i];
		}
	}
}
void Solve(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d%d",&a[i][0],&a[i][1]);
	for(int i=1,x,y;i<n;i++)scanf("%d%d",&x,&y),g[x].push_back(y),g[y].push_back(x);
	dfs(1,0),cout<<max(f[1][0],f[1][1])<<'\n';
	for(int i=1;i<=n;i++)g[i].clear();
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--)Solve();
}