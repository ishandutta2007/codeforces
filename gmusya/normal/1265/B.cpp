#include <iostream>
#include <vector>
#include <algorithm>

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
		vector <int> b(n);
		for (int i = 0; i < n; i++)
			b[a[i] - 1] = i + 1;
		vector <int> mi(n);
		mi[0] = b[0];
		for (int i = 1; i < n; i++)
			mi[i] = min(mi[i - 1], b[i]);
		vector <int> ma(n);
		ma[0] = b[0];
		for (int i = 1; i < n; i++)
			ma[i] = max(ma[i - 1], b[i]);
		for (int i = 0; i < n; i++)
			cout << (ma[i] - mi[i] < i + 1);
		cout << endl;
	}
	return 0;
}