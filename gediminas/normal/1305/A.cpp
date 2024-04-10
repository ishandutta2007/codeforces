#include <bits/stdc++.h>

using namespace std;

/*input

*/
int main () {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;
		vector<int> a(n), b(n);

		for (auto && i : a) {
			cin >> i;
		}

		for (auto && i : b) {
			cin >> i;
		}

		sort(a.begin(), a.end());
		sort(b.begin(), b.end());

		for (auto && i : a) {
			cout << i << " ";
		}

		cout << "\n";

		for (auto && i : b) {
			cout << i << " ";
		}

		cout << "\n";
	}



}