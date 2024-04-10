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
void solve(){
	int ans = 1;
	cin >> n;
	vi v(n);
	for(int i = 0; i < n; i++)cin >> v[i];
	vi v2 = v;
	sort(all(v2));
	v.pb(-1);
	for(int i = 0; i < n; i++){
		int ct = 1;
		while(i < n && v[i] == v[i + 1] && v[i] == v2[v2.size() - 1]){ct++;i++;}
		ans = max(ans, ct);
	}
	cout << ans;
}
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);cout.tie(nullptr);cerr.tie(nullptr);
  solve();
}