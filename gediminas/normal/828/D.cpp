/*input
8 6
*/
#include <bits/stdc++.h>

using namespace std;

int main () {
	ios_base::sync_with_stdio(false),cin.tie(0);
	int n, k;
	cin >> n >> k;

	int ats = (n - 1) / k * 2;

	if ((n - 1) % k >= 1)
		ats++;

	if ((n - 1) % k >= 2)
		ats++;

	cout << ats << endl;

	queue<int> eil;

	for (int i = 2; i <= k + 1; i++) {
		cout << "1 " << i << "\n";
		eil.push(i);
	}

	int dab = k + 2;

	while (dab <= n) {
		cout << eil.front() << " " << dab << "\n";
		eil.pop();
		eil.push(dab++);
	}

	return 0;
}