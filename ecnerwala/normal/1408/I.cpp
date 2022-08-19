#include<bits/extc++.h>

template <typename T, int NDIMS> struct tensor_view {
	static_assert(NDIMS >= 0, "NDIMS must be nonnegative");

protected:
	std::array<int, NDIMS> shape;
	std::array<int, NDIMS> strides;
	T* data;

	tensor_view(std::array<int, NDIMS> shape_, std::array<int, NDIMS> strides_, T* data_) : shape(shape_), strides(strides_), data(data_) {}

public:
	tensor_view() : shape{0}, strides{0}, data(nullptr) {}

protected:
	int flatten_index(std::array<int, NDIMS> idx) const {
		int res = 0;
		for (int i = 0; i < NDIMS; i++) { res += idx[i] * strides[i]; }
		return res;
	}
	int flatten_index_checked(std::array<int, NDIMS> idx) const {
		int res = 0;
		for (int i = 0; i < NDIMS; i++) {
			assert(0 <= idx[i] && idx[i] < shape[i]);
			res += idx[i] * strides[i];
		}
		return res;
	}

public:
	T& operator[] (std::array<int, NDIMS> idx) const {
		return data[flatten_index(idx)];
	}
	T& at(std::array<int, NDIMS> idx) const {
		return data[flatten_index_checked(idx)];
	}

	template <int D = NDIMS>
	std::enable_if_t<(0 < D), tensor_view<T, NDIMS-1>> operator[] (int idx) const {
		std::array<int, NDIMS-1> nshape; std::copy(shape.begin()+1, shape.end(), nshape.begin());
		std::array<int, NDIMS-1> nstrides; std::copy(strides.begin()+1, strides.end(), nstrides.begin());
		T* ndata = data + (strides[0] * idx);
		return tensor_view<T, NDIMS-1>(nshape, nstrides, ndata);
	}
	template <int D = NDIMS>
	std::enable_if_t<(0 < D), tensor_view<T, NDIMS-1>> at(int idx) const {
		assert(0 <= idx && idx < shape[0]);
		return operator[](idx);
	}

	template <int D = NDIMS>
	std::enable_if_t<(0 == D), T&> operator * () const {
		return *data;
	}

	template <typename U, int D> friend struct tensor_view;
	template <typename U, int D> friend struct tensor;
};

template <typename T, int NDIMS> struct tensor {
	static_assert(NDIMS >= 0, "NDIMS must be nonnegative");

protected:
	std::array<int, NDIMS> shape;
	std::array<int, NDIMS> strides;
	int len;
	T* data;

public:
	tensor() : shape{0}, strides{0}, len(0), data(nullptr) {}

	explicit tensor(std::array<int, NDIMS> shape_, const T& t = T()) {
		shape = shape_;
		strides[NDIMS-1] = 1;
		for (int i = NDIMS-1; i > 0; i--) {
			strides[i-1] = strides[i] * shape[i];
		}
		len = strides[0] * shape[0];
		data = new T[len];
		std::fill(data, data + len, t);
	}

	tensor(const tensor& o) : shape(o.shape), strides(o.strides), len(o.len), data(new T[len]) {
		for (int i = 0; i < len; i++) {
			data[i] = o.data[i];
		}
	}

	tensor& operator=(tensor&& o) noexcept {
		using std::swap;
		swap(shape, o.shape);
		swap(strides, o.strides);
		swap(len, o.len);
		swap(data, o.data);
	}
	tensor(tensor&& o) : tensor() {
		*this = std::move(o);
	}
	tensor& operator=(const tensor& o) {
		return *this = tensor(o);
	}
	~tensor() { delete[] data; }

	using view_t = tensor_view<T, NDIMS>;
	view_t view() {
		return tensor_view<T, NDIMS>(shape, strides, data);
	}
	operator view_t() {
		return view();
	}

	using const_view_t = tensor_view<const T, NDIMS>;
	const_view_t view() const {
		return tensor_view<const T, NDIMS>(shape, strides, data);
	}
	operator const_view_t() const {
		return view();
	}

	T& operator[] (std::array<int, NDIMS> idx) { return view()[idx]; }
	T& at(std::array<int, NDIMS> idx) { return view().at(idx); }
	const T& operator[] (std::array<int, NDIMS> idx) const { return view()[idx]; }
	const T& at(std::array<int, NDIMS> idx) const { return view().at(idx); }

	template <int D = NDIMS>
	std::enable_if_t<(0 < D), tensor_view<T, NDIMS-1>> operator[] (int idx) {
		return view()[idx];
	}
	template <int D = NDIMS>
	std::enable_if_t<(0 < D), tensor_view<T, NDIMS-1>> at(int idx) {
		return view().at(idx);
	}

	template <int D = NDIMS>
	std::enable_if_t<(0 < D), tensor_view<const T, NDIMS-1>> operator[] (int idx) const {
		return view()[idx];
	}
	template <int D = NDIMS>
	std::enable_if_t<(0 < D), tensor_view<const T, NDIMS-1>> at(int idx) const {
		return view().at(idx);
	}

	template <int D = NDIMS>
	std::enable_if_t<(0 == D), T&> operator * () {
		return *view();
	}
	template <int D = NDIMS>
	std::enable_if_t<(0 == D), const T&> operator * () const {
		return *view();
	}
};

struct splitmix64_hash {
	static uint64_t splitmix64(uint64_t x) {
		// http://xorshift.di.unimi.it/splitmix64.c
		x += 0x9e3779b97f4a7c15;
		x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
		x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
		return x ^ (x >> 31);
	}

	size_t operator()(uint64_t x) const {
		static const uint64_t FIXED_RANDOM = std::chrono::steady_clock::now().time_since_epoch().count();
		return splitmix64(x + FIXED_RANDOM);
	}
};

template <typename K, typename V, typename Hash = splitmix64_hash>
using hash_map = __gnu_pbds::gp_hash_table<K, V, Hash>;

template <typename K, typename Hash = splitmix64_hash>
using hash_set = hash_map<K, __gnu_pbds::null_type, Hash>;

template <int MOD_> struct modnum {
	static constexpr int MOD = MOD_;
	static_assert(MOD_ > 0, "MOD must be positive");

private:
	using ll = long long;

	int v;

	static int minv(int a, int m) {
		a %= m;
		assert(a);
		return a == 1 ? 1 : int(m - ll(minv(m, a)) * ll(m) / a);
	}

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
		res.v = minv(v, MOD);
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
		v += o.v;
		if (v >= MOD) v -= MOD;
		return *this;
	}
	modnum& operator -= (const modnum& o) {
		v -= o.v;
		if (v < 0) v += MOD;
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

template <typename T> T pow(T a, long long b) {
	assert(b >= 0);
	T r = 1; while (b) { if (b & 1) r *= a; b >>= 1; a *= a; } return r;
}

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int N, K, L; cin >> N >> K >> L;
	vector<int> A(N); for (auto& a : A) cin >> a;
	/*
	int K = 16, L = 16;
	int N = (1 << L) - K;
	vector<int> A(N); iota(A.begin(), A.end(), K);
	mt19937 mt(48); shuffle(A.begin(), A.end(), mt);
	*/

	assert(*min_element(A.begin(), A.end()) >= K);
	assert(*max_element(A.begin(), A.end()) < (1 << L));

	using num = modnum<998244353>;
	const num INV2 = inv(num(2));

	vector<num> fact((1 << 16) + 1);
	fact[0] = 1;
	for (int i = 1; i < int(fact.size()); i++) fact[i] = fact[i-1] * num(i);
	vector<num> ifact(fact.size());
	ifact.back() = inv(fact.back());
	for (int i = int(ifact.size())-1; i; --i) ifact[i-1] = ifact[i] * num(i);
	auto choose = [&](int n, int r) -> num {
		if (0 <= r && r <= n) return fact[n] * ifact[r] * ifact[n-r];
		else return 0;
	};

	int initial_val = 0; for (auto a : A) initial_val ^= a;
	num normalizer = inv(pow(num(N), K)) * fact[K];

	vector<array<num, 17>> dp(1 << 16);
	for (int i = 0; i < (1 << 16); i++) {
		dp[i].fill(0);
		dp[i][0] = num(1);
	}

	for (int lo = 0; lo < 16; lo++) {
		int tot_cnt = 0;
		vector<int> carries(12);
		for (auto a : A) {
			if ((a & 15) == lo) {
				tot_cnt++;
				int hi = a >> 4;
				if (hi) {
					carries[__builtin_ctz(hi)] ++;
				} else {
					assert(lo >= K);
				}
			}
		}
		int max_carry = K / (lo+1);
		vector<hash_map<int, num>> hi_ways(max_carry+1);
		hi_ways[0][0] = num(1);
		for (int i = 0; i < 12; i++) {
			for (int k = max_carry; k >= 0; k--) {
				for (int c = 1; c+k <= max_carry; c++) {
					for (auto it : hi_ways[k]) {
						if (carries[i]) {
							hi_ways[k+c][it.first ^ ((c & 1) ? (1 << (i+1)) - 1 : 0)] += it.second * choose(carries[i], c);
						}
					}
				}
			}
		}
		tensor<num, 4> lo_ways({K+1, K+1, max_carry+1, 16});
		lo_ways[{0,0,0,0}] = 1;
		for (int num_nonzero = 0; num_nonzero < K; num_nonzero++) {
			for (int k = 0; k <= K; k++) {
				for (int num_carry = 0; num_carry <= k / (lo+1); num_carry++) {
					for (int c = 1; c+k <= K; c++) {
						if (c > lo && num_carry != num_nonzero) continue;
						for (int v = 0; v < 16; v++) {
							lo_ways[{num_nonzero+1, k+c, num_carry + (c > lo), v ^ ((lo ^ (lo - c)) & 15)}] +=
								lo_ways[{num_nonzero, k, num_carry, v}] * choose(c+k, k);
						}
					}
				}
			}
		}

		vector<array<num, 17>> cur_dp(1 << 16);
		for (int i = 0; i < (1<<16); i++) cur_dp[i].fill(num(0));
		for (int num_carry = 0; num_carry <= max_carry; num_carry++) {
			for (int v = 0; v < 16; v++) {
				for (int k = 0; k <= K; k++) {
					num cur_ways = 0;
					for (int num_nonzero = 0; num_nonzero <= k; num_nonzero++) {
						cur_ways += lo_ways[{num_nonzero, k, num_carry, v}] * choose(tot_cnt - num_carry, num_nonzero - num_carry);
					}
					for (auto it : hi_ways[num_carry]) {
						cur_dp[(it.first << 4) | v][k] += cur_ways * it.second * ifact[k];
					}
				}
			}
		}

		for (int l = 0; l < 16; l++) {
			for (int i = 0; i < (1 << 16); i++) {
				if (i & (1 << l)) continue;
				for (int k = 0; k <= 16; k++) {
					num& a = cur_dp[i][k];
					num& b = cur_dp[i | (1 << l)][k];
					num x = a, y = b;
					a = (x + y);
					b = (x - y);
				}
			}
		}

		for (int i = 0; i < (1 << 16); i++) {
			array<num, 17> nval; nval.fill(num(0));
			for (int k = 0; k <= 16; k++) {
				for (int k2 = 0; k + k2 <= 16; k2++) {
					nval[k+k2] += dp[i][k] * cur_dp[i][k2];
				}
			}
			dp[i] = nval;
		}
	}

	vector<num> ans(1 << 16);
	for (int i = 0; i < (1 << 16); i++) {
		ans[i] = dp[i][K];
	}
	for (int l = 0; l < 16; l++) {
		for (int i = 0; i < (1 << 16); i++) {
			if (i & (1 << l)) continue;
			num& a = ans[i];
			num& b = ans[i | (1 << l)];
			num x = a, y = b;
			a = (x + y) * INV2;
			b = (x - y) * INV2;
		}
	}

	for (int i = 0; i < (1 << L); i++) {
		cout << ans[i ^ initial_val] * normalizer << " \n"[i+1==(1 << L)];
	}

	return 0;
}