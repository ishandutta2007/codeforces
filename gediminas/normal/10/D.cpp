#include <bits/stdc++.h>

using namespace std;
/*input
7
2 3 1 6 5 4 6
4
1 3 5 6
*/
/*input
5
1 2 0 2 1
3
1 0 1
*/
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	int a[n];

	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	int m;
	cin >> m;
	int b[m];

	for (int i = 0; i < m; ++i) {
		cin >> b[i];
	}

	int ilg[n] = {};
	vector<int> sek[n] = {};

	for (int j = 0; j < m; ++j) {
		int cur = 0;
		vector<int> s;

		for (int i = 0; i < n; ++i) {
			if (a[i] == b[j]) {
				if (cur + 1 > ilg[i]) {
					ilg[i] = cur + 1;
					sek[i] = s;
					sek[i].push_back(a[i]);
				}
			}
			else if (a[i] < b[j]) {
				if (cur < ilg[i]) {
					cur = ilg[i];
					s = sek[i];
				}
			}
		}
	}

	int ats = 0;
	int ai = 0;

	for (int i = 0; i < n; ++i) {
		if (ilg[i] > ats) {
			ats = ilg[i];
			ai = i;
		}
	}

	cout << ats << endl;
	for (auto&& x : sek[ai]) {
		cout << x << " ";
	}
}