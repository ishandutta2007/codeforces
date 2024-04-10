/*input
4
3 3 3 3

*/
#include <bits/stdc++.h>

using namespace std;

struct uzkl {
	long long fr, to, pos;
};

int main () {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	long long n;
	cin >> n;
	int mas[n];
	bitset<31> bitmas[n];

	int lastone[n + 1][31] = {};

	for (int i = 0; i < 31; i++)
		lastone[0][i] = -1;

	for (int i = 0; i < n; i++) {
		cin >> mas[i];
		bitmas[i] = bitset<31>(mas[i]);

		// /cout << bitmas[i] << endl;
		//cout << mas[i].to_ullong() << endl;
		for (int j = 0; j < 31; j++) {
			if (bitmas[i][j] == 1)
				lastone[i + 1][j] = i;
			else
				lastone[i + 1][j] = lastone[i][j];
		}
	}

	int nextone[n + 1][31] = {};

	for (int i = 0; i < 31; i++)
		nextone[n][i] = n;

	for (int i = n - 1; i >= 0; i--) {
		for (int j = 0; j < 31; j++) {
			if (bitmas[i][j] == 1)
				nextone[i][j] = i;
			else
				nextone[i][j] = nextone[i + 1][j];
		}
	}

	uzkl quer[n];

	{
		pair<int, int> did[n];

		for (int i = 0; i < n; i++) {
			did[i].first = mas[i];
			did[i].second = i;
		}

		sort(did, did + n, [](const auto & i, const auto & j) -> bool {
			return i > j;
		});

		set<int> a;
		a.insert(-1);
		a.insert(n);

		for (int i = 0; i < n; i++) {
			quer[i].pos = did[i].second;
			set<int>::iterator it = a.insert(did[i].second).first;
			set<int>::iterator it2 = it;
			it--;
			it2++;
			quer[i].fr = *it;
			quer[i].to = *it2;
		}
	}

	long long ats = 0;

	for (int di = 0; di < n; di++) {
		long long in = quer[di].pos;
		long long from = quer[di].fr;
		from++;
		long long to = quer[di].to;

		long long mi = from - 1;

		for (int j = 0; j < 31; j++) {
			if (bitmas[in][j] == 0)
				mi = max(mi, (long long)lastone[in][j]);
		}

		long long ma = to;

		for (int j = 0; j < 31; j++) {
			if (bitmas[in][j] == 0)
				ma = min(ma, (long long)nextone[in + 1][j]);
		}

		//cout << mas[in] << " " << in << " " << from << " " << to << " " << mi << " " << ma << endl;

		ats += max(0ll, (to - in) * (mi - from + 1));
		//cout << ats << endl;
		ats += max(0ll, (to - ma) * (in - from + 1));
		//cout << ats << endl;
		ats -= max(0ll, (to - ma) * (mi - from + 1));
		//cout << ats << endl;
	}

	cout << ats;

	return 0;
}