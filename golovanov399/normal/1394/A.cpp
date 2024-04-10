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

void solve() {
	int n = nxt(), d = nxt(), m = nxt();
	vector<int> smaller, greater;
	for (int i = 0; i < n; ++i) {
		int x = nxt();
		if (x <= m) {
			smaller.push_back(x);
		} else {
			greater.push_back(x);
		}
	}
	sort(all(smaller));
	reverse(all(smaller));
	sort(all(greater));
	reverse(all(greater));
	vector<long long> sm_sum(smaller.size() + 1);
	for (int i = 0; i < (int)smaller.size(); ++i) {
		sm_sum[i + 1] = sm_sum[i] + smaller[i];
	}
	vector<long long> gr_sum(greater.size() + 1);
	for (int i = 0; i < (int)greater.size(); ++i) {
		gr_sum[i + 1] = gr_sum[i] + greater[i];
	}
	long long ans = 0;
	for (int i = 0; i <= (int)greater.size() && (i - 1) * d + i <= n; ++i) {
		ans = max(ans, gr_sum[i] + sm_sum[min((int)smaller.size(), n - ((i - 1) * d + i))]);
	}
	cout << ans << "\n";
}

int main() {
	int t = 1; // nxt();
	while (t--) {
		solve();
	}

	return 0;
}