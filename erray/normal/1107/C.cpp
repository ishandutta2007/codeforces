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
int n, k, x;
string s;
vi v(500005), val[500];
void solve(){
	ll ans = 0;
	cin >> n >> k; 
	for(int i = 0; i < n; i++)cin >> v[i];
	cin >> s;
	s += 'A';
	for(int i = 0; i < n + 1; i++){
		val[s[i]].pb(v[i]);
		for(int c  = 'a'; c <= 'z'; c++){
			if(!val[c].empty() && c != s[i]){
				sort(all(val[c]));
				reverse(all(val[c]));
				for(int j = 0; j < min(k, val[c].size()); j++)ans += val[c][j];
				val[c].clear();
			}
		}
	}
	cout << ans << ln;
}
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);cout.tie(nullptr);cerr.tie(nullptr);
  solve();
}