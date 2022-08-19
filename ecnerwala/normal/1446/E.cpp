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

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int N_INF; cin >> N_INF;
	const int X = 520, Y = 520;
	auto adj = [&](array<int, 2> p) -> array<array<int, 2>, 3> {
		auto [x,y] = p;
		return {array<int, 2>{x-1, y}, {x+1,y}, {x^1, x + y - (x ^ 1)}};
	};

	tensor<bool, 2> infected({X, Y});
	tensor<bool, 2> orig_infected({X, Y});
	vector<array<int, 2>> q; q.reserve(X*Y*3);
	for (int i = 0; i < N_INF; i++) {
		int x, y; cin >> x >> y;
		x += 10, y += 10;
		infected[{x,y}] = true;
		orig_infected[{x,y}] = true;
		for (auto n : adj({x,y})) {
			q.push_back(n);
		}
	}

	for (int z = 0; z < int(q.size()); z++) {
		auto p = q[z];
		if (infected[p]) continue;
		int cnt = 0;
		for (auto n : adj(p)) {
			if (infected[n]) cnt++;
		}
		if (cnt >= 2) {
			infected[p] = true;
			for (auto n : adj(p)) {
				q.push_back(n);
			}
		}
	}

	tensor<array<int, 2>, 2> par({X,Y}, {-1, -1});
	auto get_par = [&](array<int, 2> p) {
		while (true) {
			if (par[p][0] < 0) return p;
			if (par[par[p]][0] < 0) return par[p];
			par[p] = par[par[p]];
			p = par[p];
		}
	};
	auto merge = [&](array<int, 2> p, array<int, 2> q) {
		p = get_par(p), q = get_par(q);
		if (p == q) return false;
		if (par[p][0] > par[q][0]) swap(p, q);
		par[p][0] += par[q][0];
		par[q] = p;
		return true;
	};

	int num_vert = 0;
	int num_cc = 0;
	for (int i = 0; i < X; i++) {
		for (int j = 0; j < Y; j++) {
			array<int, 2> p{i,j};
			if (infected[p]) {
				num_vert++;
				num_cc++;
				for (auto n : adj(p)) {
					if (n > p && infected[n]) {
						if (!merge(p, n)) {
							cout << "SICK" << '\n';
							exit(0);
						}
						num_cc--;
					}
				}
			}
		}
	}

	int ans = 0;
	for (int i = 0; i < X; i++) {
		for (int j = 0; j < Y; j++) {
			array<int, 2> p{i,j};
			if (orig_infected[p]) {
				for (auto n : adj(p)) {
					if (!orig_infected[n]) {
						ans++;
					}
				}
			} else if (infected[p]) {
				if (par[get_par(p)][0] == -4) {
					auto ns = adj(p);
					if (orig_infected[ns[0]] && orig_infected[ns[1]] && orig_infected[ns[2]]) {
						ans -= 2;
					}
				}
			}
		}
	}
	ans -= 2 * num_cc;

	cout << "RECOVERED" << '\n';
	cout << ans % 998244353 << '\n';

	return 0;
}