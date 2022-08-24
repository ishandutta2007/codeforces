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
	int n = nxt(), k = nxt();
	vector<int> a(n);
	generate(all(a), nxt);
	vector<int> b(k);
	generate(all(b), nxt);
	map<int, int> M;
	for (int i = 0; i < n; ++i) {
		M[a[i]] = i;
	}
	map<int, char> used;
	for (int i = 0; i < n; ++i) {
		used[i] = 0;
	}
	for (int& x : b) {
		x = M[x];
		used[x] = 1;
	}
	long long ans = 1;
	for (int x : b) {
		auto it = used.find(x);
		bool right_good = next(it) != used.end() && !next(it)->second;
		bool left_good = it != used.begin() && !prev(it)->second;
		if (!left_good && !right_good) {
			cout << "0\n";
			return;
		}
		if (left_good && right_good) {
			ans = ans * 2 % 998'244'353;
		}
		used.erase(it);
	}
	cout << ans << "\n";
}

int main() {
	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}