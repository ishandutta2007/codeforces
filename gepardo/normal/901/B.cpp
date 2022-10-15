#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

int main() {
	int n; cin >> n;
	vector<int> a {1}, b {};
	for (int i = 0; i < n; i++) {
		swap(a, b);
		vector<int> c = b;
		c.insert(c.begin(), 1, 0);
		int sign = +1;
		for (int j = 0; j < (int)a.size(); j++) {
			if (!(-1 <= c[j] + a[j] && c[j] + a[j] <= +1)) {
				sign = -1;
				break;
			}
		}
		swap(c, a);
		for (int i = 0; i < (int)c.size(); i++) {
			a[i] += c[i] * sign;
		}
	}
	cout << a.size()-1 << endl;
	for (int i: a) {
		cout << i << " ";
	}
	cout << endl;
	cout << b.size()-1 << endl;
	for (int i: b) {
		cout << i << " ";
	}
	cout << endl;
	return 0;
}