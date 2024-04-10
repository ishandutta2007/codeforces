#include<bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int n; cin >> n;
	vector<int> a(n); for (auto& a : a) cin >> a;

	int ma = *max_element(a.begin(), a.end());
	int mi = *min_element(a.begin(), a.end());

	if (n <= 2 || ma == mi) {
		cout << -1 << '\n';
		exit(0);
	}
	if (n == 3 && a[0] == a[2]) {
		cout << -1 << '\n';
		exit(0);
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (a[i] == a[j]) continue;
			swap(a[i], a[j]);
			if (!is_sorted(a.begin(), a.end(), std::less()) && !is_sorted(a.begin(), a.end(), std::greater())) {
				cout << i+1 << ' ' << j+1 << '\n';
				exit(0);
			}
			swap(a[i], a[j]);
		}
	}

	return 0;
}