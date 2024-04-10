/*input
3
aa
aa
ab
*/
#include <bits/stdc++.h>

using namespace std;

int main () {
	int n;
	cin >> n;
	vector<pair<deque<char>, int>>mas[n];

	deque<char> pav;

	for (int i = 0; i < n; i++) {
		string b;
		cin >> b;
		deque<char> a(b.begin(), b.end());

		for (int j = 0; j < a.size(); j++) {
			mas[i].push_back(make_pair(a, j));
			a.push_back(a[0]);
			a.pop_front();
		}

		sort(mas[i].begin(), mas[i].end());

		if (pav.size() == 0)
			pav = mas[i][0].first;
		else {
			if (pav != mas[i][0].first) {
				cout << -1;
				return 0;
			}
		}
	}

	int ats = 5000;

	for (int i = 0; i < pav.size(); i++) {
		int te = 0;

		for (int j = 0; j < n; j++)
			te += mas[j][i].second;

		ats = min(ats, te);
	}

	cout << ats;



	return 0;
}