#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, a, b, c, d;
		cin >> n >> a >> b >> c >> d;
		int minw = (a - b) * n;
		int maxw = (a + b) * n;
		int L = max(minw, c - d);
		int R = min(maxw, c + d);
		if (L > R) cout << "No\n";
		else cout << "Yes\n";
	}
	return 0;
}