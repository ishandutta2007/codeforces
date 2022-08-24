#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

#define random_shuffle(...) shuffle(__VA_ARGS__, rng)
#define rand() rng()

#ifdef OLBOEB
	#define return std::cerr << __FUNCTION__ << "\n"; return
#endif  // OLBOEB

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

template <int mod>
struct Modular {
	int val;

	Modular(long long _val = 0) {
		if (_val < 0 || _val >= mod) {
			val = _val % mod;
			if (val < 0) {
				val += mod;
			}
		} else {
			val = _val;
		}
	}

	Modular operator +(const Modular& ot) const {
		int res = val + ot.val;
		if (res >= mod) {
			res -= mod;
		}
		return {res};
	}

	Modular operator -(const Modular& ot) const {
		int res = val - ot.val;
		if (res < 0) {
			res += mod;
		}
		return {res};
	}

	Modular operator *(const Modular& ot) const {
		return {1ll * val * ot.val};
	}

	Modular& operator ++() {
		val += 1;
		if (val == mod) {
			val = 0;
		}
		return *this;
	}

	Modular operator ++(int) {
		Modular tmp(*this);
		operator ++();
		return tmp;
	}

	void operator +=(const Modular& ot) {
		val += ot.val;
		if (val >= mod) {
			val -= mod;
		}
	}

	void operator -=(const Modular& ot) {
		val -= ot.val;
		if (val < 0) {
			val += mod;
		}
	}

	void operator *=(const Modular& ot) {
		val = 1ll * val * ot.val % mod;
	}

	operator long long() const {
		return val;
	}
};

const int mod = 998244353;
using Mint = Modular<mod>;

struct Node {
	Mint p_left, p_right, p_divisible;

	Node() {}
	Node(Mint p): p_left(1 - p), p_right(p), p_divisible(1) {}
	Node(const Mint& pl, const Mint& pr, const Mint& pd): p_left(pl), p_right(pr), p_divisible(pd) {}
};

Node merge(Node left, Node right) {
	return {
		left.p_left * right.p_left,
		left.p_right * right.p_right,
		left.p_divisible * right.p_right + left.p_left * right.p_divisible - left.p_left * right.p_right
	};
}

struct SegTree {
	int n;
	vector<Node> a;

	SegTree(const vector<Node>& nodes) {
		n = 1;
		while (n < (int)nodes.size()) {
			n *= 2;
		}
		a.assign(n + n, Node(1));
		for (int i = 0; i < (int)nodes.size(); ++i) {
			a[n + i] = nodes[i];
		}
		for (int i = n - 1; i > 0; --i) {
			a[i] = merge(a[i + i], a[i + i + 1]);
		}
	}

	Node get(int v, int l1, int r1, int l, int r) {
		if (l >= r1 || l1 >= r) {
			return {1, 1, 1};
		}
		if (l <= l1 && r >= r1) {
			return a[v];
		}
		int m = (l1 + r1) / 2;
		return merge(get(v + v, l1, m, l, r), get(v + v + 1, m, r1, l, r));
	}

	Node get(int l, int r) {
		return get(1, 0, n, l, r);
	}
};

struct Segment {
	int l, r;
	int max_l, min_r;

	Segment() {}
	Segment(int _l, int _r): l(_l), r(_r), max_l(-1), min_r(-1) {}
	Segment(int _l, int _r, int _max_l, int _min_r): l(_l), r(_r), max_l(_max_l), min_r(_min_r) {}
};

auto updL(Segment s, int idx) {
	if (s.max_l == -1 || s.max_l < idx) {
		s.max_l = idx;
	}
	return s;
}

auto updR(Segment s, int idx) {
	if (s.min_r == -1 || s.min_r > idx) {
		s.min_r = idx;
	}
	return s;
}

struct Fraction {
	long long p, q;

	bool operator <(const Fraction& ot) const {
		return p * ot.q < ot.p * q;
	}
};

struct Event {
	Fraction t;
	int idx, tp;

	bool operator <(const Event& ot) const {
		return tie(t, tp) < tie(ot.t, ot.tp);
	}
};

const int N = 2222222;
int inv[N];

template <typename T>
T pw(T a, long long b) {
	T res = 1;
	while (b) {
		if (b & 1ll) {
			res = res * a;
		}
		b >>= 1;
		a = a * a;
	}
	return res;
}

string getFrac(long long x) {
	for (int i = 1; i < 100; ++i) {
		if (x * i % mod < 100) {
			return to_string(x * i % mod) + "/" + to_string(i);
		}
	}
	return to_string(x);
}

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	inv[1] = 1;
	for (int i = 2; i < N; ++i) {
		inv[i] = mod - mod / i * 1ll * inv[mod % i] % mod;
	}

	int n = nxt();
	long long hundredth = 1;
	while (hundredth % 100) {
		hundredth += mod;
	}
	hundredth /= 100;
	vector<int> x(n), v(n);
	vector<Node> nds;
	for (int i = 0; i < n; ++i) {
		x[i] = nxt();
		v[i] = nxt();
		Mint p = nxt();
		p *= hundredth;
		nds.emplace_back(p);
	}

	/*{
		vector<int> cnts(n - 1);
		for (int mask = 0; mask < (1 << n); ++mask) {
			pair<double, int> opt = {1e9, -1};
			for (int i = 0; i < n - 1; ++i) {
				if ((mask & (1 << i)) && !(mask & (1 << (i + 1)))) {
					opt = min(opt, {1.0 * (x[i + 1] - x[i]) / (v[i] + v[i + 1]), i});
				} else if (v[i] > v[i + 1] && (mask & (1 << i)) && (mask & (1 << (i + 1)))) {
					opt = min(opt, {1.0 * (x[i + 1] - x[i]) / abs(v[i] - v[i + 1]), i});
				} else if (v[i] < v[i + 1] && !(mask & (1 << i)) && !(mask & (1 << (i + 1)))) {
					opt = min(opt, {1.0 * (x[i + 1] - x[i]) / abs(v[i] - v[i + 1]), i});
				}
			}
			if (opt.second > -1) {
				cnts[opt.second] += 1;
			}
			for (int i = 0; i < n; ++i) {
				cerr << ((mask & (1 << i)) ? "\\" : "/");
			}
			cerr << ": " << opt.second << "\n";
		}
		for (auto x : cnts) {
			cerr << x << " ";
		}
		cerr << "\n";
	}*/

	SegTree tree(nds);
	map<int, Segment> segs;
	for (int i = 0; i < n; ++i) {
		segs[i] = {i, i};
	}

	auto get = [&](const Segment& s) -> Mint {
		int l = (s.max_l == -1) ? s.l - 1 : s.max_l;
		int r = (s.min_r == -1) ? s.r + 1 : s.min_r;
		if (l >= r) {
			return 0;
		}
		// cerr << s.l << " " << s.r << " (" << s.max_l << ", " << s.min_r << "): " << tree.get(s.l, l + 1).p_left << " " << tree.get(l + 1, r).p_divisible << " " << tree.get(r, s.r + 1).p_right << "\n";
		return tree.get(s.l, l + 1).p_left * tree.get(l + 1, r).p_divisible * tree.get(r, s.r + 1).p_right;
	};

	auto merge = [&](const Segment& l, const Segment& r) -> Segment {
		return {l.l, r.r, r.max_l == -1 ? l.max_l : r.max_l, l.min_r == -1 ? r.min_r : l.min_r};
	};

	vector<Event> evs;
	for (int i = 0; i < n - 1; ++i) {
		evs.push_back({{x[i + 1] - x[i], v[i] + v[i + 1]}, i, 0});
		if (v[i] < v[i + 1]) {
			evs.push_back({{x[i + 1] - x[i], v[i + 1] - v[i]}, i, 2});
		} else if (v[i] > v[i + 1]) {
			evs.push_back({{x[i + 1] - x[i], v[i] - v[i + 1]}, i, 1});
		}
	}
	sort(all(evs));
	Mint ans = 0;
	Mint p = 1;
	for (auto e : evs) {
		// cerr << e.t.p << "/" << e.t.q << ": " << e.idx << " " << e.tp << ", p = " << getFrac(p) << "\n";
		if (e.tp == 0) {
			auto it = segs.find(e.idx + 1);
			assert(it != segs.end());
			auto r = it->second;
			auto l = prev(it)->second;
			segs.erase(prev(it));
			segs.erase(it);
			p *= pw(get(l), mod - 2);
			p *= pw(get(r), mod - 2);
			// cerr << e.t.p << "/" << e.t.q << " with prob " << getFrac(p * get(updL(r, e.idx + 1)) * get(updR(l, e.idx))) << "\n";
			ans += Mint(e.t.p) * Mint(inv[e.t.q]) * p * get(updL(r, e.idx + 1)) * get(updR(l, e.idx));
			auto s = merge(l, r);
			p *= get(s);
			segs[s.l] = s;
		} else {
			auto it = segs.upper_bound(e.idx);
			assert(it != segs.begin());
			--it;
			auto s = it->second;
			p *= pw(get(s), mod - 2);
			Mint old = get(s);
			if (e.tp == 1) {
				s = updL(s, e.idx);
			} else {
				s = updR(s, e.idx + 1);
			}
			// cerr << e.t.p << "/" << e.t.q << " with prob " << getFrac(p * (old - get(s))) << "\n";
			ans += Mint(e.t.p) * Mint(inv[e.t.q]) * p * (old - get(s));
			p *= get(s);
			segs[s.l] = s;
		}
		if (p == 0) {
			break;
		}
	}

	cout << ans.val << "\n";

	return 0;
}