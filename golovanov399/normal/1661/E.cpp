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

struct State {
	int cnt;
	array<short, 6> ids;
};

ostream& operator <<(ostream& ostr, const State& s) {
	ostr << "(cnt = " << s.cnt << ", ids = {";
	for (int i = 0; i < 6; ++i) {
		if (i) {
			ostr << ", ";
		}
		if (s.ids[i] == -1) {
			ostr << "x";
		} else {
			ostr << s.ids[i];
		}
	}
	return ostr << "}";
}

void renumber(State& s) {
	vector<short> M;
	int cur = 0;
	for (short& x : s.ids) {
		if (x == -1) {
			continue;
		}
		if (x >= (int)M.size()) {
			M.resize(x + 1, -1);
		}
		if (M[x] == -1) {
			M[x] = cur++;
		}
		x = M[x];
	}
}

vector<vector<int>> m2c[8] = {{}, {{0}}, {{1}}, {{0, 1}}, {{2}}, {{0}, {2}}, {{1, 2}}, {{0, 1, 2}}};

void add(State& st, int mask) {
	// cerr << st << ", " << mask << " -> ";
	int cur = *max_element(all(st.ids)) + 1;
	for (const auto& c : m2c[mask]) {
		int num = -1;
		for (int i : c) {
			if (st.ids[3 + i] > -1) {
				num = st.ids[3 + i];
			}
		}
		if (num == -1) {
			++st.cnt;
			for (int i : c) {
				st.ids[3 + i] = cur;
			}
			++cur;
		} else {
			for (int i : c) {
				if (st.ids[3 + i] > -1 && st.ids[3 + i] != num) {
					--st.cnt;
					for (short& j : st.ids) {
						if (j == st.ids[3 + i]) {
							j = num;
						}
					}
				}
			}
			for (int i : c) {
				st.ids[3 + i] = num;
			}
		}
	}
	for (int i = 0; i < 3; ++i) {
		if (!(mask & (1 << i))) {
			st.ids[3 + i] = -1;
		}
	}
	// renumber(st);
	// cerr << st << "\n";
}

void add(int mask, State& st) {
	for (int i = 0; i < 3; ++i) {
		swap(st.ids[i], st.ids[i + 3]);
	}
	add(st, mask);
	for (int i = 0; i < 3; ++i) {
		swap(st.ids[i], st.ids[i + 3]);
	}
}

State merge(State s1, State s2) {
	// cerr << s1 << ", " << s2 << " -> ";
	for (auto& x : s2.ids) {
		if (x != -1) {
			x += 6;
		}
	}
	State res;
	res.cnt = s1.cnt + s2.cnt;
	for (int i = 0; i < 3; ++i) {
		res.ids[i] = s1.ids[i];
	}
	for (int i = 3; i < 6; ++i) {
		res.ids[i] = s2.ids[i];
	}
	for (int i = 0; i < 3; ++i) {
		short x = s1.ids[i + 3];
		short y = s2.ids[i];
		if (y == -1) {
			continue;
		}
		if (~x && ~y && x != y) {
			--res.cnt;
			for (auto& z : s2.ids) {
				if (z == y) {
					z = x;
				}
			}
			for (auto& z : res.ids) {
				if (z == y) {
					z = x;
				}
			}
		}
	}
	// cerr << res << "\n";
	return res;
}

State nullstate = {0, {{-1, -1, -1, -1, -1, -1}}};

State int2state(int mask) {
	vector<vector<int>> comps;
	if (mask == 0b101) {
		comps = {{0}, {2}};
	} else if (mask) {
		comps = {{}};
		for (int i = 0; i < 3; ++i) {
			if (mask & (1 << i)) {
				comps[0].push_back(i);
			}
		}
	}
	State s = nullstate;
	for (int i = 0; i < (int)comps.size(); ++i) {
		s.cnt += 1;
		for (int j : comps[i]) {
			s.ids[j] = s.ids[j + 3] = i;
		}
	}
	return s;
}

struct NonIdempotentSparse {
	vector<vector<State>> left, right;

	void build(const vector<int>& a) {
		left.assign(a.size(), {});
		right.assign(a.size(), {});
		for (int i = 0; i < (int)a.size(); ++i) {
			left[i] = {int2state(a[i])};
		}
		for (int i = 0; i < (int)a.size() - 1; ++i) {
			const int ctz = __builtin_ctz(i + 1);
			State cur = left[i][0];
			for (int j = i; j > 0 && __builtin_ctz(j) < ctz; --j) {
				add(a[j - 1], cur);
				left[i].push_back(cur);
			}
		}
		for (int i = 1; i < (int)a.size(); ++i) {
			const int ctz = __builtin_ctz(i);
			State cur = left[i][0];
			right[i] = {cur};
			for (int j = i + 1; j < (int)a.size() && __builtin_ctz(j) < ctz; ++j) {
				add(cur, a[j]);
				right[i].push_back(cur);
			}
		}
	}

	NonIdempotentSparse() {}

	explicit NonIdempotentSparse(const vector<int>& a) {
		build(a);
	}

	State get(int l, int r) const {
		assert(r > l);
		if (r == l + 1) {
			return left[l][0];
		}
		if (r == l + 2) {
			return merge(left[l][0], right[r - 1][0]);
		}
		const int tmp = l ^ (r - 1);
		const int pos = (r - 1) & ~((1 << (31 - __builtin_clz(tmp))) - 1);
		return merge(left[pos - 1][pos - l - 1], right[pos][r - pos - 1]);
	}
};

void solve() {
	int n = nxt();
	string s[3];
	for (int i = 0; i < 3; ++i) {
		cin >> s[i];
	}
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		a[i] = (s[0][i] - '0') + (s[1][i] - '0') * 2 + (s[2][i] - '0') * 4;
	}
	// vector<int> a(n);
	// for (int i = 0; i < n; ++i) {
	// 	a[i] = rand() % 8;
	// }
	auto st = NonIdempotentSparse(a);

	int q = nxt();
	while (q --> 0) {
		int l = nxt() - 1, r = nxt();
		cout << st.get(l, r).cnt << "\n";
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1; // nxt();
	while (t--) {
		solve();
	}

	return 0;
}