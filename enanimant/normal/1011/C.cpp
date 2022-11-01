// July 26, 2018
// http://codeforces.com/contest/1011/problem/C

/*

*/


#include <bits/stdc++.h>

using namespace std;


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG)


	int n, m;
	cin >> n >> m;
	vector<int> a(n + 1), b(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] == 1) {
			cout << "-1\n";
			return 0;
		}
	}
	for (int i = 1; i <= n; i++) {
		cin >> b[i];
		if (b[i] == 1) {
			cout << "-1\n";
			return 0;
		}
	}

	double lo = 0.0, hi = 1e9;
	for (int it = 0; it < 200; it++) {
		double mid = (lo + hi) / 2;
		double weight = mid + m;
		for (int i = 1; i <= n; i++) {
			int x = i + 1;
			if (x == n + 1) x = 1;
			weight -= weight / a[i];
			weight -= weight / b[x];
		}
		if (weight < m) {
			lo = mid;
		}
		else {
			hi = mid;
		}
	}
    cout.precision(10);
	cout << (lo + hi) / 2 << '\n';


	return 0;
}