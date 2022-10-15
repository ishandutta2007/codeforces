#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h> 
#define pb emplace_back
#define mp make_pair 
#define st first 
#define nd second 
#define all(v) v.begin(),v.end()
#define umap unordered_map
#define L nd<<1
#define R (L)|1
#define mid ((s + e)>>1)
#define ln '\n'
using namespace std;
typedef long long ll;
typedef vector<int> vi;
const int N = 300005;
int n, a, b, c, par[N];
vi val(N);
vector <pair <int, int> > edge[N];
ll ans, dp[N];
ll DP(int nd){
	if(dp[nd] != -1)return dp[nd];
	if(edge[nd].size() == 1 && nd != 1){ans = max((ll)val[nd], ans);return dp[nd] = 0;}
	vector <ll>  vals;
	for(auto i : edge[nd]){
		if(i.st != par[nd]){
			vals.pb(val[i.st] - i.nd + max(DP(i.st), 0ll));
		}
	}
	vals.pb(0ll);
	vals.pb(0ll);
	sort(all(vals));
	if(vals.size() >= 2)ans = max(ans, val[nd] + max(vals[vals.size() - 2], 0ll) + max(vals[vals.size() - 1], 0ll));
	return dp[nd] = max(vals[vals.size() - 1], 0ll);
}
void solve(){
	memset(dp, -1, sizeof dp);
	cin >> n;
	
	for(int i = 0; i < n; i++){cin >> val[i + 1];}
	if(n == 1){
		cout << val[1];
		return;
	}
	while(--n){
		cin >> a >> b >> c;
		edge[a].pb(mp(b, c));
		edge[b].pb(mp(a, c));
	}
	queue <pair <int, int>  > q;
	q.push(mp(1, -1));
	while(!q.empty()){
		int nd = q.front().st, pr = q.front().nd;
		q.pop();
		par[nd] = pr;
		for(auto i : edge[nd])if(i.st!=pr)q.push(mp(i.st, nd));
	} 
	ll asdasd = DP(1);
	cout << ans;
}
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);cout.tie(nullptr);cerr.tie(nullptr);
  solve();
}