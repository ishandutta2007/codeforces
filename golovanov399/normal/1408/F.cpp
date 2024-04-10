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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

vector<pair<int, int>> ans;

void equalize_power_of_2(const vector<int>& p) {
	const int n = p.size();
	assert(!(n & (n - 1)));
	if (n == 1) {
		return;
	}
	for (int len = 1; len < n; len *= 2) {
		for (int start = 0; start < n; start += 2 * len) {
			for (int i = 0; i < len; ++i) {
				ans.push_back({p[start + i], p[start + len + i]});
			}
		}
	}
}

void solve(int n) {
	ans.clear();
	vector<int> bits;
	for (int i = 0; i < 30; ++i) {
		if (n & (1 << i)) {
			bits.push_back(1 << i);
		}
	}

	vector<vector<int>> batches(bits.size());
	for (int s = 1, i = 0; i < (int)bits.size(); ++i) {
		for (int j = 0; j < bits[i]; ++j) {
			batches[i].push_back(s++);
		}
	}
	reverse(all(batches));
	for (auto& batch : batches) {
		equalize_power_of_2(batch);
	}
	while ((int)batches.size() > 2) {
		while (batches.back().size() < batches.end()[-2].size()) {
			assert(!batches[0].empty());
			batches.back().push_back(batches[0].back());
			batches[0].pop_back();
		}
		equalize_power_of_2(batches.back());
		for (int i = 0; i < (int)batches.back().size(); ++i) {
			ans.push_back({batches.back()[i], batches.end()[-2][i]});
		}
		batches.end()[-2].insert(batches.end()[-2].end(), all(batches.back()));
		batches.pop_back();
	}

	// assert((int)ans.size() <= 500'000);
	printf("%d\n", (int)ans.size());
	for (auto [x, y] : ans) {
		printf("%d %d\n", x, y);
	}
}

int main() {
	int n = nxt();
	solve(n);

	return 0;
}