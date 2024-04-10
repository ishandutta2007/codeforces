/*input
4 6
1 2 2
1 3 3
1 4 8
2 3 4
2 4 5
3 4 3
0
1 3
2 3 4
0
*/
#include <bits/stdc++.h>

using namespace std;

int main () {
	int n, m;
	cin >> n >> m;
	vector<pair<int, int> >gra[n];

	for (int i = 0; i < m; i++) {
		int a, b, t;
		cin >> a >> b >> t;
		a--, b--;
		gra[a].push_back(make_pair(b, t));
		gra[b].push_back(make_pair(a, t));
	}

	set<int> negal[n];

	for (int i = 0; i < n; i++) {
		int k;
		cin >> k;

		for (int j = 0; j < k; j++) {
			int a;
			cin >> a;
			negal[i].insert(a);
		}
	}

	priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> eil;
	eil.push(make_pair(0, 0));

	bool apl[n] = {};

	while (!eil.empty()) {
		int d = eil.top().second;
		int ats = eil.top().first;
		eil.pop();
		//cout << d << endl;

		if (apl[d])
			continue;

		apl[d] = true;

		if (d == n - 1) {
			cout << ats << endl;
			return 0;
		}

		while (negal[d].count(ats))
			ats++;

		for (auto && x : gra[d]) {
			if (!apl[x.first])
				eil.push(make_pair(ats + x.second, x.first));
		}
	}

	cout << -1;

	return 0;
}