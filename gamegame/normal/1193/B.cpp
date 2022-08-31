#include<bits/stdc++.h>
using namespace std;//diu lei lo mo lap sap sample on lun gau
typedef long long ll;
#define fi first
#define se second
const int N=1e5+1;
int n,m,k;
vector<int>ch[N];
multiset<pair<int,ll> >dp[N];
int d[N];
ll w[N];
int bs[N];
void solve(int id){
	bs[id]=id;
	int bc=0;
	for(auto cur:ch[id]){
		solve(cur);
		if(dp[bs[cur]].size()>dp[bs[id]].size()){
			bc=cur;bs[id]=bs[cur];
		}
	}
	for(auto cur:ch[id]){
		if(cur==bc) continue;
		for(auto tmp:dp[bs[cur]]){
			dp[bs[id]].insert(tmp);
		}
		dp[bs[cur]].clear();
	}
	if(d[id]==0) return;
	auto it=dp[bs[id]].lower_bound({d[id]+1,0LL});
	ll tae=w[id];
	while(it!=dp[bs[id]].end()){
		if(tae>=it->se){
			tae-=it->se;
			dp[bs[id]].erase(it++);
		}
		else{
			auto tmp=*it;
			dp[bs[id]].erase(it);
			tmp.se-=tae;
			dp[bs[id]].insert(tmp);
			break;
		}
	}
	dp[bs[id]].insert({d[id],w[id]});
}
int main(){
	ios::sync_with_stdio(false);
	cin >> n >> m >> k;
	for(int i=2; i<=n ;i++){
		int p;cin >> p;
		ch[p].push_back(i);
	}
	for(int i=1; i<=m ;i++){
		int v;cin >> v;
		cin >> d[v] >> w[v];
	}
	solve(1);
	ll ans=0;
	for(auto cur:dp[bs[1]]) ans+=cur.se;
	cout << ans << endl;
}