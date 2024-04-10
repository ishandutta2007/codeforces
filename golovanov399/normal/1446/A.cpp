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

inline long long nxt() {
	long long x;
	// scanf("%d", &x);
	cin >> x;
	return x;
}

void solve() {
	int n = nxt();
	long long w = nxt();
	vector<pair<int, int>> a(n);
	for (int i = 0; i < n; ++i) {
		a[i] = {nxt(), i};
	}
	{
		vector<pair<int, int>> ar;
		for (auto x : a) {
			if (x.first <= w) {
				ar.push_back(x);
			}
		}
		a.swap(ar);
		n = a.size();
	}
	long long sum = 0;
	for (auto p : a) {
		sum += p.first;
	}
	if (sum * 2 < w) {
		cout << "-1\n";
		return;
	}
	sort(all(a));
	reverse(all(a));
	vector<int> ans;
	long long cur = 0;
	for (int i = 0; i < n; ++i) {
		cur += a[i].first;
		ans.push_back(a[i].second);
		assert(cur <= w);
		if (cur * 2 >= w) {
			break;
		}
	}
	assert(cur * 2 >= w);
	cout << ans.size() << "\n";
	for (int i : ans) {
		cout << i + 1 << " ";
	}
	cout << "\n";
}

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}