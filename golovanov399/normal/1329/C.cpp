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

const int N = 1111111;
int a[N * 2];

bool canRemove(int i, int p2) {
	if (i >= p2) {
		return true;
	}
	if (!a[i * 2] && !a[i * 2 + 1]) {
		return false;
	}
	if (a[i * 2] > a[i * 2 + 1]) {
		return canRemove(2 * i, p2);
	} else {
		return canRemove(2 * i + 1, p2);
	}
}

void remove(int i) {
	if (!a[i * 2] && !a[i * 2 + 1]) {
		a[i] = 0;
		return;
	}
	if (a[i * 2] > a[i * 2 + 1]) {
		swap(a[i], a[i * 2]);
		remove(2 * i);
	} else {
		swap(a[i], a[i * 2 + 1]);
		remove(2 * i + 1);
	}
}

void solve() {
	int h = nxt(), g = nxt();
	int n = (1 << h) - 1;

	for (int i = 1; i <= n; ++i) {
		a[i] = nxt();
	}

	vector<int> ans;
	for (int i = 1; i < (1 << g); ++i) {
		while (canRemove(i, 1 << g)) {
			ans.push_back(i);
			remove(i);
		}
	}
	cout << accumulate(a + 1, a + (1 << g), 0ll) << "\n";
	for (int x : ans) {
		cout << x << " ";
	}
	cout << "\n";

	for (int i = 0; i <= n; ++i) {
		a[i] = 0;
	}
}

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}