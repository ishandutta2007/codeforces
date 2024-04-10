#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
	int n, q;
	cin >> n >> q;
	vector <int> ans(n + 1);
	set <int> s;
	for (int i = 0; i < n; i++)
		s.insert(i + 1);
	while (q--) {
		int l, r, x;
		cin >> l >> r >> x;
		vector <int> kek;
		for (auto it = s.lower_bound(l); it != s.upper_bound(r); it++) {
			if (x == *it)
				continue;
			int val = *it;
			ans[val] = x;
			kek.push_back(val);
		}
		for (int val : kek) 
			s.erase(val);
	}
	for (int i = 1; i <= n; i++)
		cout << ans[i] << " ";
	return 0;
}