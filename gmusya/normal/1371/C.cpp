#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		long long a, b, n, m;
		cin >> a >> b >> n >> m;
		if (a + b < n + m || min(a, b) < m) {
			cout << "No\n";
			continue;
		}
		cout << "Yes\n";
	}
	return 0;
}