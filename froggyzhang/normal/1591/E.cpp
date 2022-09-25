#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
#define N 1000100
typedef pair<int,int> pii;
tree<pii,null_type,less<pii>,rb_tree_tag,tree_order_statistics_node_update> T;
int n,Q,cnt[N],ans[N],a[N];
vector<int> G[N];
struct Query{
	int id,lim,k;	
};
vector<Query> q[N];
void dfs(int u){
	if(cnt[a[u]]){
		T.erase(pii(cnt[a[u]],a[u]));	
	}
	++cnt[a[u]];
	T.insert(pii(cnt[a[u]],a[u]));
	for(auto t:q[u]){
		int jb=t.k+T.order_of_key(pii(t.lim,0));
		ans[t.id]=jb>T.size()?-1:T.find_by_order(jb-1)->second;
	}
	for(auto v:G[u]){
		dfs(v);	
	}
	T.erase(pii(cnt[a[u]],a[u]));
	--cnt[a[u]];
	if(cnt[a[u]]){
		T.insert(pii(cnt[a[u]],a[u]));	
	}
}
void Solve(){
	cin>>n>>Q;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		q[i].clear();
		G[i].clear();
	}
	for(int i=2;i<=n;++i){
		int fa;
		cin>>fa;
		G[fa].push_back(i);
	}
	for(int i=1;i<=Q;++i){
		int u,L,k;
		cin>>u>>L>>k;
		q[u].push_back({i,L,k});	
	}
	dfs(1);
	for(int i=1;i<=Q;++i){
		cout<<ans[i]<<' ';
	}
	cout<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)Solve();
	return 0;
}