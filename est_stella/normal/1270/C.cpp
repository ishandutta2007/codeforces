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

int n;

void solve() {
	cin >> n;

	ll x = 0, y = 0;
	for(int i=1; i<=n; i++) {
		ll d;
		cin >> d;

		x += d;
		y ^= d;
	}

	if(x == 2 * y) {
		cout << 0 << "\n\n";
		return;
	}

	
	cout << 3 << "\n";
	ll a = 1e16;
	x += a;
	if(x & 1) a++, x++;
	y ^= a;

	cout << (2 * y - x) / 2 << " " << (2 * y - x) / 2 << " " << a << "\n";
}

int main() {
	fast;

	int t;
	cin >> t;

	while(t--) {
		solve();
	}
}