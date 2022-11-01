#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int n, a, b;
		cin >> n >> a >> b;
		if (a + b > n - 2 || abs(a - b) > 1) {
			cout << -1 << '\n';
			continue;
		}
		vector<int> p(n);
		if (a == b) {
			for (int i = a + b + 1; i < n; ++i) {
				p[i] = i;
			}
			int val = 0;
			for (int i = 0; i <= a + b; i += 2) {
				p[i] = val++;
			}
			for (int i = a + b - 1; i >= 0; i -= 2) {
				p[i] = val++;
			}
		}
		bool swapped = false;
		if (a > b) {
			swapped = true;
			swap(a, b);
		}
		if (b > a) {
			int val = 0;
			for (int i = 1; i <= 2 * b - 1; i += 2) {
				p[i] = val++;
			}
			for (int i = 2 * b; i >= 0; i -= 2) {
				p[i] = val++;
			}
			for (int i = 2 * b + 1; i < n; ++i) {
				p[i] = val++;
			}
		}
		if (swapped) {
			for (int& x : p) {
				x = n - x - 1;
			}
		}
		for (int x : p) {
			cout << x + 1 << ' ';
		}
		cout << '\n';
	}
	return 0;
}