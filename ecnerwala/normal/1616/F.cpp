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
		int N, M; cin >> N >> M;
		tensor<int, 2> adj({N, N}, 0);
		std::vector<int> D(M);
		for (int e = 0; e < M; e++) {
			int a, b, c; cin >> a >> b >> c; a--, b--;
			if (c == -1) c = -1-e;
			D[e] = c;
			if (a > b) std::swap(a, b);
			adj[{a, b}] = c;
		}
		std::vector<std::vector<int>> eqn; eqn.reserve(512);
		for (int i = 0; i < N; i++) {
			for (int j = i+1; j < N; j++) {
				if (!adj[{i,j}]) continue;
				for (int k = j+1; k < N; k++) {
					if (adj[{i,k}] && adj[{j,k}]) {
						int a = adj[{i, j}];
						int b = adj[{i, k}];
						int c = adj[{j, k}];
						eqn.emplace_back(M+1);
						if (a < 0) eqn.back()[-1-a]++;
						else eqn.back()[M] += 3-(a-1);
						if (b < 0) eqn.back()[-1-b]++;
						else eqn.back()[M] += 3-(b-1);
						if (c < 0) eqn.back()[-1-c]++;
						else eqn.back()[M] += 3-(c-1);
						eqn.back()[M] %= 3;
					}
				}
			}
		}

		for (int i = 0; i < int(eqn.size()); i++) {
			int j = 0;
			while (j <= M && eqn[i][j] == 0) j++;
			if (j == M+1) {
				continue;
			} else if (j == M) {
				goto bad;
			}
			if (eqn[i][j] == 2) {
				for (int k = j; k <= M; k++) eqn[i][k] = (eqn[i][k] ? 3 ^ eqn[i][k] : 0);
			}
			assert(eqn[i][j] == 1);
			for (int i2 = 0; i2 < int(eqn.size()); i2++) {
				if (i2 == i) continue;
				if (eqn[i2][j] == 1) {
					for (int k = j; k <= M; k++) {
						eqn[i2][k] -= eqn[i][k];
						eqn[i2][k] = (eqn[i2][k] < 0 ? eqn[i2][k] + 3 : eqn[i2][k]);
					}
				} else if (eqn[i2][j] == 2) {
					for (int k = j; k <= M; k++) {
						eqn[i2][k] += eqn[i][k];
						eqn[i2][k] = (eqn[i2][k] >= 3 ? eqn[i2][k] - 3 : eqn[i2][k]);
					}
				}
				assert(eqn[i2][j] == 0);
			}
		}
		for (int i = 0; i < int(eqn.size()); i++) {
			int j = 0;
			while (j <= M && eqn[i][j] == 0) j++;
			if (j == M+1) {
				continue;
			}
			assert(j != M);
			assert(D[j] == -1-j);
			D[j] = eqn[i][M]+1;
		}

		for (int i = 0; i < M; i++) {
			if (D[i] < 0) D[i] = 1;
			cout << D[i] << " \n"[i+1==M];
		}

		continue;
bad:
		cout << -1 << '\n';
		continue;
	}

	return 0;
}

// x+y+z = 0 mod 3
// resubmit