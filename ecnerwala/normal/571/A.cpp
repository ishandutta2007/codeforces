#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ll a, b, c, l;
	cin >> a >> b >> c >> l;
	ll res = (l + 3) * (l + 2) * (l + 1) / 6; // stars and bars
	for(ll i = 0; i <= l; i++) {
		// a + i >= b + c + k + j
		// a + i - b - c >= k + j
		// l - i >= k + j 
		ll s;
	   	s = min(a - b - c + i, l - i);
		if(s >= 0) res -= (s + 2) * (s + 1) / 2;
	   	s = min(b - a - c + i, l - i);
		if(s >= 0) res -= (s + 2) * (s + 1) / 2;
	   	s = min(c - a - b + i, l - i);
		if(s >= 0) res -= (s + 2) * (s + 1) / 2;
	}
	cout << res << '\n';
	return 0;
}