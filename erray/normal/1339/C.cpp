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
int t, n, x;
void solve(){
	cin >> n;
	vi v;
	for(int i = 0; i < n; i++){
		cin >> x;
		v.pb(x);
	}
	int mx = 1<<31, ans = -1;
	for(int i = 0; i < n; i++){
		mx = max(mx, v[i]);
		ans = max(ans, (int)log2(mx - v[i]));
	}
	cout << ans + 1 << ln;
}
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);cout.tie(nullptr);cerr.tie(nullptr);
  cin >> t;
  //int a = 1<<31;
  //cout << a << ln;
  //cout << (int)1ll<<31 << ln;
  while(t--)solve();
}