#include <bits/stdc++.h>

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
	typename std::enable_if<(0 < D), tensor_view<T, NDIMS-1>>::type operator[] (int idx) const {
		std::array<int, NDIMS-1> nshape; std::copy(shape.begin()+1, shape.end(), nshape.begin());
		std::array<int, NDIMS-1> nstrides; std::copy(strides.begin()+1, strides.end(), nstrides.begin());
		T* ndata = data + (strides[0] * idx);
		return tensor_view<T, NDIMS-1>(nshape, nstrides, ndata);
	}
	template <int D = NDIMS>
	typename std::enable_if<(0 < D), tensor_view<T, NDIMS-1>>::type at(int idx) const {
		assert(0 <= idx && idx < shape[0]);
		return operator[](idx);
	}

	template <int D = NDIMS>
	typename std::enable_if<(0 == D), T&>::type operator * () const {
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
		return *this;
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
	typename std::enable_if<(0 < D), tensor_view<T, NDIMS-1>>::type operator[] (int idx) {
		return view()[idx];
	}
	template <int D = NDIMS>
	typename std::enable_if<(0 < D), tensor_view<T, NDIMS-1>>::type at(int idx) {
		return view().at(idx);
	}

	template <int D = NDIMS>
	typename std::enable_if<(0 < D), tensor_view<const T, NDIMS-1>>::type operator[] (int idx) const {
		return view()[idx];
	}
	template <int D = NDIMS>
	typename std::enable_if<(0 < D), tensor_view<const T, NDIMS-1>>::type at(int idx) const {
		return view().at(idx);
	}

	template <int D = NDIMS>
	typename std::enable_if<(0 == D), T&>::type operator * () {
		return *view();
	}
	template <int D = NDIMS>
	typename std::enable_if<(0 == D), const T&>::type operator * () const {
		return *view();
	}
};

template <typename T> T gcd(T a, T b) {
	while (a) {
		b %= a;
		std::swap(a, b);
	}
	return b;
}

template <typename T> T lcm(T a, T b) {
	return a / gcd(a, b) * b;
}

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	auto read_num = []() -> __int128_t {
		std::string s; cin >> s;
		__int128_t r = 0;
		for (char c : s) {
			r *= 10;
			r += c-'0';
		}
		return r;
	};
	auto to_string = [](__int128_t a) -> std::string {
		std::string s;
		while (a) {
			s += char('0' + (a % 10));
			a /= 10;
		}
		std::reverse(s.begin(), s.end());
		return s;
	};

	int T; cin >> T;
	while (T--) {
		int N, M; cin >> N >> M;


		std::vector<__int128_t> A(N);
		for (auto& a : A) a = read_num();
		std::vector<__int128_t> B(M);
		for (auto& b : B) b = read_num();

		tensor<__int128_t, 2> gcds({N, M});
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				gcds[{i, j}] = gcd(A[i], B[j]);
			}
		}

		std::vector<bool> A_alive(N, true);
		std::vector<bool> B_alive(M, true);


		tensor<__int128_t, 2> A_seg({N, 2*M});
		std::vector<int> A_queue; A_queue.reserve(N);
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				A_seg[{i, M+j}] = A[i] / gcds[{i, j}];
			}
			for (int a = M-1; a; a--) {
				A_seg[{i, a}] = gcd(A_seg[{i, 2*a}], A_seg[{i, 2*a+1}]);
			}
			if (A_seg[{i, 1}] > 1) {
				A_alive[i] = false;
				A_queue.push_back(i);
			}
		}
		tensor<__int128_t, 2> B_seg({M, 2*N});
		std::vector<int> B_queue; B_queue.reserve(M);
		for (int j = 0; j < M; j++) {
			for (int i = 0; i < N; i++) {
				B_seg[{j, N+i}] = B[j] / gcds[{i, j}];
			}
			for (int a = N-1; a; a--) {
				B_seg[{j, a}] = gcd(B_seg[{j, 2*a}], B_seg[{j, 2*a+1}]);
			}
			if (B_seg[{j, 1}] > 1) {
				B_alive[j] = false;
				B_queue.push_back(j);
			}
		}

		while (!A_queue.empty() || !B_queue.empty()) {
			for (int i : A_queue) {
				assert(!A_alive[i]);
				for (int j = 0; j < M; j++) {
					if (!B_alive[j]) continue;
					__int128_t nv = B[j];
					for (int a = N+i; true; a >>= 1) {
						if (B_seg[{j, a}] == nv) break;
						if (a == 1) {
							B_alive[j] = false;
							B_queue.push_back(j);
							break;
						}
						B_seg[{j, a}] = nv;
						nv = gcd(B_seg[{j, a}], B_seg[{j, a^1}]);
					}
				}
			}
			A_queue.clear();
			for (int j : B_queue) {
				assert(!B_alive[j]);
				for (int i = 0; i < N; i++) {
					if (!A_alive[i]) continue;
					__int128_t nv = A[i];
					for (int a = M+j; true; a >>= 1) {
						if (A_seg[{i, a}] == nv) break;
						if (a == 1) {
							A_alive[i] = false;
							A_queue.push_back(i);
							break;
						}
						A_seg[{i, a}] = nv;
						nv = gcd(A_seg[{i, a}], A_seg[{i, a^1}]);
					}
				}
			}
			B_queue.clear();
		}
		int sa = std::accumulate(A_alive.begin(), A_alive.end(), 0);
		int sb = std::accumulate(B_alive.begin(), B_alive.end(), 0);
		if (sa && sb) {
			cout << "YES" << '\n';
			cout << sa << ' ' << sb << '\n';
			for (int i = 0; i < N; i++) {
				if (A_alive[i]) {
					cout << to_string(A[i]) << " \n"[!(--sa)];
				}
			}
			for (int j = 0; j < M; j++) {
				if (B_alive[j]) {
					cout << to_string(B[j]) << " \n"[!(--sb)];
				}
			}
		} else {
			cout << "NO" << '\n';
		}
	}

	return 0;
}