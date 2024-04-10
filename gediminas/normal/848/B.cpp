/*input

3 2 3
1 1 2
2 1 1
1 1 5
*/
#include <bits/stdc++.h>

using namespace std;

struct danc {
	int p, t, i, g;
	long long v;
	long long v2;
};

int main () {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n, w, h;
	cin >> n >> w >> h;

	map<long long, vector<danc>> sok;

	for (int i = 0; i < n; i++) {
		danc a;
		cin >> a.g >> a.p >> a.t;
		a.g--;
		a.i = i;

		if (a.g == 0)
			a.v = -a.p;
		else
			a.v = a.p;

		if (a.g == 0)
			a.v2 = a.p;
		else
			a.v2 = 300000 - a.p;

		sok[a.p - a.t].push_back(a);
	}

	long long atsx[n];
	long long atsy[n];

	for (auto && x : sok) {
		vector<danc> a = x.second;

		sort(x.second.begin(), x.second.end(), [](const auto & i, const auto & j) -> bool {
			return i.v > j.v;
		});

		sort(a.begin(), a.end(), [](const auto & i, const auto & j) -> bool {
			return i.v2 < j.v2;
		});

		for (int i = 0; i < x.second.size(); i++) {
			//cout << x.second[i].i << endl;

			if (a[i].g == 0) {
				atsx[x.second[i].i] = a[i].p;
				atsy[x.second[i].i] = h;
			}
			else {
				atsx[x.second[i].i] = w;
				atsy[x.second[i].i] = a[i].p;
			}
		}

		//cout << endl;
	}

	for (int i = 0; i < n; i++)
		cout << atsx[i] << " " << atsy[i] << "\n";


	return 0;
}