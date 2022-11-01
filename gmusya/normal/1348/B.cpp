#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		vector <int> a(n);
		for (int i = 0; i < n; i++)
			cin >> a[i];
		set <int> s;
		for (int i = 0; i < n; i++)
			s.insert(a[i]);
		if (s.size() > k) {
			cout << -1 << '\n';
			continue;
		}
		vector <int> all;
		while (!s.empty()) {
			all.push_back(*s.begin());
			s.erase(s.begin());
		}
		while (all.size() < k)
			all.push_back(a[0]);
		vector <int> b;
		int pos = 0;
		for (int i = 0; i < n; i++) {
			while (all[pos] != a[i]) {
				b.push_back(all[pos]);
				pos++;
				pos %= all.size();
			}
			b.push_back(all[pos]);
			pos++;
			pos %= all.size();
		}
		cout << b.size() << '\n';
		for (int i = 0; i < b.size(); i++)
			cout << b[i] << ' ';
		cout << '\n';
	}
	return 0;
}