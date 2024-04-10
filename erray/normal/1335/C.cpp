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
	map <int, int> m; 
	int mx = -1, n2 = n; 
	vi mxs;
	set <int> s; 
	while(n--){cin >> x;s.insert(x);mx = max(mx, ++m[x]);}
	cout << max(min(mx - 1, (int)m.size()), min(mx, (int)m.size() - 1)) << ln;
}
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);cout.tie(nullptr);cerr.tie(nullptr);
  cin >> t;
  while(t--)solve();
}