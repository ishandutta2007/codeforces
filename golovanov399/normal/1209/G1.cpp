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

const int N = 222222;
vector<int> guys[N];

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	int n = nxt(), q = nxt();
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		guys[nxt()].push_back(i);
	}

	assert(q == 0);
	vector<array<int, 3>> ar;
	for (int i = 0; i < N; ++i) {
		if (guys[i].empty()) {
			continue;
		}
		ar.push_back({{guys[i][0], guys[i].back(), (int)guys[i].size()}});
	}
	sort(all(ar));
	int r = -1;
	int mx = 0;
	int ans = n;
	for (const auto& [cl, cr, cnt] : ar) {
		if (cl > r) {
			ans -= mx;
			mx = 0;
		}
		mx = max(mx, cnt);
		r = max(r, cr);
	}
	ans -= mx;
	cout << ans << "\n";

	return 0;
}