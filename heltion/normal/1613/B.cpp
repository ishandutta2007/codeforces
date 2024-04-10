#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	for (cin >> t; t; t -= 1) {
		int n;
		cin >> n;
		vector<int> a(n);
		for (int& ai : a) cin >> ai;
		ranges::sort(a);
		for (int i = 1; i <= n / 2; i += 1)
			cout << a[i] << " " << a[0] << "\n";
	}
	return 0;
}