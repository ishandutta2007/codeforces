#include <bits/stdc++.h>

using namespace std;

int main () {
	ios_base::sync_with_stdio(false), cin.tie(0);
	int n;
	cin >> n;
	vector<pair<int, int>> pri;
	vector<string> t(n);

	for (int i = 0; i < n; i++) {
		int k;
		cin >> t[i] >> k;
		pair<int, int> n;
		n.second = i;

		for (int j = 0; j < k; j++) {
			cin >> n.first;
			pri.push_back(n);
		}
	}

	sort(pri.begin(), pri.end());

	int dab = 1;

	for (pair<int, int> &it : pri) {
		while (dab < it.first) {
			cout << "a";
			dab++;
		}

		for (int i = max(0, dab - it.first); i < t[it.second].size(); i++)
			cout << t[it.second][i];

		dab = max(dab, int(it.first + t[it.second].size()));
	}

	return 0;
}