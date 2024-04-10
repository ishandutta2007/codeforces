/*input
5 2
2 2 4 5 3
*/
#include <bits/stdc++.h>

using namespace std;
bool spalv[1000001];
int main () {
	ios_base::sync_with_stdio(false), cin.tie(0);
	int n, a;
	cin >> n >> a;
	map<int, int> kiek;
	set<int> turi[n + 1];

	for (int i = 1; i <= 1000000; i++) {
		turi[0].insert(i);
		kiek[i] = 0;
		spalv[i] = true;
	}

	for (int i = 0; i < n; i++) {
		int dab;
		cin >> dab;

		if (spalv[dab] or dab == a) {
			int buves = kiek[dab]++;
			turi[buves].erase(dab);
			buves++;
			turi[buves].insert(dab);

			if (dab == a) {
				for (auto && nr : turi[buves - 1])
					spalv[nr] = false;

				turi[buves - 1].clear();
			}
		}
	}

	for (int i = 1; i <= 1000000; i++) {
		if (spalv[i] and i != a) {
			cout << i;
			return 0;
		}
	}

	cout << -1;

	return 0;
}