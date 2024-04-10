#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
// #define make_unique(x) sort(all(x)); x.resize(unique(all(x)) - x.begin())

using namespace std;

inline int nxt() {
	int x;
	// scanf("%d", &x);
	cin >> x;
	return x;
}

struct Seg {
	int i;
	int c;
	int l, r;
};

struct Event {
	int i;
	int c;
	int t;
	int type;

	bool operator <(const Event& ot) const {
		return tie(t, type) < tie(ot.t, ot.type);
	}
};

void remin(int& x, int y) {
	x = (x < y) ? x : y;
}

void solve() {
	int n = nxt();
	vector<Seg> a(n);
	vector<int> ans(n, 2e9);
	for (int i = 0; i < n; ++i) {
		a[i].l = nxt();
		a[i].r = nxt();
		a[i].c = nxt();
		a[i].i = i;
	}
	for ([[maybe_unused]] int it : {0, 1}) {
		vector<Event> evs;
		for (auto s : a) {
			evs.push_back({s.i, s.c, s.l, 0});
			evs.push_back({s.i, s.c, s.r, 1});
		}
		sort(all(evs));
		vector<pair<int, int>> furthest_left;
		map<int, set<int>> current;
		map<int, int> cnt;
		for (const auto& e : evs) {
			if (e.type == 0) {
				vector<int> to_rem;
				for (const auto& [c, v] : current) {
					if (c == e.c) {
						continue;
					}
					ans[e.i] = 0;
					for (int i : v) {
						ans[i] = 0;
					}
					to_rem.push_back(c);
				}
				for (int x : to_rem) {
					current.erase(x);
				}
				for (const auto& p : cnt) {
					if (p.first != e.c) {
						ans[e.i] = 0;
						break;
					}
				}
				for (const auto& [r, c] : furthest_left) {
					if (c != e.c) {
						remin(ans[e.i], e.t - r);
					}
				}
				current[e.c].insert(e.i);
				cnt[e.c] += 1;
			} else {
				if (auto it = current.find(e.c); it != current.end()) {
					it->second.erase(e.i);
					if (it->second.empty()) {
						current.erase(it);
					}
				}
				auto it = cnt.find(e.c);
				if (--it->second == 0) {
					cnt.erase(it);
				}
				bool found = false;
				for (auto& [r, c] : furthest_left) {
					if (c == e.c) {
						r = e.t;
						found = true;
					}
				}
				if (!found) {
					furthest_left.push_back({e.t, e.c});
					sort(all(furthest_left));
					if ((int)furthest_left.size() > 2) {
						furthest_left.erase(furthest_left.begin());
					}
				}
			}
		}

		for (auto& s : a) {
			s.l = -s.l;
			s.r = -s.r;
			swap(s.l, s.r);
		}
	}
	for (auto x : ans) {
		cout << x << " ";
	}
	cout << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = nxt();
	for (int i = 1; i <= t; ++i) {
		solve();
	}

	return 0;
}