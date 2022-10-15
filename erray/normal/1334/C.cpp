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
int t, n;
vector <pair <ll,ll> > v;
ll a, b;	
void solve(){
	cin >> n;
	for(int i = 0; i < n; i++){cin >> a >> b;v.pb(mp(a, b));}
	if(n == 1){
		cout << v[0].st << ln;
		return;
	}
	ll ans = (1ll<<62), cost = 0;
	for(int i = 0; i < n; i++)cost+=max(v[i].st - v[i==0?n - 1: i - 1].nd, 0ll);
	//cerr << cost << ln;
	for(int i = 0; i < n; i++){
		ans = min((ll)ans,(ll) v[i].st + cost - max(v[i].st - v[i==0?n - 1: i - 1].nd, (ll)0));
	}
	cout << ans << ln;
}
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);cout.tie(nullptr);cerr.tie(nullptr);
  cin >> t;
  while(t--){
  	solve();
  	v.clear();
  }
}