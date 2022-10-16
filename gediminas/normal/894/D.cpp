#include <bits/stdc++.h>

using namespace std;
/*input
2 2
5
1 8
2 4
*/
/*input
6 4
2
1
1
3
2
2 4
1 3
3 2
1 7
*/
const int maxn = 1000010;
vector<int> a[maxn];
vector<long long> b[maxn];
int l[maxn];
int n, m;

bool dfs(int v) {
	if (v >= n) {
		return false;
	}

	a[v].push_back(0);

	if (dfs(2 * v + 1)) {
		for (auto &&i : a[2 * v + 1]) {
			a[v].push_back(i + l[2 * v]);
		}
	}

	if (dfs(2 * v + 2)) {
		for (auto &&i : a[2 * v + 2]) {
			a[v].push_back(i + l[2 * v + 1]);
		}
	}

	sort(a[v].begin(), a[v].end());
	b[v].resize(a[v].size());

	for (int i = 0; i < (int)a[v].size(); ++i) {
		b[v][i] = a[v][i] + (i > 0 ? b[v][i - 1] : 0ll);
	}

	return true;
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n >> m;

	for (int i = 0; i < n - 1; ++i) {
		cin >> l[i];
	}

	dfs(0);

	auto calc = [&](int i, long long u) -> long long {
		if (u < 0) {
			return 0;
		}

		auto it = upper_bound(a[i].begin(), a[i].end(), u);

		int j = it - a[i].begin() - 1;

		return (j + 1) * u - b[i][j];
	};

	for (int i = 0; i < m; ++i) {
		long long o, h;
		cin >> o >> h;
		o--;
		long long ans = calc(o, h);
		long long hh = h;

		while (o > 0) {
			int p = (o - 1) / 2;
			hh -= l[o - 1];

			if (hh <= 0) {
				break;
			}

			ans += hh;

			if (o == 2 * p + 1) {
				if (2 * p + 2 < n) {
					ans += calc(2 * p + 2, hh - l[2 * p + 1]);
				}
			}
			else {
				if (2 * p + 1 < n) {
					ans += calc(2 * p + 1, hh - l[2 * p]);
				}
			}

			o = p;
		}

		cout << ans << "\n";
	}
}