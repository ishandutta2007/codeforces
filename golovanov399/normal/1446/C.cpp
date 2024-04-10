#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

#define random_shuffle(...) shuffle(__VA_ARGS__, rng)
#define rand() rng()

#ifdef OLBOEB
	#define return std::cerr << __FUNCTION__ << "\n"; return
#endif  // OLBOEB

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

const int L = 32;

int h(int x) {
	return x ? 32 - __builtin_clz(x) : 0;
}

int f(const vector<int>& a) {
	array<vector<int>, L> guys;
	for (int x : a) {
		guys[h(x)].push_back(x);
	}
	int guarantee = 0;
	int ans = 0;
	for (int i = 0, j = 0; i < L; ++i) {
		if (guys[i].empty()) {
			continue;
		}

		if (i) {
			vector<int> tmp = guys[i];
			for (int& x : tmp) {
				x ^= (1 << (i - 1));
			}
			ans = max(ans, f(tmp) - guarantee - 1 + j);
		}

		guarantee += 1;
		j = 1;
	}
	return guarantee + ans;
}

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	int n = nxt();
	vector<int> a(n);
	generate(all(a), nxt);

	cout << n - f(a) << "\n";

	return 0;
}