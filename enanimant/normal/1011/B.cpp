// July 26, 2018
// http://codeforces.com/contest/1011/problem/B

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
	vector<int> a(101);
	for (int i = 0; i < m; i++) {
		int t;
		cin >> t;
		a[t]++;
	}

	int lo = 1, hi = 101;
	while (lo < hi) {
		int mid = (lo + hi) / 2;
		int ppl = 0;
		for (int i = 1; i <= 100; i++) {
			ppl += a[i] / mid;
		}
		if (ppl >= n) {
			// can support at least n people
			lo = mid + 1;
		}
		else {
			hi = mid;
		}
	}
	cout << lo - 1 << '\n';

	return 0;
}