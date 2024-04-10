#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define itn int
#define make_unique(x) sort((x).begin(), (x).end()); (x).erase(unique((x).begin(), (x).end()), (x).end())

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

bool check(const vector<int>& a, vector<vector<int>> perms) {
	for (int i = 1; i + 1 < (int)a.size(); ++i) {
		int j = 0;
		while (j < (int)perms.size() && (!binary_search(all(perms[j]), a[i]) || binary_search(all(perms[j]), a[i + 1]))) {
			++j;
		}
		if (j == (int)perms.size()) {
			return false;
		}
		int r = i;
		int l = r - (int)perms[j].size();
		if (l < 0) {
			return false;
		}
		vector<int> tmp(a.begin() + l, a.begin() + r);
		sort(all(tmp));
		if (tmp != perms[j]) {
			return false;
		}
		perms.erase(perms.begin() + j);
	}
	vector<int> tmp(a.end() - perms[0].size(), a.end());
	sort(all(tmp));
	return perms[0] == tmp;
}

void solve() {
	int n = nxt();
	vector<vector<int>> perms(n - 1);
	vector<vector<int>> ps_by_guy(n);
	for (int i = 0; i < n - 1; ++i) {
		int k = nxt();
		perms[i].resize(k);
		for (int& x : perms[i]) {
			x = nxt() - 1;
			ps_by_guy[x].push_back(i);
		}
	}
	vector<int> ans;
	set<int> bad_choices;
	while (true) {
		ans.clear();
		bool ok = true;
		vector<char> used(n - 1);
		vector<int> furthest_good(n);
		iota(all(furthest_good), 0);
		int so_far = 0;
		int rem = 0;
		for (int i = 0; i < n; ++i) {
			rem ^= i;
		}
		vector<int> cnt(n);
		for (int i = 0; i < n; ++i) {
			cnt[i] = ps_by_guy[i].size();
		}

		vector<int> tail;
		for (int len = n; len >= 2; --len) {
			int i = 0;
			while (i < n - 1 && (int)perms[i].size() != len) {
				++i;
			}
			if (i == n - 1) {
				break;
			}
			for (int x : perms[i]) {
				if (cnt[x] == 1) {
					rem ^= x;
					tail.push_back(x);
				}
				--cnt[x];
			}
			used[i] = true;
		}

		for (int i = 0; i < n - 1 - (int)tail.size(); ++i) {
			if (so_far <= i) {
				furthest_good.assign(n, 0);
				iota(all(furthest_good), 0);
			}
			int v = 0;
			while (v < n && (cnt[v] != 1 || !binary_search(all(furthest_good), v) || (i == 0 && bad_choices.count(v)))) {
				++v;
			}
			if (v == n) {
				ok = false;
				break;
			}
			if (i == 0) {
				bad_choices.insert(v);
			}
			for (int j : ps_by_guy[v]) {
				if (used[j]) {
					continue;
				}
				used[j] = true;
				int how_far = (int)perms[j].size() + i;
				if (how_far + (int)tail.size() < n && how_far > so_far) {
					so_far = how_far;
					furthest_good = perms[j];
				}
				for (int x : perms[j]) {
					cnt[x] -= 1;
				}
			}
			rem ^= v;
			ans.push_back(v);
		}
		if ((int)tail.size() < n) {
			ans.push_back(rem);
		}
		if (!ok) {
			continue;
		}
		reverse(all(tail));
		ans.insert(ans.end(), all(tail));
		if (!check(ans, perms)) {
			reverse(ans.begin(), ans.end() - tail.size());
		}
		break;
	}
	for (int x : ans) {
		cout << x + 1 << " ";
	}
	cout << "\n";
}

int main() {
	// srand(time(nullptr));
	// vector<int> p(6);
	// iota(all(p), 0);
	// random_shuffle(all(p));
	// cout << "1\n" << p.size() << "\n";
	// vector<vector<int>> ar;
	// for (int i = 1; i < (int)p.size(); ++i) {
	// 	ar.push_back(vector<int>{p.begin() + rand() % i, p.begin() + i + 1});
	// 	sort(all(ar.back()));
	// }
	// random_shuffle(all(ar));
	// for (auto v : ar) {
	// 	cout << v.size();
	// 	for (int x : v) {
	// 		cout << " " << x + 1;
	// 	}
	// 	cout << "\n";
	// }
	// for (int x : p) {
	// 	cerr << x + 1 << " ";
	// }
	// cerr << "-\n";

	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}