/*input
4 6
1 3
2 3
4 6
5 6
*/
#include <bits/stdc++.h>

using namespace std;

int main () {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n, m;
	cin >> n >> m;
	int kie[m + 1] = {};

	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		kie[x - 1]++;
		kie[y]--;
	}

	for (int i = 1; i < m; i++) {
		kie[i] += kie[i - 1];
	}

	int did[m] = {};
	{
		int last[m + 1];
		int l = 0;

		for (int i = 0; i < m; i++) {
			int lo = 1, hi = l;

			while (lo <= hi) {
				int mid = (lo + hi) / 2;

				if (kie[last[mid]] <= kie[i])
					lo = mid + 1;
				else
					hi = mid - 1;
			}

			int nl = lo;
			last[nl] = i;

			if (nl > l)
				l = nl;

			did[i] = nl;
		}
	}

	int maz[m] = {};
	{
		int last[m + 1];
		int l = 0;

		for (int i = m - 1; i >= 0; i--) {
			int lo = 1, hi = l;

			while (lo <= hi) {
				int mid = (lo + hi) / 2;

				if (kie[last[mid]] <= kie[i])
					lo = mid + 1;
				else
					hi = mid - 1;
			}

			int nl = lo;
			last[nl] = i;

			if (nl > l)
				l = nl;

			maz[i] = nl;
		}
	}

	int ats = 0;

	for (int i = 0; i < m; i++) {
		ats = max(ats, did[i] + maz[i] - 1);
	}

	cout << ats << endl;

	return 0;
}