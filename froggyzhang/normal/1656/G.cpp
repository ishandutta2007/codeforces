#include<bits/stdc++.h>
using namespace std;
#define N 200002
typedef long long ll;
int n,a[N],cnt[N],b[N],vis[N];
vector<pair<int,int> > G[N];
vector<int> ans;
void dfs(int u){
	while(!G[u].empty()){
		auto [v,id]=G[u].back();
		G[u].pop_back();
		if(vis[id])continue;
		vis[id]=1;
		dfs(v);
		ans.push_back(id);
	}
}
void Solve(){
	cin>>n;
	for(int i=1;i<=n;++i)cnt[i]=0,G[i].clear();
	for(int i=1;i<=n;++i){
		cin>>a[i];
		++cnt[a[i]];
	}
	int z=0;
	for(int i=1;i<=n;++i){
		if(cnt[i]&1){
			if(z){
				cout<<"NO\n";
				return;
			}
			z=i;
		}
	}
	for(int i=1;i<=n;++i)b[i]=0;
	if(n&1){
		b[(n+1)/2]=z;
		--cnt[z];
		if(a[(n+1)/2]==z&&!cnt[z]){
			cout<<"NO\n";
			return;
		}
	}
	for(int i=n/2-1;i>=1;--i){
		if(cnt[a[i]])b[i+1]=b[n-i]=a[i],cnt[a[i]]-=2;
		else if(cnt[a[n-i+1]])b[i+1]=b[n-i]=a[n-i+1],cnt[a[n-i+1]]-=2;
	}
	for(int i=1,j=1;i<=n/2;++i){
		if(b[i])continue;
		while(!cnt[j])++j;
		b[i]=b[n-i+1]=j;
		cnt[j]-=2;
	}
	for(int i=1;i<=n;++i){
		G[i].clear();
		vis[i]=0;
	}
	ans.clear();
	for(int i=1;i<=n;++i){
		G[a[i]].emplace_back(b[i],i);
		vis[i]=0;
	}
	for(int i=1;i<=n;++i){
		if(G[i].size()){
			dfs(i);
			break;
		}
	}
	if(ans.size()==n){
		cout<<"YES\n";
		static int Ans[N];
		for(int i=0;i<n;++i){
			Ans[ans[(i+1)%n]]=ans[i];
		}
		for(int i=1;i<=n;++i){
			cout<<Ans[i]<<' ';
		}
		cout<<'\n';
		return;
	}
	cout<<"NO\n";
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)Solve();
	return 0;
}