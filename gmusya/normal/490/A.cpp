#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector <int> a, b, c;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		if (x == 1)
			a.push_back(i + 1);
		if (x == 2)
			b.push_back(i + 1);
		if (x == 3)
			c.push_back(i + 1);
	}
	cout << min(min(a.size(), b.size()), c.size()) << endl;
	for (int i = 0; i < min(min(a.size(), b.size()), c.size()); i++)
		cout << a[i] << " " << b[i] << " " << c[i] << endl;
	return 0;
}