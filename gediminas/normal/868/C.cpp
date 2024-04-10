/*input
3 2
1 0
1 1
0 1
*/
#include <bits/stdc++.h>

using namespace std;

int main () {
	int n, k;
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n >> k;

	int kie[16] = {};

	for (int i = 0; i < n; i++) {
		int sk = 0;

		for (int j = 0; j < k; j++) {
			int x;
			cin >> x;
			sk |= x * (1 << j);
		}

		kie[sk]++;
	}

	bool ar = false;

	if (kie[0])
		ar = true;
	else if (kie[1] and kie[2])
		ar = true;
	else if (kie[1] and kie[4])
		ar = true;
	else if (kie[1] and kie[8])
		ar = true;
	else if (kie[2] and kie[4])
		ar = true;
	else if (kie[2] and kie[8])
		ar = true;
	else if (kie[4] and kie[8])
		ar = true;
	else if (kie[3] and kie[12])
		ar = true;
	else if (kie[5] and kie[10])
		ar = true;
	else if (kie[6] and kie[9])
		ar = true;
	else if (kie[3] and kie[4])
		ar = true;
	else if (kie[3] and kie[8])
		ar = true;
	else if (kie[5] and kie[2])
		ar = true;
	else if (kie[5] and kie[8])
		ar = true;
	else if (kie[9] and kie[2])
		ar = true;
	else if (kie[9] and kie[4])
		ar = true;
	else if (kie[6] and kie[1])
		ar = true;
	else if (kie[6] and kie[8])
		ar = true;
	else if (kie[10] and kie[1])
		ar = true;
	else if (kie[10] and kie[4])
		ar = true;
	else if (kie[12] and kie[1])
		ar = true;
	else if (kie[12] and kie[2])
		ar = true;
	else if (kie[8] and kie[15 - 8])
		ar = true;
	else if (kie[4] and kie[15 - 4])
		ar = true;
	else if (kie[2] and kie[15 - 2])
		ar = true;
	else if (kie[1] and kie[15 - 1])
		ar = true;

	cout << (ar ? "YES" : "NO");

	return 0;
}