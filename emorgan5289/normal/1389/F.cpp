#include <bits/stdc++.h>
using namespace std;

multiset<array<int, 3>> a;
multiset<int> s;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		int l, r, t; cin >> l >> r >> t;
		a.insert(t-1 ? array{r, 1, -l} : array{l, 0, -r});
	}
	for (auto& [_, t, x] : a) {
		if (t && s.upper_bound(x) != s.begin())
			s.erase(--s.upper_bound(x)), n--;
		if (!t) s.insert(x);
	}
	cout << n << "\n";
}