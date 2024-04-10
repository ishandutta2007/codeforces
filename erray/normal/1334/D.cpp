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
ll t, n, l, r;
void solve(){
	cin >> n >> l >> r;
	vector <ll>  v;
	ll prev = 0;
	for(int i = 1; i <= n; i++){
		v.pb((prev == 0 ? 0 : prev + 1));
		prev += (n - i)*2;
	}
	prev++;
	while(r-l+1){
		auto a = lower_bound(all(v), l);
		if(*a > l)--a;
		if(l == prev)cout << 1 << ' ';
		else if(l%2)cout << (a - v.begin()) + 1 << ' ';
		else{
			cout << ((a - v.begin()) + 1 + (l-(*a - 1))/2) << ' '; 
		}
		l++;
	}
	cout << ln;
}
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);cout.tie(nullptr);cerr.tie(nullptr);
  cin >> t;
  while(t--)solve();
}