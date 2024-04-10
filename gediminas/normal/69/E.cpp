/*input
6 4
3
3
3
4
4
2
*/
#include <bits/stdc++.h>

using namespace std;

int main () {
	int n, k;
	cin >> n >> k;
	int a[n];

	for (int i = 0; i < n; i++)
		cin >> a[i];

	set<int, greater<int>> ma;
	map<int, int> kie;

	for (int i = 0; i < k; i++) {
		kie[a[i]]++;

		if (kie[a[i]] == 1)
			ma.insert(a[i]);
		else if (kie[a[i]] == 0 or kie[a[i]] == 2)
			ma.erase(a[i]);
	}

	if (ma.empty())
		cout << "Nothing\n";
	else
		cout << *ma.begin() << "\n";

	for (int j = k; j < n; j++) {
		kie[a[j]]++;

		if (kie[a[j]] == 1)
			ma.insert(a[j]);
		else if (kie[a[j]] == 0 or kie[a[j]] == 2)
			ma.erase(a[j]);

		kie[a[j - k]]--;

		if (kie[a[j - k]] == 1)
			ma.insert(a[j - k]);
		else if (kie[a[j - k]] == 0 or kie[a[j - k]] == 2)
			ma.erase(a[j - k]);

		if (ma.empty())
			cout << "Nothing\n";
		else
			cout << *ma.begin() << "\n";

	}


	return 0;
}