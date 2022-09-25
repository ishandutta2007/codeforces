#include<bits/stdc++.h>
using namespace std;
#define N 100010
typedef long long ll;
int n,K,a[N],s[N],sum;
vector<int> G[N];
bool ok;
bool dfs(int u,int fa){
	s[u]=a[u];
	int cnt=0;
	for(auto v:G[u]){
		if(v==fa)continue;
		cnt+=dfs(v,u);
		s[u]^=s[v];
	}
	if(!s[u]&&cnt||cnt>=2)ok=true;
	if(s[u]==sum)++cnt;
	return cnt>=1;
}
void Solve(){
	cin>>n>>K;
	sum=0;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		G[i].clear();
		sum^=a[i];
	}
	for(int i=1;i<n;++i){
		int u,v;
		cin>>u>>v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	if(!sum){
		cout<<"YES\n";
		return;
	}
	if(K==2){
		cout<<"NO\n";
		return;
	}
	ok=false;
	dfs(1,0);
	cout<<(ok?"YES\n":"NO\n");
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)Solve();
	return 0;
}