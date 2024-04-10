#include <iostream>
#include <vector>

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector <int> a, b;
		for (int i = 0; i < n + n; i++) {
			int x;
			cin >> x;
			if (x % 2) b.push_back(i + 1);
			else a.push_back(i + 1);
		}
		if (a.size() % 2) {
			a.pop_back();
			b.pop_back();
		}
		else {
			if (a.size()) a.pop_back(), a.pop_back();
			else b.pop_back(), b.pop_back();
		}
		vector <int> c;
		for (int i = 0; i < a.size(); i += 2)
			cout << a[i] << ' ' << a[i + 1] << '\n';
		for (int i = 0; i < b.size(); i += 2)
			cout << b[i] << ' ' << b[i + 1] << '\n';
	}
	return 0;
}