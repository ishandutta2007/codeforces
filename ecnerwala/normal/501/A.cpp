#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

inline ll score(ll p, ll t) {
	return max(p * 3 / 10, p - p / 250 * t);
}

int main() {
	ll a, b, c, d;
	cin >> a >> b >> c >> d;
	ll l = score(a, c), r = score(b, d);
	if(l > r) cout << "Misha\n";
	else if(l < r) cout << "Vasya\n";
	else cout << "Tie\n";
	return 0;
}