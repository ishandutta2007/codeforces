#include <bits/stdc++.h>

using namespace std;
/*input
4
2
1 4
4
2 8 3 4
5
3 8 5 9 7
6
2 7 5 3 4 8

*/
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		vector<int> a(n);

		for (auto &&i : a) {
			cin >> i;
		}

		sort(a.begin(), a.end());

		for (int i = 0; i < n / 2; ++i) {
			cout << a[i+1] << " " << a[0] << "\n";
		}
	}
}