#include<bits/stdc++.h>
using namespace std;
using LL = long long;

void solve() {
	int n;
	cin >> n;
	vector<int> d1(n), d2(n);
	multiset<int> s1, s2;
	for (auto &v : d1) {
		cin >> v;
		s1.insert(v);
	}
	for (auto &v : d2) {
		cin >> v;
		s2.insert(v);
	}
	auto back = [](multiset<int> &s) {
		return --s.end();
	};
	auto check = [&](LL h) {
		multiset<int> sa = s1, sb = s2;
		vector<pair<int, int>> ans;
		while (!sa.empty() || !sb.empty()) {
			if (sa.empty() || (!sb.empty() && *back(sb) > *back(sa))) {
				if (*back(sb) < h) {
					break;
				}
				int val = *back(sb) - h;
				if (sa.find(val) == sa.end()) {
					return false;
				} else {
					ans.emplace_back(val, *back(sb));
					sa.erase(sa.find(val)), sb.erase(back(sb));
				}
			} else {
				if (*back(sa) < h) {
					break;
				}
				int val = *back(sa) - h;
				if (sb.find(val) == sb.end()) {
					return false;
				} else {
					ans.emplace_back(*back(sa), val);
					sb.erase(sb.find(val)), sa.erase(back(sa));
				}
			}
		}
		for (auto v : sa) {
			if (sb.find(h - v) == sb.end()) {
				return false;
			}
			ans.emplace_back(v, h - v);
			sb.erase(sb.find(h - v));
		}
		int p1 = 0, p2 = h;
		vector<int> pos;
		for (auto [x, y] : ans) {
			if (x + y == h) {
				pos.push_back(x);
			} else if (x + h == y) {
				pos.push_back(-x);
			} else if (x == y + h) {
				pos.push_back(x);
			} else {
				assert(false);
			}
		}
		int mn = 0;
		for (auto v : pos) {
			mn = min(mn, v);
		}
		puts("YES");
		for (auto v : pos) {
			printf("%d ", v - mn);
		}
		puts("");
		printf("%d %d\n", p1 - mn, p2 - mn);
		return true;
	};
	for (auto v : d2) {
		if (check(d1[0] + v)) {
			return;
		}
		if (check(abs(d1[0] - v))) {
			return;
		}
	}
	puts("NO");
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