/*input
4
0 3
2 5
4 2
4 0

*/
#include <bits/stdc++.h>

using namespace std;

int main () {
	int n;
	cin >> n;
	long long cap = 0, zm = 0;

	for (int i = 0; i < n; i++) {
		long long a, b;
		cin >> a >> b;
		zm = zm - a + b;
		cap = max(cap, zm);
	}

	cout << cap;


	return 0;
}