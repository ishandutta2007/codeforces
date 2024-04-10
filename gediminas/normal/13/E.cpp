#include <bits/stdc++.h>

using namespace std;
/*input
8 5
1 1 1 1 1 2 8 2
1 1
0 1 3
1 1
0 3 4
1 2


8 7
8 5
7 3
*/

const int konstas = sqrt(100000);

int group(int x) {
	return x / konstas;
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n, m;
	cin >> n >> m;

	int power[n] = {};
	int next[n] = {};
	int cnt[n] = {};

	for (int i = 0; i < n; ++i) {
		cin >> power[i];
	}

	for (int i = n - 1; i >= 0; --i) {
		int j = i + power[i];

		if (j < n and group(i) == group(j)) {
			cnt[i] = cnt[j] + 1;
			next[i] = next[j];
		}
		else {
			cnt[i] = 0;
			next[i] = i;
		}
	}

	for (int i = 0; i < m; ++i) {
		int t;
		cin >> t;

		if (t == 0) {
			int x, y;
			cin >> x >> y;
			x--;
			power[x] = y;
			int g = group(x);

			while (x >= 0 and group(x) == g) {
				int j = x + power[x];

				if (j < n and group(x) == group(j)) {
					cnt[x] = cnt[j] + 1;
					next[x] = next[j];
				}
				else {
					cnt[x] = 0;
					next[x] = x;
				}

				x--;
			}
		}
		else {
			int p;
			cin >> p;
			p--;
			int ans = 0;
			int pp = p;

			while (p < n) {
				ans += cnt[p];
				p = next[p];

				if (p < n) {
					pp = p;
					p = p + power[p];
					ans++;
				}
			}

			cout << pp + 1 << " " << ans << "\n";
		}
	}
}