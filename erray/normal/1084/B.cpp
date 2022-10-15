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
int n, x;
ll k;
void solve(){
	cin >> n >> k;
	ll sum = 0;
	vi v;
	while(n--){cin >> x;sum+=x; v.pb(x);}
	sort(all(v));
	sum -= (ll)(v[0]*v.size());
	//cerr << sum << ln;
	if(sum < k) cout << max(v[0]-(ll)ceil((long double)(k - sum)/v.size()), -1ll);
	else cout << v[0];
}
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);cout.tie(nullptr);cerr.tie(nullptr);
  solve();
}