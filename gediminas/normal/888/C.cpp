/*input
abcde

*/
#include <bits/stdc++.h>

using namespace std;

int main () {
	vector<int> raid['z' - 'a' + 1];

	for (auto && x : raid)
		x.push_back(-1);

	string a;
	cin >> a;

	for (int i = 0; i < a.size(); i++)
		raid[a[i] - 'a'].push_back(i);

	for (auto && x : raid)
		x.push_back(a.size());

	int ats = a.size();

	for (int i = 0; i <= 'z' - 'a'; i++) {
		int atst = 0;

		for (int j = 1; j < raid[i].size(); j++)
			atst = max(atst, raid[i][j] - raid[i][j - 1]);

		ats = min(ats, atst);
	}

	cout << ats;

	return 0;
}