/*input
5 4
3 1
2 1
2 3
4 5
*/
#include <bits/stdc++.h>

using namespace std;
const int nmax = 100005;

int main () {
	ios_base::sync_with_stdio(false), cin.tie(0);

	int n, m;
	cin >> n >> m;

	set<int> gra[n];
	vector<int> graa[n];
	int ind[n];

	for (int i = 0; i < m; i++) {
		int v, u;
		cin >> u >> v;
		v--, u--;
		gra[u].insert(v);
		graa[v].push_back(u);
	}

	priority_queue<int> a;

	for (int i = 0; i < n; i++) {
		if (gra[i].size() == 0)
			a.push(i);
	}

	for (int i = n; i >= 1; i--) {
		int d = a.top();
		a.pop();

		for (auto && x : graa[d]) {
			gra[x].erase(d);

			if (gra[x].size() == 0)
				a.push(x);
		}

		ind[d] = i;
	}

	for (int i = 0; i < n; i++)
		cout << ind[i] << " ";

	return 0;
}