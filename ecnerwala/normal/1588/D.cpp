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

int char_to_val(char c) {
	if ('A' <= c && c <= 'Z') {
		return c - 'A';
	} else if ('a' <= c && c <= 'z') {
		return (c - 'a') + 26;
	} else assert(false);
}

char val_to_char(int v) {
	if (0 <= v && v < 26) {
		return char('A' + v);
	} else if (26 <= v && v < 52) {
		return char('a' + (v - 26));
	} else assert(false);
}

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	
	int T; cin >> T;
	while (T--) {
		int N; cin >> N;
		std::vector<std::string> S(N);
		for (auto& s : S) cin >> s;
		std::vector<std::array<std::array<int, 2>, 52>> loc(N);

		const int INF = 1e9;

		for (int i = 0; i < N; i++) {
			for (int v = 0; v < 52; v++) loc[i][v][0] = loc[i][v][1] = INF;
			for (int l = 0; l < int(S[i].size()); l++) {
				int v = char_to_val(S[i][l]);
				if (loc[i][v][0] == INF) {
					loc[i][v][0] = l;
				} else if (loc[i][v][1] == INF) {
					loc[i][v][1] = l;
				} else assert(false);
			}
		}

		tensor<std::pair<int, int>, 2> dp({52, 1 << N}, {-1, -1});

		auto dfs = std::y_combinator([&](auto self, int v, int msk) -> int {
			if (dp[{v, msk}].first != -1) {
				return dp[{v, msk}].first;
			}

			dp[{v, msk}] = {0, -1};

			for (int nv = 0; nv < 52; nv++) {
				int nmsk = 0;
				for (int i = 0; i < N; i++) {
					int cur_loc = loc[i][v][(msk >> i) & 1];
					if (cur_loc < loc[i][nv][0]) {
						if (loc[i][nv][0] == INF) goto bad;
					} else if (cur_loc < loc[i][nv][1]) {
						if (loc[i][nv][1] == INF) goto bad;
						nmsk |= (1 << i);
					} else {
						goto bad;
					}
				}
				dp[{v, msk}] = max(dp[{v, msk}], {self(nv, nmsk) + 1, nv});
bad:
				continue;
			}

			return dp[{v, msk}].first;
		});

		std::vector<bool> valid_start(52, true);
		std::pair<int, int> best(0, -1);
		for (int v = 0; v < 52; v++) {
			for (int i = 0; i < N; i++) {
				if (loc[i][v][0] == INF) {
					valid_start[v] = false;
					break;
				}
			}
			if (valid_start[v]) {
				best = max(best, {dfs(v, 0) + 1, v});
			}
		}

		string res; res.reserve(best.first);
		for (int v = best.second, msk = 0; true; ) {
			if (v == -1) {
				assert(res.empty());
				break;
			}
			res += val_to_char(v);
			int nv = dp[{v, msk}].second;
			if (nv == -1) {
				assert((dp[{v, msk}].first == 0));
				break;
			}
			int nmsk = 0;
			for (int i = 0; i < N; i++) {
				int cur_loc = loc[i][v][(msk >> i) & 1];
				if (cur_loc < loc[i][nv][0]) {
					if (loc[i][nv][0] == INF) assert(false);
				} else if (cur_loc < loc[i][nv][1]) {
					if (loc[i][nv][1] == INF) assert(false);
					nmsk |= (1 << i);
				} else {
					assert(false);
				}
			}
			v = nv;
			msk = nmsk;
		}
		cout << res.size() << '\n';
		cout << res << '\n';
	}

	return 0;
}