#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		int s = 0;
		for (int j = 0; j < 3; ++j) {
			int x;
			cin >> x;
			s += x;
		}
		ans += (s >= 2);
	}
	cout << ans << "\n";
	return 0;
}