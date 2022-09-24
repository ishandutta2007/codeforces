#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1000000007;
int n,cnt,m,p[100005],size[100005];
ll a[100005];
vector<int> g[100005];
void dfs(int x,int f){
	size[x]=1;
	for(int y:g[x]){
		if(y^f)dfs(y,x),size[x]+=size[y],a[++cnt]=1ll*size[y]*(n-size[y]);
	}
}
int main() {
	int T;
	cin>>T;
	while(T--){
		scanf("%d",&n),cnt=0;
		for(int i=1;i<=n;i++)g[i].clear();
		for(int i=1,x,y;i<n;i++)scanf("%d%d",&x,&y),g[x].push_back(y),g[y].push_back(x);
		dfs(1,0);
		sort(a+1,a+cnt+1);
		scanf("%d",&m);
		for(int i=1;i<=m;i++)scanf("%d",&p[i]);
		int ans=0;
		if(m<n-1){
			for(int i=m+1;i<n;i++)p[i]=1;
			sort(p+1,p+n);
			for(int i=1;i<n;i++)ans=(ans+a[i]%mod*p[i]%mod)%mod;
			cout<<ans<<'\n';
		}
		else {
			sort(p+1,p+m+1);
			for(int i=1;i<n-1;i++)ans=(ans+a[i]%mod*p[i]%mod)%mod;
			int o=1;
			for(int i=n-1;i<=m;i++)o=1ll*o*p[i]%mod;
			ans=(ans+a[n-1]%mod*o%mod)%mod;
			cout<<ans<<'\n';
		}
	}
	return 0;
}