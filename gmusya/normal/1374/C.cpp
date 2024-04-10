#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int bal = 0;
		vector <char> a(n);
		for (int i = 0; i < n; i++)
			cin >> a[i];
		int ans = 0;
		for (int i = 0; i < n; i++) {
			if (a[i] == '(') bal++;
			else bal--;
			ans = min(ans, bal);
		}
		cout << -ans << '\n';
	}
	return 0;
}