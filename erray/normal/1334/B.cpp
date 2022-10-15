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
int t, n, x, k;
void solve(){
  cin >> n >> k;
  vi v;
  for(int i = 0; i < n; i++){cin >> x;v.pb(x);}
  sort(all(v));
	reverse(all(v));
	ll sum = 0;
	int i = 0;
  while(i < n && (sum+v[i])/(i + 1)>=k){
  	//cout << sum << " ";
  	sum += v[i++];
  }
  cout << i << ln;
} 
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);cout.tie(nullptr);cerr.tie(nullptr);
  cin >> t;
  while(t--)solve();
}