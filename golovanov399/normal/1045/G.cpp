#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define itn int
#define make_unique(x) sort((x).begin(), (x).end()); (x).erase(unique((x).begin(), (x).end()), (x).end())

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

struct Robot {
	int x, r, iq;

	bool operator <(const Robot& ot) const {
		return r > ot.r;
	}
};

struct Fenwick {
	int n;
	vector<int> a;

	Fenwick(int _n = 0): n(_n), a(_n) {}

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

int main() {
	int n = nxt(), k = nxt();
	vector<Robot> a(n);
	for (int i = 0; i < n; ++i) {
		a[i].x = nxt();
		a[i].r = nxt();
		a[i].iq = nxt();
	}

	vector<int> iqs;
	for (const auto& r : a) {
		iqs.push_back(r.iq);
	}
	make_unique(iqs);

	vector<vector<int>> positions(iqs.size());
	for (const auto& r : a) {
		positions[lower_bound(all(iqs), r.iq) - iqs.begin()].push_back(r.x);
	}
	for (auto& v : positions) {
		make_unique(v);
	}

	vector<Fenwick> fenws(iqs.size());
	for (int i = 0; i < (int)iqs.size(); ++i) {
		fenws[i] = Fenwick(positions[i].size());
	}

	sort(all(a));
	long long ans = 0;
	for (const auto& r: a) {
		int it = lower_bound(all(iqs), r.iq - k) - iqs.begin();
		while (it < (int)iqs.size() && iqs[it] <= r.iq + k) {
			int le = lower_bound(all(positions[it]), r.x - r.r) - positions[it].begin();
			int ri = upper_bound(all(positions[it]), r.x + r.r) - positions[it].begin();
			ans += fenws[it].get(le, ri);
			++it;
		}
		int idx = lower_bound(all(iqs), r.iq) - iqs.begin();
		fenws[idx].add(lower_bound(all(positions[idx]), r.x) - positions[idx].begin(), 1);
	}

	cout << ans << "\n";

	return 0;
}