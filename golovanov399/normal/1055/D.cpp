#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

#define random_shuffle(...) shuffle(__VA_ARGS__, rng)
#define rand() rng()

using namespace std;

inline int nxt() {
	int x;
	// scanf("%d", &x);
	cin >> x;
	return x;
}

vector<int> zFunction(const string& s) {
	int n = s.length();

	vector<int> z(n);
	int l = 0, r = 0;
	for (int i = 1; i < n; ++i) {
		z[i] = max(min(z[i - l], r - i), 0);

		while (i + z[i] < n && s[i + z[i]] == s[z[i]])
			++z[i];

		if (i + z[i] > r) {
			l = i;
			r = i + z[i];
		}
	}
	
	if (n)
		z[0] = n;

	return z;
}

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	cin.sync_with_stdio(0);

	int n = nxt();
	vector<string> from(n), to(n);
	for (int i = 0; i < n; ++i) {
		cin >> from[i];
	}
	for (int i = 0; i < n; ++i) {
		cin >> to[i];
	}

	vector<int> max_l(n), max_r(n);
	for (int i = 0; i < n; ++i) {
		if (from[i] == to[i]) {
			max_l[i] = max_r[i] = -1;
		} else {
			while (from[i][max_l[i]] == to[i][max_l[i]]) {
				++max_l[i];
			}
			max_r[i] = (int)from[i].size() - 1;
			while (from[i][max_r[i]] == to[i][max_r[i]]) {
				--max_r[i];
			}
			++max_r[i];
		}
	}

	string src, dst;
	for (int i = 0; i < n; ++i) {
		if (max_l[i] == -1) {
			continue;
		}

		if (src.empty()) {
			src = from[i].substr(max_l[i], max_r[i] - max_l[i]);
			dst = to[i].substr(max_l[i], max_r[i] - max_l[i]);
		} else {
			if (
				src != from[i].substr(max_l[i], max_r[i] - max_l[i]) ||
				dst != to[i].substr(max_l[i], max_r[i] - max_l[i])
			) {
				cout << "NO\n";
				return 0;
			}
		}
	}

	vector<int> indices;
	for (int i = 0; i < n; ++i) {
		if (max_l[i] != -1) {
			indices.push_back(i);
		}
	}

	while (true) {
		bool ok = true;
		for (int i : indices) {
			if (max_l[i] == 0) {
				ok = false;
				break;
			}
		}
		if (!ok) {
			break;
		}
		char c = from[indices[0]][max_l[indices[0]] - 1];
		char d = to[indices[0]][max_l[indices[0]] - 1];
		for (int i : indices) {
			if (from[i][max_l[i] - 1] != c || to[i][max_l[i] - 1] != d) {
				ok = false;
				break;
			}
		}
		if (ok) {
			src = c + src;
			dst = d + dst;
			for (int i : indices) {
				--max_l[i];
			}
		} else {
			break;
		}
	}
	while (true) {
		bool ok = true;
		for (int i : indices) {
			if (max_r[i] == (int)from[i].size()) {
				ok = false;
				break;
			}
		}
		if (!ok) {
			break;
		}
		char c = from[indices[0]][max_r[indices[0]]];
		char d = to[indices[0]][max_r[indices[0]]];
		for (int i : indices) {
			if (from[i][max_r[i]] != c || to[i][max_r[i]] != d) {
				ok = false;
				break;
			}
		}
		if (ok) {
			src = src + c;
			dst = dst + d;
			for (int i : indices) {
				++max_r[i];
			}
		} else {
			break;
		}
	}

	string zlp = src;
	vector<int> start(n);
	for (int i = 0; i < n; ++i) {
		start[i] = (int)zlp.size() + 1;
		if (i == 0) {
			zlp += "#";
		} else {
			zlp += "$";
		}
		zlp += from[i];
	}
	auto z = zFunction(zlp);
	int idx = 0;
	for (int i = (int)src.size(); i < (int)zlp.size(); ++i) {
		if (z[i] == (int)src.size()) {
			while (idx < n - 1 && start[idx + 1] <= i) {
				++idx;
			}

			if (max_l[idx] > -1 && i - start[idx] >= max_l[idx]) {
				continue;
			}

			cout << "NO\n";
			return 0;
		}
	}

	cout << "YES\n" << src << "\n" << dst << "\n";

	return 0;
}