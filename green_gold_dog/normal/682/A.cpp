#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

ll power(ll a, ll p, ll m) {
	if (p == 1) {
		return a % m;
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

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll a, b;
	cin >> a >> b;
	cout << (((a/5)*(b/5))+(((a+1)/5)*((b+4)/5))+(((a+2)/5)*((b+3)/5))+(((a+3)/5)*((b+2)/5))+(((a+4)/5)*((b+1)/5)));
}