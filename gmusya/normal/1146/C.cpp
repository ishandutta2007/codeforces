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
		int p = 1;
		while (p <= n) p *= 2;
		p /= 2;
		int ans = 0;
		while (p) {
			vector <int> a, b;
			for (int i = 1; i <= n; i++) {
				if (i & p) a.push_back(i);
				else b.push_back(i);
			}
			cout << a.size() << " " << b.size() << " ";
			for (int i = 0; i < a.size(); i++)
				cout << a[i] << " ";
			for (int i = 0; i < b.size(); i++)
				cout << b[i] << " ";
			cout << endl;
			cout.flush();
			int x;
			cin >> x;
			ans = max(ans, x);
			p /= 2;
		}
		cout << -1 << " " << ans << endl;
		cout.flush();
	}
	return 0;
}