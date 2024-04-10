#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define umap unordered_map
#define all(v) v.begin(),v.end()
#define st first
#define nd second
#define L (nd<<1)
#define R L|1
#define mid (s + e)>>1
#define ln '\n'
#define MAX (ll)(1<<30)
#define MOD 1000000007a 

#define mod 998244353
#define N 500005
using namespace std;
typedef long long ll;
typedef pair<ll ,ll> pii;
typedef vector<int> vi;
int t, n, m;
void solve(){
	ll ans = 1;
	cin >> n >> m;
	n++;
	for(int i = 0; (1ll<<i) < n; i++){
		ans = ((ll)ans * (min((1ll<<(i + 1)), (ll)n) - (1ll<<i) + 1))%m;
	}
	cout << (ans - 1 + m) % m << ln;
}
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);cout.tie(NULL);
  cin >> t;
  while(t--)solve();  

}