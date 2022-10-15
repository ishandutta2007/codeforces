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
#define max(aa, bb) (aa > bb ? aa : bb)
#define min(aa, bb) (aa < bb ? aa : bb)
#define ln '\n'
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
int n;
string b;
ll val[105];
ll dp[105][105][105];
ll DP(int s, int e, int pr){
	if(dp[s][e][pr] != -1)return dp[s][e][pr];
	if(s > e)return dp[s][e][pr] = 0;
	dp[s][e][pr] = val[pr] + DP(s + 1, e, 1);
	for(int i = s + 1; i <= e; i++){
		if(b[i] == b[s]){
			dp[s][e][pr] = max(dp[s][e][pr], DP(s + 1, i - 1, 1) + DP(i, e, pr + 1));
		}
	}
	return dp[s][e][pr];
}
void solve(){
	memset(dp, -1, sizeof dp);
	cin >> n >> b;
	for(int i = 0; i < n; i++)cin >> val[i + 1];
	cout << DP(0, n - 1, 1);
}
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);cout.tie(nullptr);cerr.tie(nullptr);
  solve();
}