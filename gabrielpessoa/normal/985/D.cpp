#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll lim = 1.5e9;

ll n, h;

ll somaPa(ll inicio, ll size) {
	if(2e18/size <= size + inicio + inicio - 1) return inf;
	return size * (size + inicio + inicio - 1) / 2;
}

ll calc(ll n, ll h) {
	if(n <= h) {
		return n < lim ? (n * (n+1) / 2) : inf;
	} else {
		if(h >= lim) return inf;
		ll aux1 = h*(h-1)/2;
		ll aux2 = somaPa(h, (n - h + 1)/2);
		ll aux3 = somaPa(h, (n - h + 2)/2);
		if(aux1 >= 1e18 || aux2 >= 1e18 || aux3 >= 1e18) return inf;
		return aux1 + aux2 + aux3;
	}
}

int main() {
	//cout << somaPa(4, 2) << '\n';
	//return 0;
	cin >> n >> h;
	ll l = 1, r = n;
	while(r > l + 1) {
		ll m = (l + r)/2;
		if(calc(m, h) >= n) {
			r = m;
		} else {
			l = m;
		}
	}
	if(calc(l, h) >= n) {
		cout << l << '\n';
	} else {
		cout << r << '\n';
	}
}