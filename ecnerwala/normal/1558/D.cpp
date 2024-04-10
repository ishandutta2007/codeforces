#include <bits/stdc++.h>

namespace std {

template<class Fun>
class y_combinator_result {
	Fun fun_;
public:
	template<class T>
	explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}

	template<class ...Args>
	decltype(auto) operator()(Args &&...args) {
		return fun_(std::ref(*this), std::forward<Args>(args)...);
	}
};

template<class Fun>
decltype(auto) y_combinator(Fun &&fun) {
	return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));
}

} // namespace std

template <typename T> T mod_inv_in_range(T a, T m) {
	// assert(0 <= a && a < m);
	T x = a, y = m;
	T vx = 1, vy = 0;
	while (x) {
		T k = y / x;
		y %= x;
		vy -= k * vx;
		std::swap(x, y);
		std::swap(vx, vy);
	}
	assert(y == 1);
	return vy < 0 ? m + vy : vy;
}

template <typename T> T mod_inv(T a, T m) {
	a %= m;
	a = a < 0 ? a + m : a;
	return mod_inv_in_range(a, m);
}

template <int MOD_> struct modnum {
	static constexpr int MOD = MOD_;
	static_assert(MOD_ > 0, "MOD must be positive");

private:
	using ll = long long;

	int v;

public:

	modnum() : v(0) {}
	modnum(ll v_) : v(int(v_ % MOD)) { if (v < 0) v += MOD; }
	explicit operator int() const { return v; }
	friend std::ostream& operator << (std::ostream& out, const modnum& n) { return out << int(n); }
	friend std::istream& operator >> (std::istream& in, modnum& n) { ll v_; in >> v_; n = modnum(v_); return in; }

	friend bool operator == (const modnum& a, const modnum& b) { return a.v == b.v; }
	friend bool operator != (const modnum& a, const modnum& b) { return a.v != b.v; }

	modnum inv() const {
		modnum res;
		res.v = mod_inv_in_range(v, MOD);
		return res;
	}
	friend modnum inv(const modnum& m) { return m.inv(); }
	modnum neg() const {
		modnum res;
		res.v = v ? MOD-v : 0;
		return res;
	}
	friend modnum neg(const modnum& m) { return m.neg(); }

	modnum operator- () const {
		return neg();
	}
	modnum operator+ () const {
		return modnum(*this);
	}

	modnum& operator ++ () {
		v ++;
		if (v == MOD) v = 0;
		return *this;
	}
	modnum& operator -- () {
		if (v == 0) v = MOD;
		v --;
		return *this;
	}
	modnum& operator += (const modnum& o) {
		v -= MOD-o.v;
		v = (v < 0) ? v + MOD : v;
		return *this;
	}
	modnum& operator -= (const modnum& o) {
		v -= o.v;
		v = (v < 0) ? v + MOD : v;
		return *this;
	}
	modnum& operator *= (const modnum& o) {
		v = int(ll(v) * ll(o.v) % MOD);
		return *this;
	}
	modnum& operator /= (const modnum& o) {
		return *this *= o.inv();
	}

	friend modnum operator ++ (modnum& a, int) { modnum r = a; ++a; return r; }
	friend modnum operator -- (modnum& a, int) { modnum r = a; --a; return r; }
	friend modnum operator + (const modnum& a, const modnum& b) { return modnum(a) += b; }
	friend modnum operator - (const modnum& a, const modnum& b) { return modnum(a) -= b; }
	friend modnum operator * (const modnum& a, const modnum& b) { return modnum(a) *= b; }
	friend modnum operator / (const modnum& a, const modnum& b) { return modnum(a) /= b; }
};

static const uint64_t FIXED_RANDOM = std::chrono::steady_clock::now().time_since_epoch().count();
std::mt19937 mt(FIXED_RANDOM);
struct treap_node {
	std::array<treap_node*, 2> c{nullptr, nullptr};
	std::mt19937::result_type pri = mt();
	int lazy = 0;
	int v;

	void apply(int l) {
		v += l;
		lazy += l;
	}

	void downdate() {
		if (lazy) {
			if (c[0]) c[0]->apply(lazy);
			if (c[1]) c[1]->apply(lazy);
			lazy = 0;
		}
	}
};

treap_node* merge(treap_node* a, treap_node* b) {
	if (!b) return a;
	if (!a) return b;

	treap_node* r;
	if (a->pri < b->pri) {
		r = a;
		a->downdate();
		r->c[1] = merge(a->c[1], b);
	} else {
		r = b;
		b->downdate();
		r->c[0] = merge(a, b->c[0]);
	}
	return r;
}

std::pair<treap_node*, treap_node*> split(treap_node* r, int y) {
	if (!r) return {nullptr, nullptr};
	r->downdate();
	treap_node *a, *b;
	if (r->v >= y) {
		b = r;
		std::tie(a, b->c[0]) = split(r->c[0], y);
	} else {
		a = r;
		std::tie(a->c[1], b) = split(r->c[1], y);
	}
	return {a, b};
}

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	const int V = 1e6;
	using num = modnum<998244353>;
	std::vector<num> fact(V+1);
	fact[0] = 1;
	for (int i = 1; i <= V; i++) fact[i] = fact[i-1] * num(i);

	int T; cin >> T;
	while (T--) {
		int N; cin >> N;
		int M; cin >> M;
		std::vector<treap_node> nodes(M);
		treap_node* ROOT = nullptr;
		for (int z = 0; z < M; z++) {
			int x, y; cin >> x >> y; x--, y--;
			auto [l, r] = split(ROOT, y);
			if (r) r->apply(1);
			nodes[z].v = y+1;
			ROOT = merge(l, &nodes[z]);
			ROOT = merge(ROOT, r);
		}

		int prv = -1;
		int cnt = N-1;

		std::y_combinator([&](auto self, treap_node* a) -> void {
			if (!a) return;
			a->downdate();
			self(a->c[0]);
			if (a->v != prv) {
				cnt--;
				prv = a->v;
			}
			self(a->c[1]);
		})(ROOT);

		// cnt + N choose N
		cout << fact[cnt+N] / (fact[cnt] * fact[N]) << '\n';
	}

	return 0;
}