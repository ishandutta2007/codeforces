#include <bits/stdc++.h>

#include <array>
#include <tuple>
#include <type_traits>
#include <utility>

using std::array, std::tuple, std::swap;
using std::forward_as_tuple;

template <typename T, int dim> struct Tensor;

template <typename T, int dim, int idx, class D = void>
struct TensorView {
	const array<int, dim>& shape;
	const array<int, dim>& subsizes;
	T* data;

	TensorView& operator =(TensorView&& ot) {
		std::copy(data, data + subsizes[idx + 1] * shape[idx], ot.data);
		return *this;
	}

	TensorView<T, dim, idx + 1> operator [](int i) {
		return {shape, subsizes, data + subsizes[idx] * i};
	}

	TensorView<T, dim, idx + 1> back() {
		return operator [](shape[idx] - 1);
	}
};

template <typename T, int dim, int idx>
struct TensorView<T, dim, idx, std::enable_if_t<idx + 1 == dim>> {
	const array<int, dim>& shape;
	const array<int, dim>& subsizes;
	T* data;

	TensorView& operator =(TensorView&& ot) {
		std::copy(data, data + shape[idx], ot.data);
		return *this;
	}

	T& operator [](int i) {
		return data[i];
	}

	T& back() {
		return operator [](shape[idx] - 1);
	}
};

template <int... I>
struct indices {
	using next = indices<I..., sizeof...(I)>;

	template <typename... T>
	static array<std::remove_cvref_t<std::tuple_element_t<0, tuple<T...>>>, sizeof...(I)> of(tuple<T...>&& t) {
		return {get<I>(t)...};
	}
};

template <int N>
struct build_indices {
	using type = typename build_indices<N - 1>::type::next;
};

template <>
struct build_indices<0> {
	using type = indices<>;
};

template <typename T, int dim>
struct Tensor {
	static_assert(dim > 0);
	array<int, dim> shape;
	array<int, dim> subsizes;
	int sz;
	T* data;

	template <typename... Int>
	explicit Tensor(Int... args) {
		T val = T();
		if constexpr (sizeof...(args) == dim + 1) {
			val = get<dim>(forward_as_tuple(args...));
			shape = build_indices<dim>::type::of(forward_as_tuple(args...));
		} else {
			static_assert(sizeof...(args) == dim);
			shape = {args...};
		}
		subsizes.fill(1);
		for (int i = dim - 2; i >= 0; --i) {
			subsizes[i] = subsizes[i + 1] * shape[i + 1];
		}
		sz = subsizes[0] * shape[0];
		data = new T[sz];
		this->fill(val);
	}

	Tensor(const Tensor& ot): shape(ot.shape), subsizes(ot.subsizes), sz(ot.sz), data(new T[sz]) {
		memcpy(data, ot.data, sizeof(T) * sz);
	}

	Tensor& operator =(Tensor&& ot) noexcept {
		shape.swap(ot.shape);
		subsizes.swap(ot.subsizes);
		swap(sz, ot.sz);
		swap(data, ot.data);
		return *this;
	}

	Tensor(Tensor&& ot) {
		*this = move(ot);
	}

	~Tensor() {
		delete[] data;
	}

	void fill(const T& val) {
		std::fill(data, data + sz, val);
	}

	TensorView<T, dim, 0> view() {
		return {shape, subsizes, data};
	}

	TensorView<const T, dim, 0> const_view() const {
		return {shape, subsizes, data};
	}

	auto operator [](int idx) {
		return view()[idx];
	}

	auto back() {
		return view().back();
	}

	auto operator [](int idx) const {
		return const_view()[idx];
	}

	auto back() const {
		return const_view().back();
	}

	T& operator [](array<int, dim> ids) {
		int i = 0;
		for (int j = 0; j < dim; ++j) {
			i += ids[j] * subsizes[j];
		}
		return data[i];
	}

	const T& operator [](array<int, dim> ids) const {
		int i = 0;
		for (int j = 0; j < dim; ++j) {
			i += ids[j] * subsizes[j];
		}
		return data[i];
	}
};

#define all(x) (x).begin(), (x).end()
// #define make_unique(x) sort(all(x)); x.resize(unique(all(x)) - x.begin())

using namespace std;

inline int nxt() {
	int x;
	// scanf("%d", &x);
	cin >> x;
	return x;
}

void solve() {
	int n = nxt(), m = nxt();
	string s, t;
	cin >> s >> t;
	if (n == m) {
		if (s != t) {
			cout << "-1\n";
		} else {
			cout << "0\n";
		}
		return;
	}
	Tensor<char, 2> can_match(n + 1, m + 1, 0);
	Tensor<int, 2> where_prev_removed(n + 1, m + 1, -1);
	can_match[0][0] = 1;
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j <= m; ++j) {
			can_match[i][j] = can_match[i - 1][j] || (j > 0 && s[i - 1] == t[j - 1] && can_match[i - 1][j - 1]);
			if (j > 0 && s[i - 1] == t[j - 1] && can_match[i - 1][j - 1]) {
				where_prev_removed[i][j] = where_prev_removed[i - 1][j - 1];
			} else if (can_match[i - 1][j]) {
				where_prev_removed[i][j] = i - 1;
			}
		}
	}
	if (!can_match[n][m]) {
		cout << "-1\n";
		return;
	}
	Tensor<char, 2> can_match_rev(n + 1, m + 1, 0);
	can_match_rev[0][0] = 1;
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j <= m; ++j) {
			can_match_rev[i][j] = can_match_rev[i - 1][j] || (j > 0 && s[n - i] == t[m - j] && can_match_rev[i - 1][j - 1]);
		}
	}
	Tensor<char, 2> can_be_kth_removed(n, n - m, 0);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n - m; ++j) {
			can_be_kth_removed[i][j] = i - j >= 0 && i - j <= m && can_match[i][i - j] && can_match_rev[n - 1 - i][m - i + j];
		}
	}
	vector<int> earliest(n - m, n), latest(n - m, 0);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n - m; ++j) {
			if (can_be_kth_removed[i][j]) {
				earliest[j] = min(earliest[j], i);
				latest[j] = max(latest[j], i);
			}
		}
	}

	int ans = 1e9;
	// no home
	ans = min(ans, n - latest[0]);
	// insta home
	ans = min(ans, 1 + (earliest[n - m - 1] + 1) + (n - m));
	// (n-m-k) removed with backspace, then home and another k

	for (int i = 0; i < n; ++i) {
		for (int k = 1; k < n - m; ++k) {
			if (can_be_kth_removed[i][k]) {
				int p = where_prev_removed[i][i - k];
				ans = min(ans, (n - i) + 1 + (p + 1) + k);
			}
		}
	}

	cout << ans << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = nxt();
	for (int i = 1; i <= t; ++i) {
		// cout << "Case #" << i << ": ";
		solve();
	}

	return 0;
}