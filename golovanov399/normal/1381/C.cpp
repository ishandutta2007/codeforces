#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

// #define random_shuffle(...) shuffle(__VA_ARGS__, rng)
// #define rand() rng()

#ifdef OLBOEB
	#define return std::cerr << __FUNCTION__ << "\n"; return
#endif  // OLBOEB

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

// #define TEST

pair<int, int> get_bc(const vector<int>& a, const vector<int>& b) {
	map<int, int> M, N;
	for (int x : a) {
		M[x] += 1;
	}
	for (int x : b) {
		N[x] += 1;
	}
	int c = 0;
	for (auto p : M) {
		c += min(p.second, N[p.first]);
	}
	int bb = 0;
	for (int i = 0; i < (int)a.size(); ++i) {
		bb += a[i] == b[i];
	}
	return {bb, c - bb};
}

void solve() {
#ifdef TEST
	int n = 5;
	int bulls = rand() % (n + 1), cows = rand() % (n + 1);
	if (bulls > cows) {
		swap(bulls, cows);
	}
	cows -= bulls;
	vector<int> ar(n);
	for (int i = 0; i < n; ++i) {
		ar[i] = rand() % (n + 1);
	}
	vector<vector<int>> a(n + 1);
	for (int i = 0; i < n; ++i) {
		a[ar[i]].push_back(i);
	}
#else
	int n = nxt();
	int bulls = nxt(), cows = nxt();
	cows -= bulls;
	vector<vector<int>> a(n + 1);
	for (int i = 0; i < n; ++i) {
		a[nxt() - 1].push_back(i);
	}
#endif

	int fake = 0;
	while (!a[fake].empty()) {
		++fake;
	}

	priority_queue<pair<int, int>> S;
	for (int i = 0; i < n + 1; ++i) {
		S.push({(int)a[i].size(), i});
	}
	vector<int> b(n, -1);
	for (int i = 0; i < bulls; ++i) {
		auto [cnt, pos] = S.top();
		S.pop();
		b[a[pos].back()] = pos;
		a[pos].pop_back();
		--cnt;
		S.push({cnt, pos});
	}

	if (bulls == n) {
#ifdef TEST
		if (get_bc(ar, b) != pair{bulls, cows}) {
			cerr << n << " " << bulls << " " << cows + bulls << "\n";
			for (int x : ar) {
				cerr << x + 1 << " ";
			}
			cerr << "\n";
			cerr << "out:";
			for (int x : b) {
				cerr << " " << x + 1;
			}
			cerr << "\n";
			assert(false);
		}
#else
		printf("YES\n");
		for (int x : b) {
			printf("%d ", x + 1);
		}
		printf("\n");
#endif
		return;
	}

	int min_inter = 0;
	for (int i = 0; i < n + 1; ++i) {
		min_inter = max(min_inter, 2 * (int)a[i].size() - (n - bulls));
	}

	if (min_inter + cows > n - bulls) {
#ifndef TEST
		printf("NO\n");
#endif
		return;
	}

	vector<int> positions;
	vector<int> guys;
	for (int i = 0; i < n + 1; ++i) {
		for (int x : a[i]) {
			positions.push_back(x);
			guys.push_back(i);
		}
	}

	// cerr << "\n";
	// for (int x : positions) {
	// 	cerr << x + 1 << " ";
	// }
	// cerr << "\n";
	// for (int x : guys) {
	// 	cerr << x + 1 << " ";
	// }
	// cerr << "\n";
	// cerr << "\n";

	int bitch = (*max_element(all(a), [](const vector<int>& x, const vector<int>& y) {
		return x.size() < y.size();
	}))[0];
	int msz = max_element(all(a), [](const vector<int>& x, const vector<int>& y) {
		return x.size() < y.size();
	})->size();
	int idx = find(all(positions), bitch) - positions.begin();
	// cerr << bitch << " " << msz << " " << idx << " --\n";

	int fake_count = n - bulls - cows;
	for (int i = 0; i < fake_count; ++i) {
		guys[(i + idx) % (int)guys.size()] = fake;
	}
	for (int i = 0; i < (int)guys.size(); ++i) {
		b[positions[i]] = guys[(i + msz) % (int)guys.size()];
	}

#ifdef TEST
	if (get_bc(ar, b) != pair{bulls, cows}) {
		cerr << n << " " << bulls << " " << cows + bulls << "\n";
		for (int x : ar) {
			cerr << x + 1 << " ";
		}
		cerr << "\n";
		cerr << "out:";
		for (int x : b) {
			cerr << " " << x + 1;
		}
		cerr << "\n";
		assert(false);
	}
#else
	printf("YES\n");
	for (int x : b) {
		printf("%d ", x + 1);
	}
	printf("\n");
#endif
}

int main() {
	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}