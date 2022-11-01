#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int a, b;
		cin >> a >> b;
		if (a > b) swap(a, b);
		int ans = 0;
		int k = min(a, b - a);
		ans += k;
		a -= k;
		b -= 2 * k;
		int z = a / 3;
		ans += 2 * z;
		a %= 3, b %= 3;
		ans += (a + b) / 3;
		cout << ans << '\n';
	}
	return 0;
}