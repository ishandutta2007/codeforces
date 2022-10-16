/*input
4 2 5
1 2 3 1
*/
#include <bits/stdc++.h>

using namespace std;

int main () {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	long long n, k, m;
	cin >> n >> k >> m;
	vector<int> a(n);

	for (int i = 0; i < n; i++)
		cin >> a[i];

	vector<pair<int, long long>>b;

	for (int i = 0; i < n; i++) {
		if (b.size() == 0 or a[i] != b.back().first)
			b.push_back(make_pair(a[i], 1));
		else
			b.back().second++;

		if (b.back().second == k)
			b.pop_back();
	}

	long long ats = 0;

	for (auto && x : b)
		ats += x.second;

	if (ats == 0 or m == 1) {
		cout << ats;
		exit(0);
	}

	ats *= m;

	int i = 0, j = b.size() - 1;

	while (i < j) {
		if (b[i].first != b[j].first)
			break;

		ats -= (b[i].second + b[j].second) / k * k * (m - 1);

		b[i].second = (b[i].second + b[j].second) % k;
		j--;

		if (b[i].second == 0)
			i++;
	}

	if (i > j)
		ats = 0;

	if (i == j) {
		if ((b[i].second * m) % k == 0)
			ats = 0;
		else
			ats -= (b[i].second * m) / k * k;
	}

	cout << ats;

	return 0;
}