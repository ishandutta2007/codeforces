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
int t, x, arr[3];
ll calc(ll n1, ll n2, ll n3){return (n1 - n2)*(n1 - n2) + (n3 - n2)*(n3 - n2) + (n1 - n3)*(n1 - n3);}
ll tp(vi a, vi b, vi c){
	int p1 = 0, p2 = 0;
	ll r = (1ll<<62);
	for(int i : a){
		while(p1 + 1 < b.size() && b[p1 + 1] <= i)p1++;
		while(p2 + 1 < c.size() && c[p2] < i)p2++;
		r = min(r, calc(i, b[p1], c[p2]));
	}
	return r;
}
void solve(){
	ll ans = (1ll<<62);
	vi v[3];
	for(int i = 0; i < 3; i++)cin >> arr[i];
	for(int i = 0; i < 3; i++){
		while(arr[i]--){
			cin >> x;
			v[i].pb(x);
		}
		sort(all(v[i]));
	}
	int p[3] = {0, 1, 2};
	for(int i = 0; i < 6; i++, next_permutation(p, p + 3))ans = min(ans, tp(v[p[0]], v[p[1]], v[p[2]]));
	cout << ans << ln;
}
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);cout.tie(nullptr);cerr.tie(nullptr);
  cin >> t;
  while(t--)solve();
}