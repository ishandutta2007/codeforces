/*input
5
10 40 20 50 30

*/
#include <bits/stdc++.h>

using namespace std;

int main () {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	set<pair<long long, int>>a;
	long long mas[n];

	for (int i = 0; i < n; i++) {
		cin >> mas[i];
		a.emplace(mas[i], i);
	}

	while (a.size() > 1) {
		pair<long long, int> x = *a.begin();
		pair<long long, int> y = *++a.begin();

		if (x.first == y.first) {
			mas[x.second] = -1;
			mas[y.second] *= 2;
			a.erase(a.begin());
			a.erase(a.begin());
			a.emplace(mas[y.second], y.second);
		}
		else {
			a.erase(a.begin());
		}
	}

	vector<long long> ats;

	for (int i = 0; i < n; i++) {
		if (mas[i] != -1)
			ats.push_back(mas[i]);
	}

	cout << ats.size() << endl;
	for(auto&& x : ats) {
		cout << x << " ";
	}


	return 0;
}