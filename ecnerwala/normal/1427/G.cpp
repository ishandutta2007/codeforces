#include<bits/stdc++.h>

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

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int N; cin >> N;

	tensor<int, 2> A({N, N});
	vector<pair<int, array<int, 2>>> evts; evts.reserve(N*N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> A[{i,j}];
			if (A[{i,j}] > 0) {
				evts.push_back({A[{i,j}],{i,j}});
			}
		}
	}
	sort(evts.begin(), evts.end());

	tensor<int, 2> row_flow({N, N}); // from i,j to i,j+1
	tensor<int, 2> col_flow({N, N}); // from i,j to i+1,j
	tensor<int, 2> sink_flow({N, N}, -1);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (A[{i,j}] > 0) {
				sink_flow[{i,j}] = 0;
			}
		}
	}

	int cur_epoch = 1;
	tensor<int, 2> vis({N, N});

	auto send_flow = [&](array<int, 2> p) -> bool {
		bool ans = std::y_combinator([&](auto self, array<int, 2> cur) -> bool {
			if (A[cur] == -1) {
				return false;
			}
			if (vis[cur] == cur_epoch) {
				return false;
			}
			vis[cur] = cur_epoch;
			if (sink_flow[cur] != -1) {
				sink_flow[cur]++;
				return true;
			}

			if (cur[1] > 0) {
				auto nxt = cur;
				nxt[1] --;
				if (row_flow[nxt] != -1) {
					if (self(nxt)) {
						row_flow[nxt]--;
						return true;
					}
				}
			}
			if (cur[1] < N-1) {
				auto nxt = cur;
				nxt[1] ++;
				if (row_flow[cur] != 1) {
					if (self(nxt)) {
						row_flow[cur]++;
						return true;
					}
				}
			}
			if (cur[0] > 0) {
				auto nxt = cur;
				nxt[0] --;
				if (col_flow[nxt] != -1) {
					if (self(nxt)) {
						col_flow[nxt]--;
						return true;
					}
				}
			}
			if (cur[0] < N-1) {
				auto nxt = cur;
				nxt[0] ++;
				if (col_flow[cur] != 1) {
					if (self(nxt)) {
						col_flow[cur]++;
						return true;
					}
				}
			}
			return false;
		})(p);

		if (ans) {
			cur_epoch++;
		}
		return ans;
	};

	int cur_flow = 0;
	int last_val = 0;
	int64_t ans = 0;
	for (int z = 0; z < int(evts.size()); z++) {
		auto [cur_val, p] = evts[z];

		//cerr << cur_val << ' ' << last_val << ' ' << cur_flow << '\n';
		ans += int64_t(cur_val - last_val) * cur_flow;
		last_val = cur_val;


		int f = sink_flow[p];
		sink_flow[p] = -1;
		cur_flow -= f;
		//cerr << '(' << p[0] << ',' << p[1] << ')' << ' ' << f << '\n';
		while (send_flow(p)) {
			cur_flow++;
		}
	}

	assert(cur_flow == 0);
	cout << ans << '\n';

	return 0;
}