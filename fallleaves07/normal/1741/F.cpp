#include<bits/stdc++.h>
using namespace std;
using LL = long long;

struct BIT {
	int n;
	vector<int> mx;
	BIT(int _n) : n(_n), mx(n + 1) {}
	void insert(int loc, int val) {
		for (int i = loc; i <= n; i += i & -i) {
			mx[i] = max(mx[i], val);
		}
	}
	int query(int loc) {
		int ret = 0;
		for (int i = loc; i; i -= i & -i) {
			ret = max(ret, mx[i]);
		}
		return ret;
	}
};

void solve() {
	int n;
	cin >> n;
	struct Seg {
		int l, r, c, id;
		bool operator<(const Seg &b) const {
			if (l != b.l) {
				return l < b.l;
			}
			return r < b.r;
		}
	};
	vector<Seg> s(n);
	for (int i = 0; i < n; i++) {
		cin >> s[i].l >> s[i].r >> s[i].c;
		s[i].id = i;
	}
	sort(s.begin(), s.end());
	const int inf = 0x3f3f3f3f;
	vector<int> ans(n, inf);
	{
		BIT pre(n), suf(n);
		for (auto [l, r, c, id] : s) {
			int d = max(pre.query(c - 1), suf.query(n - c));
			if (d > 0) {
				ans[id] = min(ans[id], max(0, l - d));
			}
			pre.insert(c, r), suf.insert(n - c + 1, r);
		}
	}
	reverse(s.begin(), s.end());
	{
		BIT pre(n), suf(n);
		int R = 1e9 + 1;
		for (auto [l, r, c, id] : s) {
			int d = max(pre.query(c - 1), suf.query(n - c));
			if (d > 0) {
				ans[id] = min(ans[id], max(0, (R - r) - d));
			}
			pre.insert(c, R - l), suf.insert(n - c + 1, R - l);
		}
	}
	for (int i = 0; i < n; i++) {
		printf("%d ", ans[i]);
	}
	puts("");
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
	int T;
	cin >> T;
	while (T--) {
		solve();
	}
    return 0;
}