/*input
456
*/
#include <bits/stdc++.h>

using namespace std;

int main () {
	int n;
	cin >> n;

	vector<int> ats;

	for (int i = 0; i <= 100 and i < n; i++) {
		int sk = n - i;
		int su = 0;

		while (sk > 0) {
			su += sk % 10;
			sk /= 10;
		}

		if (su == i)
			ats.push_back(n - i);
	}

	cout << ats.size() << "\n";

	sort(ats.begin(), ats.end());

	for (auto && x : ats)
		cout << x << " ";



	return 0;
}