/*input
4 5
2 3 1 4 4
*/
#include <bits/stdc++.h>

using namespace std;

int main () {
	int n, m;
	cin >> n >> m;
	int ind[n];
	fill(ind, ind + n, -1);
	int la;
	cin >> la;
	la--;
	set<int>pan;

	for (int i = 1; i <= n; i++)
		pan.insert(i);

	for (int i = 1; i < m; i++) {
		int d;
		cin >> d;
		d--;
		int a = (d - la + n) % n;

		if (a == 0)
			a = n;

		if ((ind[la] == -1 and pan.count(a) > 0) or ind[la] == a) {
			ind[la] = a;
			pan.erase(a);
		}
		else {
			cout << -1;
			return 0;
		}

		la = d;
	}

	for (int i = 0; i < n; i++) {
		if (ind[i] == -1) {
			ind[i] = *pan.begin();
			pan.erase(pan.begin());
		}
	}

	for (int i = 0; i < n; i++)
		cout << ind[i] << " ";


	return 0;
}