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

void panic() {
	cout << "-1\n";
	exit(0);
}

const int N = 222222;
vector<int> a[N];
vector<int> ar[N];

char used[N];
void dfs(int v) {
	used[v] = 1;
	for (int x : a[v]) {
		if (used[x] == 2) {
			continue;
		}
		if (used[x] == 1) {
			panic();
		}
		dfs(x);
	}
	used[v] = 2;
}

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	int n = nxt(), m = nxt();
	for (int i = 0; i < m; ++i) {
		int u = nxt() - 1, v = nxt() - 1;
		a[u].push_back(v);
		ar[v].push_back(u);
	}

	for (int i = 0; i < n; ++i) {
		if (!used[i]) {
			dfs(i);
		}
	}

	int ans = 0;
	vector<char> is_smaller(n);
	vector<char> is_greater(n);

	function<void(int)> push_smaller = [&](int v) {
		if (is_smaller[v]) {
			return;
		}
		is_smaller[v] = true;
		for (int x : a[v]) {
			push_smaller(x);
		}
	};
	function<void(int)> push_greater = [&](int v) {
		if (is_greater[v]) {
			return;
		}
		is_greater[v] = true;
		for (int x : ar[v]) {
			push_greater(x);
		}
	};

	string quant = "";
	for (int i = 0; i < n; ++i) {
		if (!is_smaller[i] && !is_greater[i]) {
			++ans;
			quant += "A";
		} else {
			quant += "E";
		}
		push_smaller(i);
		push_greater(i);
	}

	cout << ans << "\n" << quant << "\n";

	return 0;
}