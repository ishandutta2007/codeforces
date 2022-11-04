#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

ll power(ll a, ll p, ll m = (ll)1e18) {
	if (p == 0) {
		return 1;
	}
	if (p % 2 == 0) {
		ll ans = power(a, p/2, m);
		return ans*ans%m;
	} else {
		return power(a, p-1, m)*a%m;
	}
}

ll gcd(ll a, ll b) {
	if (a == 0) {
		return b;
	}
	if (b == 0) {
		return a;
	}
	return gcd(min(a, b), max(a, b)%min(a, b));
}

ll lcm(ll a, ll b) {
	return a*b/gcd(a, b);
}

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll n, k;
	cin >> n >> k;
	cout << lcm(n, power(10, k));
}