#include <iostream>
#include <algorithm>

#define endl '\n'

typedef long long ll;

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		ll x, y;
		ll a, b;
		cin >> x >> y;
		cin >> a >> b;
		if (x <= 0 && y >= 0) {
			cout << (abs(x) + abs(y)) * a << endl;
			continue;
		}
		if (x >= 0 && y <= 0) {
			cout << (abs(x) + abs(y)) * a << endl;
			continue;
		}
		x = abs(x);
		y = abs(y);
		cout << (max(x, y) - min(x, y)) * a + min(x,y) * min(2 * a, b) << endl;
	}
	return 0;
}