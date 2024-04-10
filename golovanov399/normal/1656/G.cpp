#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

void solve() {
	int n = nxt();
	vector<int> a(n);
	for (int& x : a) {
		x = nxt() - 1;
	}
	vector<int> cnt(n);
	for (int x : a) {
		cnt[x] += 1;
	}
	int cnt_odd = count_if(all(cnt), [](int x) { return x % 2; });
	if (cnt_odd > 1) {
		cout << "No\n";
		return;
	}
	

	vector<int> blue(n, -1), red(n, -1);
	for (int i = 0; i < n - 1 - i; ++i) {
		blue[i] = n - 1 - i;
		blue[n - 1 - i] = i;
	}
	int to_skip = -1;
	if (n % 2) {
		int x = 0;
		while (cnt[x] % 2 == 0) {
			++x;
		}
		if (cnt[x] == 1 && a[n / 2] == x) {
			cout << "No\n";
			return;
		}
		for (int i = 0; i < n; ++i) {
			if (a[i] == x && i != n / 2) {
				to_skip = i;
			}
		}
		assert(to_skip > -1);
	}
	vector<int> last(n, -1);
	for (int i = 0; i < n; ++i) {
		if (i == to_skip) {
			continue;
		}
		if (last[a[i]] > -1) {
			red[i] = last[a[i]];
			red[last[a[i]]] = i;
			last[a[i]] = -1;
		} else {
			last[a[i]] = i;
		}
	}
	vector<int> path;
	vector<char> used(n);
	vector<int> ans(n, -1);
	if (n % 2) {
		int i = to_skip;
		ans[n / 2] = i;
		while (true) {
			used[i] = 1;
			path.push_back(i);
			i = blue[i];
			if (i == -1) {
				break;
			}
			used[i] = 1;
			path.push_back(i);
			i = red[i];
		}
	}
	vector<vector<int>> cycles;
	for (int i = 0; i < n; ++i) {
		if (used[i]) {
			continue;
		}
		cycles.push_back({});
		int j = i;
		do {
			used[j] = 1;
			cycles.back().push_back(j);
			j = blue[j];
			used[j] = 1;
			cycles.back().push_back(j);
			j = red[j];
		} while (j != i);
	}
	if (n % 2 == 1) {
		assert(!path.empty());
		cycles.insert(cycles.begin(), path);
	}
	// for (int i = 0; i < n; ++i) {
	// 	cerr << blue[i] << " ";
	// }
	// cerr << "\n";
	// for (int i = 0; i < n; ++i) {
	// 	cerr << red[i] << " ";
	// }
	// cerr << "\n";
	for (int i = 0; i < (int)cycles.size(); ++i) {
		int j;
		for (j = 0; j + 3 < (int)cycles[i].size(); j += 2) {
			ans[cycles[i][j]] = cycles[i][j + 1];
			ans[cycles[i][j + 1]] = cycles[i][j + 2];
		}
		const int ni = (i + 1) % (int)cycles.size();
		if (i + 1 == (int)cycles.size()) {
			ans[cycles[i][j]] = cycles[ni][(int)cycles[ni].size() - 1 - (int)cycles[ni].size() % 2];
			ans[cycles[i][j + 1]] = cycles[ni][((int)cycles[ni].size() - (int)cycles[ni].size() % 2) % (int)cycles[ni].size()];
		} else {
			ans[cycles[i][j]] = cycles[ni][((int)cycles[ni].size() - (int)cycles[ni].size() % 2) % (int)cycles[ni].size()];
			ans[cycles[i][j + 1]] = cycles[ni][(int)cycles[ni].size() - 1 - (int)cycles[ni].size() % 2];
		}
	}
	cout << "Yes\n";
	for (int i = 0; i < n; ++i) {
		cout << ans[i] + 1 << " ";
	}
	cout << "\n";
}

int main() {
	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}