#include <bits/stdc++.h>

using namespace std;
/*input
3
0 0 0
*/
/*input
5
3 3 2 2 2
*/
/*input
4
0 1 2 3
*/
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	map<int, set<int>> a;

	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		a[x].insert(i);
	}

	bool ger = true;
	vector<int> ans(n);

	int j = 1;

	for (auto &&[i, s] : a) {
		if (s.size() % (n - i) != 0) {
			ger = false;
			break;
		}

		int k = 0;

		for (auto &&x : s) {
			ans[x] = j;
			k++;

			if (k == n - i) {
				j++;
				k = 0;
			}
		}
	}

	if (ger) {
		cout << "Possible\n";

		for (auto &&i : ans) {
			cout << i << " ";
		}
	}
	else {
		cout << "Impossible";
	}
}