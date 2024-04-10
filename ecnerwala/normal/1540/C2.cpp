#include <bits/stdc++.h>

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

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	using num = modnum<int(1e9)+7>;

	int N; cin >> N;
	vector<int> C(N); for (auto& c : C) cin >> c;
	vector<int> B(N-1); for (auto& b : B) cin >> b;
	int Q; cin >> Q;
	vector<pair<int, int>> X(Q); for (auto& x : X) cin >> x.first;
	for (int q = 0; q < Q; q++) X[q].second = q;

	vector<num> ans(Q);

	sort(X.begin(), X.end());
	vector<pair<int, int>> dupes; dupes.reserve(Q);
	{
		int L = 0;
		for (int z = 0; z < Q; z++) {
			if (L > 0 && X[z].first == X[L-1].first) {
				dupes.push_back({X[z].second, X[L-1].second});
			} else {
				X[L++] = X[z];
			}
		}
		X.resize(L);
	}


	int totC = std::accumulate(C.begin(), C.end(), 0);
	vector<num> dp; dp.reserve(totC+1);
	vector<num> dp2; dp2.reserve(totC+1);
	dp.assign(1, num(1));
	vector<int> offsets(N+1);
	offsets[0] = 0;
	{
		int cur_offset = 0;
		for (int i = 1; i <= N; i++) {
			offsets[i] = offsets[i-1] + cur_offset;
			if (i < N) cur_offset += B[i-1];
		}
	}

	auto extend = [](std::vector<num>& vec, int c) -> void {
		int L = int(vec.size())-1;
		vec.resize(L+c+1, num(0));
		num cur = 0;
		for (int v = L+c; v >= 0; v--) {
			if (v >= c) cur += vec[v-c];
			cur -= std::exchange(vec[v], cur);
		}
	};

	int z = int(X.size())-1;

	for (int i = 0; i < N; i++) {
		extend(dp, C[i]);

		// now, restrict it to sum >= X * (i+1) + tot_offset, then it's okay
		for (; z >= 0 && X[z].first * (i+1) + offsets[i+1] > 0; z--) {
			if (X[z].first * (i+1) + offsets[i+1] >= int(dp.size())) {
				ans[X[z].second] = num(0);
				continue;
			}
			dp2 = dp;
			for (int j = i+1; true; j++) {
				int lo = X[z].first * j + offsets[j];
				assert(lo > 0);
				if (lo >= int(dp2.size())) {
					ans[X[z].second] = num(0);
					break;
				}
				std::fill(dp2.begin(), dp2.begin()+lo, num(0));
				if (j == N) {
					ans[X[z].second] = std::accumulate(dp2.begin(), dp2.end(), num(0));
					break;
				}
				extend(dp2, C[j]);
			}
		}
	}
	assert(int(dp.size()) == totC+1);

	num small_ans = std::accumulate(dp.begin(), dp.end(), num(0));
	for (; z >= 0; z--) {
		ans[X[z].second] = small_ans;
	}

	for (auto [f, t] : dupes) {
		ans[f] = ans[t];
	}

	for (int q = 0; q < Q; q++) {
		cout << ans[q] << '\n';
	}

	return 0;
}