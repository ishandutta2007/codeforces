#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

using namespace std;

inline int nxt() {
	int x;
	// scanf("%d", &x);
	cin >> x;
	return x;
}

// #define TEST

#ifdef TEST
vector<int> g;
#endif

int ask(const vector<int>& a, const vector<int>& b) {
#ifndef TEST
	cout << "? " << a.size() << " " << b.size() << "\n";
	for (int x : a) {
		cout << x + 1 << " ";
	}
	cout << "\n";
	for (int x : b) {
		cout << x + 1 << " ";
	}
	cout << endl;
	return nxt();
#else
	int lhs = 0, rhs = 0;
	for (int x : a) {
		lhs += g[x];
	}
	for (int x : b) {
		rhs += g[x];
	}
	if (auto prod = lhs * rhs; prod > (int)g.size()) {
		assert(false);
	} else {
		return prod;
	}
#endif
}

void solve() {
#ifdef TEST
	int n = 2000;
	g.resize(n);
	for (int i = 0; i < n; ++i) {
		g[i] = (rand() % 7 - 3) / 3;
	}
	for (int i = 0; i < 20; ++i) {
		cerr << g[i] << " ";
	}
	cerr << "...\n";
#else
	int n = nxt();
#endif
	vector<int> group = {0};
	int cur = 1;
	int last = ask(group, {cur});
	while (last == 0) {
		group.push_back(cur++);
		last = ask(group, {cur});
	}
	while ((int)group.size() > 1) {
		if (ask(vector<int>{group.begin(), group.begin() + group.size() / 2}, {cur})) {
			group.resize(group.size() / 2);
		} else {
			group.erase(group.begin(), group.begin() + group.size() / 2);
		}
	}
	vector<int> ans;
	for (int i = 0; i < cur; ++i) {
		if (i != group[0]) {
			ans.push_back(i);
		}
	}
	for (int i = cur + 1; i < n; ++i) {
		if (ask(group, {cur, i}) == last) {
			ans.push_back(i);
		}
	}
#ifdef TEST
	int cnt = 0;
	for (int i = 0; i < n; ++i) {
		cnt += !g[i];
	}
	make_unique(ans);
	// cerr << "answer size: " << ans.size() << "\n";
	// cerr << "actual size: " << cnt << "\n";
	assert((int)ans.size() == cnt);
	for (int x : ans) {
		assert(!g[x]);
	}
#else
	cout << "! " << ans.size();
	for (int x : ans) {
		cout << " " << x + 1;
	}
	cout << endl;
#endif
}

int main() {
	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}