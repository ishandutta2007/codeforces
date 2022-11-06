#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

ll gcd(ll a, ll b) {
	if (a == 0) {
		return b;
	}
	if (b == 0) {
		return a;
	}
	return gcd(a%b, b%a);
}

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll n, a = 1;
	cin >> n;
	vector<ll> ans(1, 1);
	for (ll i = 2; i < n-1; i++) {
		if (gcd(i, n) == 1) {
			ans.push_back(i);
			a = (a*i)%n;
		}
	}
	if (a != 1) {
		ans.push_back(n-1);
	}
	cout << ans.size() << endl;
	for (auto i : ans) {
		cout << i << ' ';
	}
}