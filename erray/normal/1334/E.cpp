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
const int mod = 998244353;
map <ll, ll> dp;
vector <ll> dv;
ll DP(ll num){
	if(dp.find(num)!=dp.end())return dp[num];
	ll r = 0;	
	for(int i = 0; i < dv.size(); i++)if(num%dv[i]==0)r = (r + DP(num/dv[i])%mod);
	return dp[num] = max(r, 1ll);
}  
ll n, a, b;
int q;
void query(){
	cin >> a >> b;
	ll g = __gcd(a, b);
	cout << DP(a/g)*DP(b/g)%mod << ln;
}
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);cout.tie(nullptr);cerr.tie(nullptr);
  cin >> n >> q;
  for(ll i = 2; i*i <= n; i++){
  	int ct = 0;
  	while(n%i == 0){
  		n/=i;
  		ct++;
  	}
  	if(ct)dv.pb(i);
  }
  if(n!= 1)dv.pb(n);
  //for(ll i : dv)cerr << i << " ";
  while(q--)query();	
}