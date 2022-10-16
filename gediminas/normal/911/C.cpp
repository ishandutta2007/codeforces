/*input
4 2 3

*/
#include <bits/stdc++.h>

using namespace std;

int main () {
	int a, b, c;
	cin >> a >> b >> c;
	int kie[1501] = {};
	kie[a]++;
	kie[b]++;
	kie[c]++;
	bool ar = kie[1] >= 1 || kie[2] >= 2 || kie[3] >= 3 || (kie[2] >= 1 and kie[4] >= 2);

	if (ar)
		cout << "YES";
	else
		cout << "NO";

	return 0;
}