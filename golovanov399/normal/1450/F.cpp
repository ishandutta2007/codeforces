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

int stupid(const vector<int>& a) {
	const int n = a.size();
	vector<int> p(n);
	iota(all(p), 0);
	int ans = 1e9;
	do {
		int cost = 0;
		int last = -1;
		for (int i : p) {
			if (i == p[0]) {
				last = i;
				continue;
			}
			if (a[last] == a[i]) {
				cost = 1e9;
				break;
			}
			if (abs(last - i) > 1) {
				cost += 1;
			}
			last = i;
		}
		ans = min(ans, cost);
	} while (next_permutation(all(p)));
	if (ans > 1e8) {
		ans = -1;
	}
	return ans;
}

int subsolve(const vector<int>& a) {
	const int n = a.size();
	if (n == 1) {
		return 0;
	}
	int segs = 1;
	map<int, int> M;
	M[a[0]] += 1;
	M[a.back()] += 1;
	for (int i = 0; i < n - 1; ++i) {
		if (a[i] == a[i + 1]) {
			M[a[i]] += 2;
			segs += 1;
		}
	}
	pair<int, int> mx = {-1, -1};
	for (auto p : M) {
		mx = max(mx, {p.second, p.first});
	}
	for (int i = 0; i < n - 1/* && mx.first > segs + 1*/; ++i) {
		if (a[i] != a[i + 1] && a[i] != mx.second && a[i + 1] != mx.second && mx.first > segs + 1) {
			segs += 1;
		}
	}
	if (mx.first > segs + 1) {
		return -1;
	} else {
		return segs - 1;
	}
}

void solve() {
	int n = nxt();
	vector<int> a(n);
	generate(all(a), nxt);
	cout << subsolve(a) << "\n";
}

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#if 0
	while (true) {
		int n = 6;
		vector<int> a(n);
		for (int i = 0; i < n; ++i) {
			a[i] = rand() % n;
		}
		int ans = stupid(a);
		int res = subsolve(a);
		if (ans != res) {
			cerr << "\n" << n << "\n";
			for (int x : a) {
				cerr << x << " ";
			}
			cerr << "\n";
			cerr << "ans: " << ans << "\n";
			cerr << "res: " << res << "\n";
			return 1;
		} else {
			cerr << "ok ";
		}
	}
#else
	int t = nxt();
	while (t--) {
		solve();
	}
#endif

	return 0;
}