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
int T,n , k;
map <ll, ll> sum;  
void solve(){	
	sum.clear();
	cin >> n >> k; 
	vi v(n);
	ll ans = n*2;
	vi l, h; 
	for(int i = 0; i < n; ++i)cin >> v[i];
	for(int i = 0; i < n/2; i++){
		int a = v[i], b = v[n - i - 1];
		if(a > b)swap(a, b);
		l.pb(a);
		h.pb(b);
		sum[a + b]++;
	}
	sort(all(l));
	sort(all(h));
	int p1 = 0, p2 = 0;
	for(int i = 2; i <= k*2; ++i){
		while(p1 < l.size() && l[p1] < i)p1++;
		while(p2 < h.size() && h[p2] + k < i)p2++;
		//cout << p1 << " " << p2 << ln;
		ans = min(ans, n/2 - sum[i] + l.size() - p1 + p2);
	}
	cout << ans << ln;
}
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);cout.tie(nullptr);cerr.tie(nullptr);
  cin >> T;
  while(T--)solve();

}