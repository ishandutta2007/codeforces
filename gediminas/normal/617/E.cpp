#include <bits/stdc++.h>

using namespace std;
/*input
6 2 3
1 2 1 1 0 3
1 6
3 5

*/
/*input
5 3 1
1 1 1 1 1
1 5
2 4
1 3

*/

const int konstas = sqrt(100000);

int group(int x) {
	return x / konstas;
}
	int kiek[2000010];

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n, m, k;
	cin >> n >> m >> k;

	int a[n + 1] = {};

	for (int i = 0; i < n; ++i) {
		cin >> a[i + 1];
		a[i + 1] ^= a[i];
	}

	vector<pair<pair<int, int>, int>> vv;

	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		vv.push_back({{a - 1, b + 1}, i});
	}

	sort(vv.begin(), vv.end(), [](const auto & i, const auto & j) -> bool {
		if (group(i.first.first) != group(j.first.first))
			return group(i.first.first) < group(j.first.first);
		return i.first.second < j.first.second;
	});

	int st = 0, en = 1;
	long long cnt = 0;

	kiek[0] = 1;
	long long ans[m] = {};

	#define add(b) { \
		if (k == 0) { \
			cnt -= kiek[b] * 1ll * (kiek[b] - 1) / 2; \
			kiek[b]++; \
			cnt += kiek[b] * 1ll * (kiek[b] - 1) / 2; \
		} \
		else { \
			kiek[b]++; \ 
			cnt += kiek[b ^ k]; \
		} \
	}
	#define rem(b) { \
		if (k == 0) { \
			cnt -= kiek[b] * 1ll * (kiek[b] - 1) / 2; \
			kiek[b]--; \
			cnt += kiek[b] * 1ll * (kiek[b] - 1) / 2; \
		} \
		else { \
			kiek[b]--; \ 
			cnt -= kiek[b ^ k]; \
		} \
	}

	for (int i = 0; i < m; ++i) {
		int fr = vv[i].first.first;
		int to = vv[i].first.second;

		while (en < to) {
			int b = a[en++];
			add(b);
		}

		while (fr < st) {
			int b = a[--st];
			add(b);
		}

		while (st < fr) {
			int b = a[st++];
			rem(b);
		}

		while (to < en) {
			int b = a[--en];
			rem(b);
		}

		ans[vv[i].second] = cnt;
	}

	for (int i = 0; i < m; ++i) {
		cout << ans[i] << "\n";
	}
}