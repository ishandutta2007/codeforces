#include <iostream>
#include <vector>

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector <int> a(n);
		for (int i = 0; i < n; i++)
			cin >> a[i];
		if (n == 1 && a[0] % 2) {
			cout << -1 << endl;
			continue;
		}
		if (n == 1) {
			cout << 1 << endl;
			cout << 1 << endl;
			continue;
		}
		vector <int> ch, nech;
		for (int i = 0; i < n; i++) {
			if (a[i] % 2)
				nech.push_back(i + 1);
			else
				ch.push_back(i + 1);
		}
		if (ch.size() > 0) {
			cout << 1 << endl;
			cout << ch[0] << endl;
			continue;
		}
		cout << 2 << endl;
		cout << nech[0] << " " << nech[1] << endl;
	}
	return 0;
}