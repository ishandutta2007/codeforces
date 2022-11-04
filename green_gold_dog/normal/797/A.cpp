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
	vector<ll> ans;
	for (ll i = 2; i*i <= n; i++) {
		while (n % i == 0) {
			ans.push_back(i);
			n /= i;
		}
	}
	if (n > 1) {
		ans.push_back(n);
	}
	if (ans.size() < k) {
		cout << -1;
	} else {
		ll a = 1;
		for (ll i = 0; i < k-1; i++) {
			cout << ans[i] << ' ';
		}
		for (ll i = k-1; i < ans.size(); i++) {
			a *= ans[i];
		}
		cout << a;
	}
}