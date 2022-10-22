#include<bits/stdc++.h>  
using namespace std;  
  
#define fast ios::sync_with_stdio(false);cin.tie(NULL)  
#define fi first  
#define se second  
#define all(v) (v).begin(),(v).end()  
#define pb push_back  
#define eb emplace_back
#define pre(a) cout<<fixed; cout.precision(a)
  
typedef long long ll;  
typedef pair<int,int> pii;  
typedef pair<ll,ll> pll;  
const long long INF = 1e18;  
const int inf = 1e9;

ll n, m;
ll fact[250010];
ll ans;

int main() {
	fast;

	cin >> n >> m;

	fact[0] = 1;
	for(ll i=1; i<=n; i++) {
		fact[i] = fact[i-1] * i % m;
	}

	for(ll i=n; i>=1; i--) {
		ans += i * fact[i] % m * fact[n - i + 1] % m;
		ans %= m;
	}

	cout << ans;
}