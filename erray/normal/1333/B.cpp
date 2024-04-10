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
#define mid (s + e)/2
#define ln '\n'
#define MAX (ll)(1<<30)
#define MOD 1000000007
#define mod 998244353
#define N 500005
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll; 
int t, n, x, a[N], b[N];
void solve(){
	cin >> n;
	bool ex[n + 1][2];
	memset(ex, 0, sizeof ex);
	for(int i = 0; i < n; i++){
		cin >> a[i];
		ex[i + 1][0]= (i != 0 ? ex[i][0] : 0) | a[i] < 0;
		ex[i + 1][1]= (i != 0 ? ex[i][1] : 0) | a[i] > 0;
	}
	bool b3 = 1;
	for(int i = 0; i < n; i++){
		cin >> b[i];
		if(b[i] == a[i])continue;
		//cout << ex[i][0] << " " << ex[i][1] << ln;
		b3&=ex[i][b[i] > a[i]];
	}
	cout << (a[0] == b[0] && b3 ? "YES" : "NO") << ln;
}
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);cout.tie(NULL);
  cin >> t;
  while(t--)solve();
}