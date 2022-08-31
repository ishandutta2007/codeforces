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

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int T; cin >> T;

	while (T--) {
		int N; cin >> N;
		vector<vector<int>> A(2*N, vector<int>(N));
		for (auto& a : A) for (auto& v : a) { cin >> v; v--; }

		tensor<pair<int, int>, 2> cnt({N, N}, pair<int, int>{0,0});
		tensor<vector<int>, 2> inds({N, N});
		for (int i = 0; i < 2*N; i++) {
			for (int j = 0; j < N; j++) {
				cnt[{j, A[i][j]}].first++;
				cnt[{j, A[i][j]}].second ^= i;
				inds[{j, A[i][j]}].push_back(i);
			}
		}

		vector<bool> alive(2*N, true);
		vector<int> res; res.reserve(N);

		for (int j = 0; j < N; j++) {
			for (int v = 0; v < N; v++) {
				if (cnt[{j, v}].first == 1) {
					int i = cnt[{j, v}].second;
					if (alive[i]) {
						alive[i] = false;
						res.push_back(i);
					}
				}
			}
		}

		auto remove_vec = [&](int i) -> void {
			assert(alive[i]);
			alive[i] = false;
			for (int j = 0; j < N; j++) {
				int v = A[i][j];
				cnt[{j, v}].first --;
				cnt[{j, v}].second ^= i;
				if (cnt[{j, v}].first == 1) {
					int ni = cnt[{j, v}].second;
					if (alive[ni]) {
						alive[ni] = false;
						res.push_back(ni);
					}
				}
			}
		};
		int ways = 1;
		const int MOD = 998244353;
		for (int z = 0, idx = 0; int(res.size()) < N; ) {
			if (z == int(res.size())) {
				if (alive[idx]) {
					ways <<= 1;
					if (ways >= MOD) ways -= MOD;
					alive[idx] = false;
					res.push_back(idx);
				}
				idx++;
				continue;
			}
			int s = res[z++];
			assert(!alive[s]);
			// mark them all impossible
			for (int x = 0; x < N; x++) {
				cnt[{x, A[s][x]}] = {0, 0};
			}
			for (int x = 0; x < N; x++) {
				for (int i : inds[{x, A[s][x]}]) {
					if (alive[i]) remove_vec(i);
				}
			}
		}
		cout << ways << '\n';
		for (int i = 0; i < N; i++) {
			cout << res[i]+1 << " \n"[i+1==N];
		}
	}

	return 0;
}