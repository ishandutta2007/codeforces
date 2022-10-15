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
typedef pair<int, int> pii;
typedef vector<int> vi;
int n, k, a, b, sp[200005], par[200005], dp[200005], ct[200005], val[200005], sum[200005];
vector <int> edge[200005];   
bool vis[200005];
int DP(int nd){
	if(dp[nd]!=-1)return dp[nd];
	for(int i : edge[nd])if(i != par[nd])dp[nd]+=DP(i)+1;
	val[nd] = sp[nd] - ++dp[nd];
	return dp[nd];
}
void solve(){
	cin >> n >> k;
	int tn = n;
	while(--n){
		cin >> a >> b;
		edge[a].pb(b);
		edge[b].pb(a);
	} 
	n = tn;
	ll ans = 0;
	memset(dp, -1, sizeof dp);
	queue <int> q;
	q.push(1);
	while(!q.empty()){
		int nd = q.front();q.pop();
		for(auto a : edge[nd]){
			if(a != 1 && sp[a] == 0){
				sp[a] = sp[nd] + 1; q.push(a);
			}
			else par[nd] = a;
		}
	} 
	int asd = DP(1);
	priority_queue <pii> pq;
	for(int i = 2; i <= n; i++)if(dp[i] == sum[i])pq.push(mp(val[i], i));
	//cout << pq.size() << ln;
	while(k--){
		int vl = pq.top().st, nd = pq.top().nd;
		pq.pop();
		sum[par[nd]]+=sum[nd]+1;
		//cout << vl << " " << nd <<  " " << dp[nd] << ln;
		ans += vl;
		if(sum[par[nd]] == dp[par[nd]])pq.push(mp(val[par[nd]], par[nd]));
	}
	cout << ans;
}
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);cout.tie(nullptr);cerr.tie(nullptr);
  solve();
}