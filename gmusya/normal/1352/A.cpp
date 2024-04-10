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
		vector <int> a;
		while (n) {
			a.push_back(n % 10);
			n /= 10;
		}
		reverse(a.begin(), a.end());
		int cnt = 0;
		for (int i = 0; i < a.size(); i++)
			cnt += (a[i] > 0);
		cout << cnt << '\n';
		for (int i = 0; i < a.size(); i++) {
			if (!a[i]) continue;
			cout << a[i];
			for (int j = i + 1; j < a.size(); j++)
				cout << '0';
			cout << ' ';
		}
		cout << '\n';
	}
	return 0;
}