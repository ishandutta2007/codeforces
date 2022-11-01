#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector <int> a(n);
		for (int i = 0; i < n; i++) {
			char c;
			cin >> c;
			a[i] = c - '0';
		}
		int pos1 = n - 1;
		while (pos1 >= 0 && a[pos1] == 1) pos1--;
		int pos0 = 0;
		while (pos0 < n && a[pos0] == 0) pos0++;
		if (pos1 + 1 == pos0) {
			for (auto &now : a) cout << now;
			cout << '\n';
			continue;
		}
		for (int i = 0; i < pos0; i++)
			cout << '0';
		cout << '0';
		for (int i = pos1 + 1; i < n; i++)
			cout << '1';
		cout << '\n';
	}
	return 0;
}