#include <iostream>
#include <vector>

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n0, n1, n2;
		cin >> n0 >> n1 >> n2;
		if (n0 && !n1) {
			for (int i = 0; i <= n0; i++)
				cout << 0;
			cout << '\n';
			continue;
		}
		if (n2 && !n1) {
			for (int i = 0; i <= n2; i++)
				cout << 1;
			cout << '\n';
			continue;
		}
		if (!n2 && !n0) {
			vector <int> a(n1 + 1);
			for (int i = 1; i <= n1; i++)
				a[i] = 1 - a[i - 1];
			for (int i = 0; i <= n1; i++)
				cout << a[i];
			cout << '\n';
			continue;
		}
		if (!n2) {
			for (int i = 0; i < n0; i++)
				cout << 0;
			vector <int> a(n1 + 1);
			for (int i = 1; i <= n1; i++)
				a[i] = 1 - a[i - 1];
			for (int i = 0; i <= n1; i++)
				cout << a[i];
			cout << '\n';
			continue;
		}
		if (!n0) {
			for (int i = 0; i < n2; i++)
				cout << 1;
			vector <int> a(n1 + 1);
			a[0] = 1;
			for (int i = 1; i <= n1; i++)
				a[i] = 1 - a[i - 1];
			for (int i = 0; i <= n1; i++)
				cout << a[i];
			cout << '\n';
			continue;
		}
		for (int i = 0; i <= n0; i++)
			cout << 0;
		for (int i = 0; i <= n2; i++)
			cout << 1;
		vector <int> a(n1 - 1);
		for (int i = 1; i < n1 - 1; i++)
			a[i] = 1 - a[i - 1];
		for (int i = 0; i < n1 - 1; i++)
			cout << a[i];
		cout << '\n';
	}
	return 0;
}