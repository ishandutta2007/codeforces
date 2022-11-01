#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

const ll INF = 1e18;

int n;
ll a, r, m;

ll f(ll x, vector <ll> &arr) {
	ll lsum = 0, rsum = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] > x) rsum += arr[i] - x;
		else lsum += x - arr[i];
	}
	ll hm = min(lsum, rsum);
	ll c = hm * m;
	lsum -= hm, rsum -= hm;
	c += lsum * a + rsum * r;
	return c;
}

int main() {
	cin >> n >> a >> r >> m;
	m = min(m, a + r);
	vector <ll> arr(n);
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	sort(arr.begin(), arr.end());
	ll ans = INF;
	ll L = 0;
	ll R = 1e9;
	while (L != R) {
		ll M1 = (L + R) / 2;
		ll M2 = M1 + 1;
		ll f1 = f(M1, arr), f2 = f(M2, arr);
		if (f1 < f2) 
			R = M2 - 1;
		if (f1 > f2) 
			L = M1 + 1;
		if (f1 == f2) {
			L = M1, R = M2;
			break;
		}
	}
	cout << f(L, arr);
	return 0;
}