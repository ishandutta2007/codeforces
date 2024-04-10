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
set<itn> a[N];

void panic() {
	cout << "No\n";
	exit(0);
}

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	int n = nxt();
	for (int i = 0; i < n - 1; ++i) {
		int u = nxt() - 1, v = nxt() - 1;
		a[u].insert(v);
		a[v].insert(u);
	}

	vector<int> p(n);
	for (int i = 0; i < n; ++i) {
		p[i] = nxt() - 1;
	}

	if (p[0]) {
		panic();
	}

	vector<int> cnt(n);
	for (int i = 0; i < n; ++i) {
		cnt[i] = a[i].size();
	}
	queue<int> q;
	q.push(p[0]);
	for (int i = 1; i < n; ++i) {
		if (q.empty()) {
			panic();
		}
		int v = q.front();
		if (!a[v].count(p[i])) {
			panic();
		}
		--cnt[v];
		if (!cnt[v]) {
			q.pop();
		}

		--cnt[p[i]];
		if (cnt[p[i]]) {
			q.push(p[i]);
		}
	}

	cout << "Yes\n";

	return 0;
}