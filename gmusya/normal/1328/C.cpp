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
		for (int i = 0; i < n; i++) {
			char c;
			cin >> c;
			a[i] = c - '0';
		}
		vector <int> ans1(n), ans2(n);
		int pos = n;
		for (int i = 0; i < n; i++)
			if (a[i] % 2) {
				pos = i;
				break;
			}
		for (int i = 0; i < n; i++) {
			if (i < pos) 
				ans1[i] = ans2[i] = a[i] / 2;
			if (i == pos) 
				ans1[i] = 1;
			if (i > pos)
				ans2[i] = a[i];
		}
		for (int i = 0; i < n; i++)
			cout << ans1[i];
		cout << '\n';
		for (int i = 0; i < n; i++)
			cout << ans2[i];
		cout << '\n';
	}
	return 0;
}