#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()

using namespace std;

inline long long nxt() {
	long long x;
	cin >> x;
	return x;
}

struct Node {
	int cnt;
	long long val;
};

struct Fenwick {
	int n;
	vector<Node> a;

	Fenwick(int _n): n(_n), a(_n) {}

	void add(int pos, int cnt, int val) {
		while (pos < n) {
			a[pos].cnt += cnt;
			a[pos].val += val;
			pos |= pos + 1;
		}
	}

	Node get(int pos) {
		Node res = {0, 0};
		while (pos >= 0) {
			res.cnt += a[pos].cnt;
			res.val += a[pos].val;
			pos = (pos & (pos + 1)) - 1;
		}
		return res;
	}
};

int main() {
	int n = nxt();
	vector<pair<int, int>> a(n);
	for (int i = 0; i < n; ++i) {
		a[i].first = nxt();
	}
	for (int i = 0; i < n; ++i) {
		a[i].second = -nxt();
	}
	sort(all(a));
	vector<int> ys;
	for (const auto& p : a) {
		ys.push_back(p.second);
	}
	sort(all(ys));
	ys.resize(unique(all(ys)) - ys.begin());
	for (auto& p : a) {
		p.second = lower_bound(all(ys), p.second) - ys.begin();
	}
	Fenwick f(ys.size());
	long long ans = 0;
	for (int i = n - 1; i >= 0; --i) {
		auto nd = f.get(a[i].second);
		ans += nd.val - 1ll * a[i].first * nd.cnt;
		f.add(a[i].second, 1, a[i].first);
	}
	cout << ans << "\n";

	return 0;
}