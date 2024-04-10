#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; ++i) {
			a[i] = i + 2;
		}
		for (int i = 0; i < n; ++i) {
			cout << a[i] << ' ';
		}
		cout << '\n';
	}
	return 0;
}