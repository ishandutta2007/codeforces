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
ll n, m, k, x;
void solve(){
	cin >> n >> m >> k;
	vector<ll> v(n);
	for(int i = 0; i < n; i++)cin >> v[i];
	sort(all(v));
	reverse(all(v));
	int f = m/(k + 1);
	ll ans = 0;
	int k2 = m%(k + 1);
	cout << (ll)v[0]*f*k + v[1]*f + k2*v[0] << ln;
}
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);cout.tie(nullptr);cerr.tie(nullptr);
  solve();
}