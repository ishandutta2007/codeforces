


#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort((x).begin(), (x).end()); (x).erase(unique((x).begin(), (x).end()), (x).end())
#define imie(x) #x << ": " << x

using namespace std;

using li = long long;
using LI = __int128_t;
using ld = long double;
using uint = unsigned int;
using ull = unsigned long long;

ostream& operator <<(ostream& ostr, LI x) {
	static constexpr li BIG = 1e18;
	if (x < 0) {
		ostr << "-";
		x = -x;
	}
	if (x < BIG) {
		return ostr << (li)x;
	} else if (x / BIG >= BIG) {
		stringstream ss;
		ss << setfill('0') << setw(18) << (li)(x / BIG % BIG);
		ss << setfill('0') << setw(18) << (li)(x % BIG);
		return ostr << (li)(x / BIG / BIG) << ss.str();
	} else {
		stringstream ss;
		ss << setfill('0') << setw(18) << (li)(x % BIG);
		return ostr << (li)(x / BIG) << ss.str();
	}
}

template <typename T>
ostream& operator <<(ostream& ostr, const vector<T>& vec) {
	auto [pre, sep, post] = (&ostr == &cout) ? make_tuple("", " ", "") : make_tuple("[", ", ", "]");
	ostr << pre;
	bool fp = true;
	for (const auto& x : vec) {
		if (fp) {
			fp = false;
		} else {
			ostr << sep;
		}
		ostr << x;
	}
	return ostr << post;
}

template <typename T, size_t N>
ostream& operator <<(ostream& ostr, const array<T, N>& vec) {
	auto [pre, sep, post] = (&ostr == &cout) ? make_tuple("", " ", "") : make_tuple("[", ", ", "]");
	ostr << pre;
	bool fp = true;
	for (const auto& x : vec) {
		if (fp) {
			fp = false;
		} else {
			ostr << sep;
		}
		ostr << x;
	}
	return ostr << post;
}

template <typename T>
ostream& operator <<(ostream& ostr, const set<T>& st) {
	auto [pre, sep, post] = (&ostr == &cout) ? make_tuple("", " ", "") : make_tuple("{", ", ", "}");
	ostr << pre;
	bool fp = true;
	for (const auto& x : st) {
		if (fp) {
			fp = false;
		} else {
			ostr << sep;
		}
		ostr << x;
	}
	return ostr << post;
}

template <typename T>
ostream& operator <<(ostream& ostr, const multiset<T>& st) {
	auto [pre, sep, post] = (&ostr == &cout) ? make_tuple("", " ", "") : make_tuple("{", ", ", "}");
	ostr << pre;
	bool fp = true;
	for (const auto& x : st) {
		if (fp) {
			fp = false;
		} else {
			ostr << sep;
		}
		ostr << x;
	}
	return ostr << post;
}

template <typename T, typename U>
ostream& operator <<(ostream& ostr, const map<T, U>& mp) {
	ostr << "{";
	bool fp = true;
	for (const auto& [k, v] : mp) {
		if (fp) {
			fp = false;
		} else {
			ostr << ", ";
		}
		ostr << k << ": " << v;
	}
	return ostr << "}";
}

template <typename T, typename U>
ostream& operator <<(ostream& ostr, const pair<T, U>& p) {
	return ostr << "(" << p.first << ", " << p.second << ")";
}


#define all(x) (x).begin(), (x).end()
#define itn int
#define make_unique(x) sort((x).begin(), (x).end()); (x).erase(unique((x).begin(), (x).end()), (x).end())


inline int nxt() {
	int x;
	cin >> x;
	return x;
}

void solve() {
	int n = nxt(), m = nxt();
	vector<int> ans(m + 1, -1);
	vector<char> can(m + 1, 0);
	vector<char> ncan(m + 1, 0);
	vector<int> required(m + 1);
	can[0] = 1;
	for (int it = 1; it <= n; ++it) {
		int t = nxt();
		if (t == 1) {
			long long x;
			cin >> x;
			int y = nxt();
			x = (x + 99999) / 100000;
			for (int i = 0; i < x; ++i) {
				int cnt = 0;
				for (int j = i; j <= m; j += x) {
					cnt += can[j];
					if (j - 1ll * (y + 1) * x >= 0) {
						cnt -= can[j - (y + 1) * x];
					}
					ncan[j] = !!cnt;
				}
			}
		} else {
			long long x;
			cin >> x;
			int y = nxt();
			const int def = 1e9;
			fill(all(required), def);
			for (int i = 1; i <= m; ++i) {
				if (can[i]) {
					required[i] = 0;
				}
				const long long ni = (1ll * i * x + 99999) / 100000;
				if (ni <= m) {
					required[ni] = required[i] + 1;
				}
				if (required[i] <= y) {
					ncan[i] = 1;
				}
			}
		}
		for (int i = 0; i <= m; ++i) {
			if (ncan[i] && !can[i]) {
				ans[i] = it;
				can[i] = 1;
			}
		}
	}
	ans.erase(ans.begin());
	cout << ans << "\n";
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