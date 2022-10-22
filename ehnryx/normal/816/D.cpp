#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod = 1e9+7;

// Find x,y such that ax + by = d = gcd(a,b)
// * a^-1 (mod m): if (egcd(a,m,x,y) == 1) return (x+m)%m; else ERROR;
ll egcd(ll a, ll b, ll& x, ll &y) {
  if (!b) {x = 1; y = 0; return a;}//to ensure d>=0: x=sgn(a);y=0;return abs(a);
  ll d = egcd(b, a%b, y, x); y -= x * (a/b); return d; }

ll inv[200000];
void geninv(ll n) {
	ll x;
	for (int i = 1; i <= n; i++) {
		egcd(mod, i, x, inv[i]);
	}
}

ll memo[200000];
ll ncr(ll n, ll r) {
	if (r == 0) return memo[r] = 1;
	if (r > n/2) return memo[r] = memo[n-r];
	return memo[r] = ((memo[r-1]*(n-r+1)) % mod * inv[r]) % mod;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	// ll arr[4][200000];
	vector<ll> arr[4];
	for (int i = 0; i < 4; i++)
		arr[i].resize(200000);
	int n;
	cin >> n;
	geninv(n/2);
	for (int i = 0; i < n; i++) {
		cin >> arr[n%4][i];
	}
	int sgn = 1;
	while (n%4 != 1) {
		for (int i = 0; i < n; i++) {
			arr[(n-1)%4][i] = (arr[n%4][i] + sgn*arr[n%4][i+1]) % mod;
			sgn *= -1;
		}
		sgn *= -1;
		n--;
	}
	ll sum = 0;
	for (int i = 0; i <= n/2; i++) {
		sum = (sum + (arr[1][2*i]*ncr(n/2, i)) % mod) % mod;
	}
	cout << (sum + mod) % mod << endl;

	return 0;
}