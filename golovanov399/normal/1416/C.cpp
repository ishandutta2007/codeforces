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

struct Fenwick {
	int n;
	vector<int> a;

	Fenwick(int _n): n(_n), a(_n) {}

	void add(int pos) {
		while (pos < n) {
			a[pos] += 1;
			pos |= pos + 1;
		}
	}

	int get(int pos) {
		int res = 0;
		while (pos >= 0) {
			res += a[pos];
			pos = (pos & (pos + 1)) - 1;
		}
		return res;
	}
};

long long get_inv_cnt(vector<int> a) {
	int n = a.size();
	vector<pair<int, int>> ar(n);
	for (int i = 0; i < n; ++i) {
		ar[i] = {a[i], i};
	}
	sort(all(ar));
	for (int i = 0; i < n; ++i) {
		a[ar[i].second] = i;
	}
	Fenwick f(n);
	long long ans = 0;
	for (int i = n - 1; i >= 0; --i) {
		ans += f.get(a[i]);
		f.add(a[i]);
	}
	return ans;
}

void solve() {
	int n = nxt();
	vector<int> a(n);
	generate(all(a), nxt);
	long long ans = get_inv_cnt(a);
	int x = 0;
	for (int i = (1 << 30); i; i >>= 1) {
		for (auto& x : a) {
			x ^= i;
		}
		if (auto nw = get_inv_cnt(a); nw < ans) {
			ans = nw;
			x ^= i;
		} else {
			for (auto& x : a) {
				x ^= i;
			}
		}
	}
	cout << ans << " " << x << "\n";
}

int main() {
	int t = 1; // nxt();
	while (t--) {
		solve();
	}

	return 0;
}