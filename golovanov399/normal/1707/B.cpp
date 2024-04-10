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

const int N = 505'505;
int cnt[N];

void add(int pos, vector<int>& vals, int c = 1) {
	if (!cnt[pos]) {
		vals.push_back(pos);
	}
	cnt[pos] += c;
}

void solve() {
	int n = nxt();
	vector<int> ids;
	for (int i = 0; i < n; ++i) {
		add(nxt(), ids);
	}
	vector<pair<int, int>> cvs;
	for (int it = 0; it < n - 1; ++it) {
		sort(all(ids));
		for (int i : ids) {
			cvs.push_back({cnt[i], i});
			cnt[i] = 0;
		}

		ids = {};
		int last = -1;
		for (auto [c, v] : cvs) {
			if (last > -1) {
				add(v - last, ids);
			}
			if (c > 1) {
				add(0, ids, c - 1);
			}
			last = v;
		}

		cvs = {};
	}
	cout << ids[0] << "\n";
	cnt[ids[0]] = 0;
}

int main() {
	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}