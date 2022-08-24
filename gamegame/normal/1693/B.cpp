#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const ll mod=998244353;
const int N=2e6+1;
ll n,m;
ll dp[N];
ll l[N],r[N];
vector<int>adj[N];
void dfs(int id){
	dp[id]=0;
	ll s=0;
	for(auto c:adj[id]){
		dfs(c);
		dp[id]+=dp[c];
		s+=r[c];
	}
	if(s>=l[id]) r[id]=min(r[id],s);
	else{
		dp[id]++;
	}
}
void solve(){
	cin >> n;
	for(int i=1; i<=n ;i++) adj[i].clear();
	for(int i=2; i<=n ;i++){
		int p;cin >> p;
		adj[p].push_back(i);
	}
	for(int i=1; i<=n ;i++) cin >> l[i] >> r[i];
	dfs(1);
	cout << dp[1] << '\n';
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	int t;cin >> t;while(t--) solve();
}