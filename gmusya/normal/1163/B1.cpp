#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector <int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	vector <vector <int>> b(n, vector <int>(10));
	b[0][a[0] - 1] = 1;
	for (int i = 1; i < n; i++) {
		b[i] = b[i - 1];
		b[i][a[i] - 1]++;
	}
	for (int i = n - 1; i >= 0; i--) {
		vector <int> c;
		for (int j = 0; j < 10; j++)
			if (b[i][j] != 0)
				c.push_back(b[i][j]);
		sort(c.begin(), c.end());
		if (c.size() == 1) {
			cout << i + 1;
			return 0;
		}
		if (c[0] == 1 && c[1] == c[c.size() - 1]) {
			cout << i + 1;
			return 0;
		}
		if (c[0] == c[c.size() - 1] - 1 && c[0] == c[c.size() - 2]) {
			cout << i + 1;
			return 0;
		}
	}
	return 0;
}