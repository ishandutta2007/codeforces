/*input
2
1 P
500 P
5
10 R
14 B
16 B
21 R
32 R

*/
#include <bits/stdc++.h>

using namespace std;

int main () {
	//random shit
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	vector<long long> r, b;
	long long lastp = -1000000000000000ll;
	long long ats = 0;

	for (int i = 0; i < n; i++) {
		long long x;
		char t;
		cin >> x >> t;

		if (t == 'G') {
			long long ats1 = 0;

			if (r.size() > 0) {
				long long mi = r.back() - r.front() + min(r.front() - lastp, x - r.back());

				for (int i = 0; i + 1 < r.size(); i++) {
					mi = min(mi, r[i] - lastp + x - r[i + 1]);
				}

				ats1 += mi;
			}

			if (b.size() > 0) {
				long long mi = b.back() - b.front() + min(b.front() - lastp, x - b.back());

				for (int i = 0; i + 1 < b.size(); i++) {
					mi = min(mi, b[i] - lastp + x - b[i + 1]);
				}

				ats1 += mi;
			}


			if (lastp != -1000000000000000ll) {
				ats1 += x - lastp;
				ats1 = min(ats1, 2 * (x - lastp));
			}

			lastp = x;
			r.clear();
			b.clear();

			ats += ats1;
		}
		else if (t == 'R')
			r.push_back(x);
		else if (t == 'B')
			b.push_back(x);
	}

	if (r.size() > 0) {
		if (lastp != -1000000000000000ll)
			ats += r.back() - lastp;
		else
			ats += r.back() - r.front();
	}

	if (b.size() > 0) {
		if (lastp != -1000000000000000ll)
			ats += b.back() - lastp;
		else
			ats += b.back() - b.front();
	}

	cout << ats << endl;

	return 0;
}