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
		vector <int> b;
		b.push_back(a[0]);
		for (int i = 1; i < n - 1; i++)
			if ((a[i] > a[i - 1] && a[i] > a[i + 1]) || (a[i] < a[i - 1] && a[i] < a[i + 1]))
				b.push_back(a[i]);
		b.push_back(a[n - 1]);
		cout << b.size() << '\n';
		for (auto &now : b)
			cout << now << ' ';
		cout << '\n';
	}
	return 0;
}