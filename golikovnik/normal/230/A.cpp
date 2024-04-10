#include <bits/stdc++.h>
using namespace std;

int main() {
	int s, n;
	cin >> s >> n;
	vector<int> x(n), y(n);
	for (int i = 0; i < n; ++i) {
		cin >> x[i] >> y[i];
	}
	for (int i = 0; i < n; ++i) {
		int j = -1;
		int bonus = -1;
		for (int k = 0; k < n; ++k) {
			if (s > x[k] and y[k] > bonus) {
				j = k;
				bonus = y[k];
			}
		}
		if (j == -1) {
			cout << "NO\n";
			return 0;
		}
		s += bonus;
		x[j] = INT_MAX;
	}
	cout << "YES\n";
	return 0;
}