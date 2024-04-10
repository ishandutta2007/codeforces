#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

ll pow(ll a, ll e) {
	ll res = 1;
	while(e) res *= a, e--;
	return res;
}

ll dsum(ll a) {
	ll res = 0;
	while(a) res += a % 10, a /= 10;
	return res;
}

int main() {
	ll a, b, c; cin >> a >> b >> c;
	vector<ll> res;
	for(ll s = 1; s <= 81; s++) {
		ll v = pow(s, a) * b + c;
		if(v > 0 && v < 1e9 && dsum(v) == s) res.push_back(v);
	}
	sort(res.begin(), res.end());
	cout << res.size() << '\n';
	for(ll i : res)  cout << i << ' ';
	cout << '\n';
	return 0;
}