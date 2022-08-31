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

struct Op {
	int l, r;
};

#define apply klsdjfklsjdf

void apply(string& s, const Op& op) {
	reverse(s.begin() + op.l, s.begin() + op.r);
}

vector<Op> proceed_to_canonical(vector<int> a, int k) {
	assert((int)a.size() >= k + 2);
	vector<Op> res;

	auto make_turn = [&](int l, int r, int delta) {
		int left_index = accumulate(a.begin(), a.begin() + l, 0) + l - 1;
		int right_index = accumulate(a.begin(), a.begin() + r, 0) + r;
		if (delta > 0) {
			right_index += delta;
		} else {
			left_index += delta;
		}
		res.push_back({left_index, right_index});
		reverse(a.begin() + l, a.begin() + r);
		a[l - 1] += delta;
		a[r] -= delta;
		// for (int x : a) {
		// 	cerr << x << " ";
		// }
		// cerr << "\n";
	};

	[[maybe_unused]] auto go_full_r2l = [&](int l) {
		const int r = l + k - 1;
		make_turn(l, r, a[r]);
	};
	[[maybe_unused]] auto go_full_l2r = [&](int l) {
		const int r = l + k - 1;
		make_turn(l, r, -a[l - 1]);
	};

	if (k % 2) {
		for (int i = 0; i < (int)a.size() - k; ++i) {
			go_full_l2r(i + 1);
		}
		int from = (int)a.size() - k;

		for (int i = 0; i < k - 1; ++i) {
			go_full_l2r(from - 1);
			go_full_l2r(from);
		}
	} else {
		for (int i = 0; i < (int)a.size() - k - 2; ++i) {
			go_full_l2r(i + 1);
		}
		int from = (int)a.size() - k;

		for (int i = 0; i < k / 2 - 1; ++i) {
			go_full_r2l(from - 1);
			make_turn(from, from + k - 1, 0);
		}
		for (int i = 0; i < k / 2; ++i) {
			go_full_l2r(from - 1);
			go_full_l2r(from);
		}
	}

	// assert(all_of(all(a) - 2 + k % 2, [](int x) { return x == 0; }));

	return res;
}

vector<int> diffs(const string& s) {
	vector<int> res = {0};
	for (char c : s) {
		if (c == '1') {
			res.push_back(0);
		} else {
			res.back() += 1;
		}
	}
	return res;
}

void solve() {
	[[maybe_unused]] int n = nxt(), k = nxt();
	string s, t;
	cin >> s >> t;
	if (count(all(s), '1') != count(all(t), '1')) {
		cout << "-1\n";
		return;
	}
	const int cnt = count(all(s), '1');

	if (k == 0 || k > cnt) {
		if (s == t) {
			cout << "0\n";
		} else {
			cout << "-1\n";
		}
		return;
	}
	if (k == cnt) {
		string ns = s, nt = t;
		vector<int> ans;
		for (int i = n - 1; i >= 0; --i) {
			if (s[i] == '1') {
				reverse(ns.begin(), ns.begin() + i + 1);
				ans.push_back(i);
				break;
			}
		}
		for (int i = n - 1; i >= 0; --i) {
			if (t[i] == '1') {
				reverse(nt.begin(), nt.begin() + i + 1);
				ans.push_back(i);
				break;
			}
		}
		string nns = ns, nnt = nt;
		for (int i = n - 1; i >= 0; --i) {
			if (ns[i] == '1') {
				reverse(nns.begin(), nns.begin() + i + 1);
				ans.push_back(i);
				break;
			}
		}
		for (int i = n - 1; i >= 0; --i) {
			if (nt[i] == '1') {
				reverse(nnt.begin(), nnt.begin() + i + 1);
				ans.push_back(i);
				break;
			}
		}
		if (ns == nt) {
			cout << "2\n" << 1 << " " << ans[0] + 1 << "\n" << 1 << " " << ans[1] + 1 << "\n";
		} else if (nns == nt) {
			cout << "3\n" << 1 << " " << ans[0] + 1 << "\n" << 1 << " " << ans[2] + 1 << "\n" << 1 << " " << ans[1] + 1 << "\n";
		} else {
			cout << "-1\n";
		}
		return;
	}

	auto for_s = proceed_to_canonical(diffs(s), k);
	auto for_t = proceed_to_canonical(diffs(t), k);

	// assert((int)for_s.size() <= 2 * n);
	// assert((int)for_t.size() <= 2 * n);

	auto ns = s, nt = t;
	for (auto op : for_s) {
		// assert(count(ns.begin() + op.l, ns.begin() + op.r, '1') == k);
		apply(ns, op);
	}
	for (auto op : for_t) {
		// assert(count(nt.begin() + op.l, nt.begin() + op.r, '1') == k);
		apply(nt, op);
	}

	if (ns != nt) {
		cout << "-1\n";
	} else {
		cout << for_s.size() + for_t.size() << "\n";
		reverse(all(for_t));
		for (const auto& [l, r] : for_s) {
			cout << l + 1 << " " << r << "\n";
		}
		for (const auto& [l, r] : for_t) {
			cout << l + 1 << " " << r << "\n";
		}
	}
}

int main() {
	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}