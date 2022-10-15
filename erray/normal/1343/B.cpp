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
int T, n, x; 
void solve(){
	cin >> n;
	if((n>>1)&1){
		cout << "NO" << ln;
		return;
	}
	cout << "YES" << ln;
	for(int i = 2; i <= n; i+= 2){
		cout << i << " ";
	}
	for(int i = 1; i < n - 2; i+= 2){
		cout << i << " ";
	}
	cout << n + n/2 - 1 << ln;
}
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);cout.tie(nullptr);cerr.tie(nullptr);
  cin >> T;
  while(T--)solve();
}