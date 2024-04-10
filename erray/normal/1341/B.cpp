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
int T, n, k; 
void solve(){
	cin >> n >> k;
	vi v(n), al;
	for(int i = 0; i < n; ++i)cin >> v[i];
	int ct = 0, ans = -1;
	for(int i = 1; i < k - 1; ++i){
		ct += (v[i]>v[i - 1] && v[i]>v[i + 1]);
	}
	ans = ct;
	al.pb(ct);
	//scout << ct << " ";
	for(int i = 1; i + k - 1 < n; ++i){
		ct -= (v[i]>v[i - 1] && v[i]>v[i + 1]);
		ct += ((v[i + k - 2]>v[i + k - 3] && v[i + k - 2]>v[i + k - 1]));
		ans = max(ans, ct);
		//cout << ct << " ";
		al.pb(ct);
	}
	cout << ans + 1 << " ";
	for(int i = 0; i < al.size(); ++i){
		if(al[i] == ans){
			cout << i + 1 << ln;
			return;
		}
	}

}
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);cout.tie(nullptr);cerr.tie(nullptr);
  cin >> T;
  while(T--)solve();
}