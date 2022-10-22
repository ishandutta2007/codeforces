#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n, a, b;
	cin >> n;
	int reductions;
	set<int> node[n];
	set<int> currleaf;
	set<int> nextleaf;
	for (int i = 0; i < n-1; i++) {
		cin >> a >> b;
		node[a-1].insert(b-1);
		node[b-1].insert(a-1);
	}
	for (int i = 0; i < n; i++) {
		if (node[i].size() == 1) 
			currleaf.insert(i);
	}
	// reduce
	int special = -1;
	int first;
	for (reductions = 0; currleaf.size() > 1; reductions++) {
		for (auto cleaf = currleaf.begin(); cleaf != currleaf.end(); ) {
			if (node[*cleaf].size() != 1) {
				if (special != -1) {
					cout << -1 << endl;
					return 0;
				}
				else {
					special = *cleaf;
					cleaf = currleaf.erase(cleaf);
					first = reductions;
				}
			}
			else {
				cleaf++;
			}
		}
		for (auto &cleaf : currleaf) {
			int tleaf = *node[cleaf].begin();
			if (currleaf.count(tleaf) == 1) {
				if (special != -1)
					cout << -1 << endl;
				else 
					cout << 2 * reductions + 1 << endl;
				return 0;
			}
			else {
				nextleaf.insert(tleaf);
				node[tleaf].erase(cleaf);
			}
		}
		currleaf = nextleaf;
		nextleaf.clear();
	}
	int ans;
	if (special == -1)
		ans = reductions;
	else if ((*currleaf.begin()) == special)
		ans = first + reductions;
	else
		ans = -1;
	while (ans % 2 == 0)
		ans /= 2;
	cout << ans << endl;

	return 0;
}