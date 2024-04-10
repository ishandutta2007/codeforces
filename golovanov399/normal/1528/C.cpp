#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

const int N = 333'333;

struct Fenwick {
	int n;
	vector<int> a;

	Fenwick(int _n): n(_n), a(_n) {}

	void add(int pos, int x) {
		while (pos < n) {
			a[pos] += x;
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

	int get(int l, int r) {
		return get(r - 1) - get(l - 1);
	}
};

vector<int> sons[N];
vector<int> a[N];
int tin[N];
int tout[N];
int timer;

void dfs(int v) {
	tin[v] = timer++;
	for (int x : a[v]) {
		dfs(x);
	}
	tout[v] = timer;
}

void solve() {
	int n = nxt();
	for (int i = 0; i < n; ++i) {
		sons[i].clear();
		a[i].clear();
	}
	for (int i = 0; i < n - 1; ++i) {
		sons[nxt() - 1].push_back(i + 1);
	}
	for (int i = 0; i < n - 1; ++i) {
		a[nxt() - 1].push_back(i + 1);
	}
	timer = 0;
	dfs(0);

	Fenwick f1(n), f2(n);
	int ans = 0;
	function<void(int, int)> rec = [&](int v, int cur) {
		int old = -1;
		bool need = false;
		if (f1.get(tin[v], tout[v]) == 0) {
			need = true;
			if (int val = f2.get(tin[v]); val == 0) {
				++cur;
			} else {
				old = val - 1;
				f2.add(tin[old], -old - 1);
				f2.add(tout[old], old + 1);
			}
			f2.add(tin[v], v + 1);
			f2.add(tout[v], -v - 1);
		}
		ans = max(ans, cur);
		f1.add(tin[v], 1);
		for (int x : sons[v]) {
			rec(x, cur);
		}
		f1.add(tin[v], -1);
		if (old > -1) {
			f2.add(tin[old], old + 1);
			f2.add(tout[old], -old - 1);
		}
		if (need) {
			f2.add(tin[v], -v - 1);
			f2.add(tout[v], v + 1);
		}
	};
	rec(0, 0);
	cout << ans << "\n";
}

int main() {
	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}