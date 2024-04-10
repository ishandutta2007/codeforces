/*input
4 3
1 2
1 1
3 1 3 2
2 1 1

*/
#include <bits/stdc++.h>

using namespace std;

int main () {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n, m;
	cin >> n >> m;
	bool reikia[m] = {};
	bool negal[m] = {};
	vector<int> kartu[m];
	bool ar = true;
	vector<int> old;

	for (int i = 0; i < n and ar; i++) {
		int s;
		cin >> s;
		vector<int> dab(s);

		for (int i = 0; i < s; i++) {
			cin >> dab[i];
			dab[i]--;
		}

		if (old.size() > dab.size()) {
			bool lyg = true;

			for (int i = 0; i < s; i++)
				lyg &= old[i] == dab[i];

			if (lyg) {
				ar = false;
				break;
			}
		}

		for (int i = 0; i < min(old.size(), dab.size()); i++) {
			if (old[i] == dab[i])
				continue;
			else if (old[i] < dab[i]) {
				kartu[dab[i]].push_back(old[i]);
				break;
			}
			else {
				negal[dab[i]] = true;
				reikia[old[i]] = true;
				break;
			}
		}

		old = dab;
	}

	bool apl[m] = {};

	for (int i = 0; i < m; i++) {
		if (apl[i] or !reikia[i])
			continue;

		apl[i] = true;
		queue<int> eil;
		eil.push(i);

		while (!eil.empty()) {
			for (auto && x : kartu[eil.front()]) {
				if (!apl[x]) {
					apl[x] = true;
					eil.push(x);
					reikia[x] = true;
				}
			}

			eil.pop();
		}
	}

	for (int i = 0; i < m; i++) {
		if (negal[i] and reikia[i])
			ar = false;
	}

	if (!ar) {
		cout << "No";
		return 0;
	}

	cout << "Yes\n";

	int k = 0;

	for (int i = 0; i < m; i++)
		k += reikia[i];

	cout << k << "\n";

	for (int i = 0; i < m; i++) {
		if (reikia[i])
			cout << i + 1 << " ";
	}

	return 0;
}