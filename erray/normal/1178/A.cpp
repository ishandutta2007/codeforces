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
int n, x;
vi v;
ll sum = 0;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);cout.tie(nullptr);cerr.tie(nullptr);
  cin >> n;
  for(int i = 0; i < n; i++){
  	cin >> x;
  	sum += x;
  	v.pb(x);
  }
  sum /=2;
  ++sum;
  sum -= v[0];
  vi ans;
  int ind = 1;
  ans.pb(1);
  for(auto a : v){

  	if(a <= v[0] / 2){
  		sum-=a;
  		ans.pb(ind);
  	}
  	  	++ind;
  }
  if(sum > 0){
  	cout << 0;
  	return 0;
  }
  cout << ans.size() << ln;
  for(auto a : ans)cout << a << " ";
  

}