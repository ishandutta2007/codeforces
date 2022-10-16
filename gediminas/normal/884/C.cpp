/*input

5
1 5 4 3 2
*/
#include <bits/stdc++.h>

using namespace std;

int main () {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;

	int p[n];

	for (int i = 0; i < n; i++) {
		cin >> p[i];
		p[i]--;
	}

	bool apl[n] = {};
	vector<long long> cikl(n);
	long long ats = 0;

	for (int i = 0; i < n; i++) {
		if (!apl[i]) {
			long long s = 1;
			apl[i] = true;
			int j = p[i];

			while (j != i) {
				s++;
				apl[j] = true;
				j = p[j];
			}

			cikl.push_back(s);
			ats += s * s;
		}
	}

	sort(cikl.begin(), cikl.end());

	if (cikl.size() > 1) {
		ats -= cikl.back() * cikl.back();
		ats -= cikl[cikl.size() - 2] * cikl[cikl.size() - 2];
		ats += (cikl[cikl.size() - 2] + cikl.back()) * (cikl[cikl.size() - 2] + cikl.back());
	}

	cout << ats;

	return 0;
}