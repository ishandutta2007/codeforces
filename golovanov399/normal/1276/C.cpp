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

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	int n = nxt();
	map<int, int> M;
	for (int i = 0; i < n; ++i) {
		M[nxt()] += 1;
	}
	map<int, int> by_cnt;
	for (auto it : M) {
		by_cnt[it.second] += 1;
	}
	auto it = by_cnt.begin();
	int cursum = 0;
	int cur_cnt = M.size();
	pair<int, int> opt = {0, 0};
	for (int a = 1; a * a <= n; ++a) {
		cursum += cur_cnt;
		if (it != by_cnt.end() && it->first == a) {
			cur_cnt -= it->second;
			++it;
		}
		if (cursum >= a * a && opt.first < cursum - cursum % a) {
			opt = {cursum - cursum % a, a};
		}
	}
	int sum = opt.first;
	int a = opt.second;
	vector<vector<int>> ans(a);
	vector<pair<int, int>> cs;
	for (auto [x, c] : M) {
		cs.push_back({c, x});
	}
	sort(all(cs));
	reverse(all(cs));
	int rem = sum;
	int p = 0;
	for (auto [c, x] : cs) {
		for (int i = 0; i < c && i < a && rem > 0; ++i, --rem, p = (p + 1) % a) {
			ans[p].push_back(x);
		}
	}
	for (int i = 0; i < a; ++i) {
		rotate(ans[a - 1 - i].begin(), ans[a - 1 - i].begin() + i, ans[a - 1 - i].end());
	}
	printf("%d\n%d %d\n", sum, a, sum / a);
	for (const auto& v : ans) {
		for (int x : v) {
			printf("%d ", x);
		}
		printf("\n");
	}

	return 0;
}