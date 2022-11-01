#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		vector <int> a(n);
		for (int i = 0; i < n; i++)
			cin >> a[i];
		vector <int> p(m);
		for (int i = 0; i < m; i++) {
			cin >> p[i];
			p[i]--;
		}
		sort(p.begin(), p.end());
		int l = p[0];
		int r = p[0];
		for (int i = 1; i < m; i++) {
			if (r + 1 == p[i])
				r = p[i];
			else {
				sort(a.begin() + l, a.begin() + r + 2);
				l = p[i];
				r = p[i];
			}
		}
		sort(a.begin() + l, a.begin() + r + 2);
		bool tf = true;
		for (int i = 0; i < n - 1; i++)
			if (a[i] > a[i + 1])
				tf = false;
		if (tf)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}