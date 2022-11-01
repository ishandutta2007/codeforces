#include <iostream>
#include <vector>

#define ll long long

using namespace std;

int main() {
	ll n, x, y;
	cin >> n >> x >> y;
	ll cnt1 = 0, cnt2 = 0, cnt3 = 0, cnt4 = 0;
	for (ll i = 0; i < n; i++) {
		ll x1, y1;
		cin >> x1 >> y1;
		if (x1 > x)
			cnt1++;
		if (x1 < x)
			cnt2++;
		if (y1 > y)
			cnt3++;
		if (y1 < y)
			cnt4++;
	}
	if (cnt1 >= cnt2 && cnt1 >= cnt3 && cnt1 >= cnt4) {
		cout << cnt1 << endl;
		cout << x + 1 << " " << y;
		return 0;
	}
	if (cnt2 >= cnt1 && cnt2 >= cnt3 && cnt2 >= cnt4) {
		cout << cnt2 << endl;
		cout << x - 1 << " " << y;
		return 0;
	}
	if (cnt3 >= cnt1 && cnt3 >= cnt2 && cnt3 >= cnt4) {
		cout << cnt3 << endl;
		cout << x << " " << y + 1;
		return 0;
	}
	cout << cnt4 << endl;
	cout << x << " " << y - 1;
	return 0;
}