#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);

	int n;
	vector<int> v;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int j;
		cin >> j;
		v.push_back(j);
	}

	sort(v.begin(), v.end());

	int numNeeded = 1;
	if (v.at(1) == v.at(2)) numNeeded++;
	if (v.at(0) == v.at(2)) numNeeded++;

	long long numHad = count(v.begin(), v.end(), v.at(2));

	if (numNeeded == 1) {
		cout << numHad << endl;
	} else if (numNeeded == 2) {
		cout << numHad * (numHad - 1) / 2 << endl;
	} else {
		cout << numHad * (numHad - 1) * (numHad - 2) / 6 << endl;
	}


	return 0;

}