#include <bits/stdc++.h>

using namespace std;
/*input
6
4 1
0 0 0 1
3 1
3 3 3
11 3
0 1 2 2 3 3 3 4 4 4 4
5 3
1 2 3 4 5
9 4
2 2 3 5 7 11 13 13 17
10 7
0 1 1 2 3 3 4 5 5 6

*/
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int t;
	cin >> t;

	while (t--) {
		set<int> a;
		int n, k;
		cin >> n >> k;

		for (int i = 0; i < n; ++i) {
			int t;
			cin >> t;
			a.insert(t);
		}

		if (a.size() <= k) {
			cout << 1 << "\n";
		}
		else if (k == 1) {
			cout << -1 << "\n";
		}
		else {
			cout << (a.size() - 2) / (k-1) + 1 << "\n";
		}
	}
}