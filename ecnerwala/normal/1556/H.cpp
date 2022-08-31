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

struct union_find {
	std::vector<int> par;
	union_find() {}
	union_find(int N) : par(N, -1) {}
	int get_par(int a) {
		while (par[a] >= 0) {
			if (par[par[a]] >= 0) par[a] = par[par[a]];
			a = par[a];
		}
		return a;
	}
	bool merge(int a, int b) {
		a = get_par(a), b = get_par(b);
		if (a == b) return false;
		if (par[a] > par[b]) std::swap(a, b);
		par[a] += par[b];
		par[b] = a;
		return true;
	}
	bool merge(std::array<int, 2> a) { return merge(a[0], a[1]); }
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

	int N, K; cin >> N >> K;

	std::vector<int> D_orig(K); for (auto& d : D_orig) cin >> d;

	tensor<int, 2> W({N, N});

	for (int i = 0; i < N; i++) {
		for (int j = i+1; j < N; j++) {
			int v; cin >> v;
			W[{i,j}] = W[{j,i}] = v;
		}
	}

	std::vector<std::pair<int, std::array<int, 2>>> small_edges; small_edges.reserve(K*(K-1)/2);
	for (int i = 0; i < K; i++) {
		for (int j = i+1; j < K; j++) {
			small_edges.push_back({W[{i,j}], {i,j}});
		}
	}

	assert(N-K > 0);
	std::vector<std::pair<int, std::array<int, 2>>> big_edges; big_edges.reserve(N*(N-1)/2);
	for (int i = K; i < N; i++) {
		for (int j = i+1; j < N; j++) {
			big_edges.push_back({W[{i,j}], {i,j}});
		}
	}
	std::sort(big_edges.begin(), big_edges.end());
	{
		int L = 0;
		union_find uf(N);
		for (int i = 0; i < int(big_edges.size()); i++) {
			if (uf.merge(big_edges[i].second)) {
				big_edges[L++] = big_edges[i];
			}
		}
		big_edges.resize(L);
		assert(L == N-K-1);
	}

	std::vector<std::pair<int, std::array<int, 2>>> ground_set; ground_set.reserve(N*K + int(big_edges.size()));
	for (int i = 0; i < K; i++) {
		for (int j = K; j < N; j++) {
			ground_set.push_back({W[{i,j}], {i,j}});
		}
	}
	ground_set.insert(ground_set.end(), big_edges.begin(), big_edges.end());

	int V = int(ground_set.size());

	/*
	for (int i = 0; i < V; i++) {
		cerr << ground_set[i].first << ' ' << ground_set[i].second[0] << ' ' << ground_set[i].second[1] << '\n';
	}
	*/

	const int INF = int(1e9);
	int ans = INF;
	for (int m = 0; m < (1 << int(small_edges.size())); m++) {
		std::vector<int> D = D_orig;
		union_find uf(N);
		int val = 0;
		{
			bool good = true;
			for (int i = 0; good && i < int(small_edges.size()); i++) {
				if (m & (1 << i)) {
					if (!uf.merge(small_edges[i].second)) {
						good = false;
						break;
					}
					val += small_edges[i].first;
					for (int a : small_edges[i].second) D[a]--;
				}
			}
			bool all_zero = true;
			for (int d : D) {
				if (d > 0) all_zero = false;
				if (d < 0) good = false;
			}
			if (all_zero) {
				assert(N-K > 0);
				good = false;
			}
			if (!good) continue;
		}

		std::vector<bool> used(V);
		for (int iter = __builtin_popcount(m); iter < N-1; iter++) {
			//cerr << "start iter" << '\n';
			std::vector<std::vector<pair<int, int>>> adj(V+K);

			std::vector<std::vector<pair<int, int>>> tree_adj(N);
			for (int i = 0; i < int(small_edges.size()); i++) {
				if (m & (1 << i)) {
					auto [a, b] = small_edges[i].second;
					tree_adj[a].push_back({b, -1});
					tree_adj[b].push_back({a, -1});
					//cerr << "tree " << a << ' ' << b << '\n';
				}
			}
			for (int i = 0; i < V; i++) {
				if (used[i]) {
					auto [a, b] = ground_set[i].second;
					tree_adj[a].push_back({b, i});
					tree_adj[b].push_back({a, i});
					//cerr << "tree " << a << ' ' << b << ' ' << i << '\n';
				}
			}
			std::vector<std::pair<int, int>> tree_par(N, {-1, -1});
			std::vector<int> tree_depth(N, -1);
			for (int i = 0; i < N; i++) {
				if (tree_depth[i] != -1) continue;
				tree_depth[i] = 0;
				std::y_combinator([&](auto self, int cur, int prv) -> void {
					for (auto [nxt, e] : tree_adj[cur]) {
						if (nxt == prv) continue;
						tree_par[nxt] = {cur, e};
						tree_depth[nxt] = tree_depth[cur]+1;
						self(nxt, cur);
					}
				})(i, -1);
			}

			std::vector<bool> can_source(V);
			std::vector<bool> can_sink(V);

			for (int i = 0; i < V; i++) {
				if (!used[i]) {
					auto [a, b] = ground_set[i].second;
					if (uf.get_par(a) == uf.get_par(b)) {
						while (a != b) {
							if (tree_depth[a] < tree_depth[b]) std::swap(a, b);
							int j = tree_par[a].second;
							if (j != -1) {
								adj[j].push_back({i, ground_set[i].first});
							}
							a = tree_par[a].first;
						}
					} else {
						can_source[i] = true;
					}
				}
			}

			for (int i = 0; i < V; i++) {
				auto [a, b] = ground_set[i].second;
				assert(b >= K);
				if (a < K) {
					if (used[i]) {
						if (D[a] == 0) {
							adj[V+a].push_back({i, -ground_set[i].first});
						}
					} else {
						if (D[a] > 0) {
							can_sink[i] = true;
						} else {
							adj[i].push_back({V+a, 0});
						}
					}
				} else {
					if (!used[i]) {
						can_sink[i] = true;
					}
				}
			}

			std::vector<pair<pair<int, int>, int>> dist(V+K, {{INF, INF}, -2});
			for (int i = 0; i < V; i++) {
				if (can_source[i]) dist[i] = {{ground_set[i].first, 0}, -1};
			}
			for (int z = 0; z < 5*K; z++) {
				for (int a = 0; a < V+K; a++) {
					if (dist[a].second == -2) continue;
					for (auto [b, w] : adj[a]) {
						dist[b] = min(dist[b], pair<pair<int, int>, int>{{dist[a].first.first + w, dist[a].first.second + 1}, a});
					}
				}
			}

			pair<pair<int, int>, int> best_dist{{INF, INF}, -2};
			for (int i = 0; i < V; i++) {
				if (can_sink[i]) {
					if (dist[i].second == -2) continue;
					best_dist = min(best_dist, {dist[i].first, i});
				}
			}
			if (best_dist.second == -2) {
				goto bad;
			}
			val += best_dist.first.first;

			int cur = best_dist.second;
			assert(can_sink[cur]);
			{
				int a = ground_set[cur].second[0];
				if (a < K) {
					assert(D[a] > 0);
					D[a]--;
				}
			}
			for (; dist[cur].second != -1; cur = dist[cur].second) {
				if (cur < V) {
					used[cur] = !used[cur];
				}
			}
			used[cur] = !used[cur];
			assert(can_source[cur]);
			uf.merge(ground_set[cur].second);
		}
		ans = min(ans, val);

		/*
		cerr << "final val " << val << '\n';
		for (int i = 0; i < int(small_edges.size()); i++) {
			if (m & (1 << i)) {
				auto [a, b] = small_edges[i].second;
				cerr << "tree " << a << ' ' << b << ' ' << small_edges[i].first << '\n';
			}
		}
		for (int i = 0; i < V; i++) {
			if (used[i]) {
				auto [a, b] = ground_set[i].second;
				cerr << "gnd " << a << ' ' << b << ' ' << ground_set[i].first << '\n';
			}
		}
		*/
bad:
		continue;
	}

	cout << ans << '\n';

	return 0;
}