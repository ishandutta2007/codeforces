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
	if (n == 1) {
		cout << "0\n";
		return 0;
	}
	vector<int> a(n);
	generate(all(a), nxt);
	map<int, int> M;
	for (int x : a) {
		M[x] += 1;
	}
	vector<pair<int, int>> guys;
	for (auto [k, v] : M) {
		guys.push_back({v, k});
	}
	sort(all(guys));
	if ((int)guys.size() == 1) {
		cout << "0\n";
		return 0;
	}
	if (guys.back().first == (guys.end() - 2)->first) {
		cout << n << "\n";
		return 0;
	}

	int x = guys.back().second;

	int ans = 2;
	for (auto p : M) {
		int y = p.first;
		if (y == x) {
			continue;
		}
		vector<int> st = {-1};
		int cur = 0;
		for (int i = 0; i < n; ++i) {
			int z = a[i];
			if (z == x) {
				--cur;
			} else if (z == y) {
				++cur;
			}
			if (cur <= -(int)st.size()) {
				st.push_back(i);
			} else {
				ans = max(ans, i - st[max(0, -cur)]);
			}
		}
	}
	cout << ans << "\n";

	return 0;
}