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
const int mod = 1e9 + 7;
string s;
vi pl[30];
vi v;
ll ans = 1;
void solve(){
	cin >> s;
	for(int i = 0; i < s.size(); i++)if(s[i] == 'a' || s[i] == 'b')v.pb(s[i] == 'a');
	int ct = 0;
	for(int a : v){
		//cout << a << ln;
		ct += a;
		if(!a&&ct!=0){
			ans = (ans * (ct + 1))%mod;
			ct = 0;
		}
	}
	cout << ((ans * ++ct) - 1ll + mod)%mod;
}
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);cout.tie(nullptr);cerr.tie(nullptr);
  solve();
}