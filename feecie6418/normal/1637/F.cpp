#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pr;
int n,a[200005],f[200005];
ll ans=0;
vector<int> g[200005];
void dfs(int x,int fa){
	if(g[x].size()==1&&fa){
		f[x]=a[x],ans+=a[x];
	}
	for(int y:g[x]){
		if(y==fa)continue;
		dfs(y,x);
		f[x]=max(f[x],f[y]);
	}
	if(!fa){
		if(g[x].size()>1){
			sort(g[x].begin(),g[x].end(),[](int x,int y){return f[x]>f[y];});
			ans+=a[x]-f[g[x][0]];
			ans+=a[x]-f[g[x][1]];
		}
		else {
			ans+=a[x]-f[x];
			ans+=a[x];
		}
		return ;
	}
	if(f[x]<=a[x])ans+=a[x]-f[x],f[x]=a[x];
}
void Solve(){
	cin>>n;
	int mx=0,p=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]>mx)mx=a[i],p=i;
	}
	for(int i=1,x,y;i<n;i++){
		scanf("%d%d",&x,&y);
		g[x].push_back(y),g[y].push_back(x);
	}
	dfs(p,0);
	cout<<ans<<'\n';
	for(int i=1;i<=n;i++)f[i]=a[i]=0,g[i].clear();
	ans=0;
}
int main(){
//	freopen("1.in","r",stdin);
//	freopen("1.out","w",stdout);
	int t=1;
	while(t--){
		Solve();
	}
}