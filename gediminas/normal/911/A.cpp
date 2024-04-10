/*input
2
3 3
*/
#include <bits/stdc++.h>

using namespace std;

int main () {
	int n, ats;
	cin >> n;
	ats = n;
	int a[n];

	for (int i = 0; i < n; i++)
		cin >> a[i];

	int mi = a[0];

	for (int i = 0; i < n; i++)
		mi = min(mi, a[i]);

	int la = -1;

	for (int i = 0; i < n; i++) {
		if (a[i] == mi) {
			if (la != -1)
				ats = min(ats, i - la);

			la = i;
		}
	}

	cout << ats;

	return 0;
}