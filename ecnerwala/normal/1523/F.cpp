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

template <typename T> void setmin(T& a, T b) { if (b < a) a = b; }
template <typename T> void setmax(T& a, T b) { if (b > a) a = b; }

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	auto dist = [](array<int, 2> a, array<int, 2> b) {
		return abs(a[0] - b[0]) + abs(a[1] - b[1]);
	};

	int N, M; cin >> N >> M;
	vector<array<int, 2>> locs(N);
	for (int i = 0; i < N; i++) {
		cin >> locs[i][0] >> locs[i][1];
	}

	vector<pair<int, array<int, 2>>> quests(M);
	for (int j = 0; j < M; j++) {
		int x, y, t; cin >> x >> y >> t;
		quests[j] = {t, {x, y}};
	}
	sort(quests.begin(), quests.end());

	const int INF = int(1e9) + 20;

	tensor<int, 2> min_dist({1 << N, N});
	for (int i = 0; i < N; i++) {
		min_dist[{0, i}] = INF;
	}
	for (int i = 0; i < N; i++) {
		vector<int> cur_dist(N);
		for (int j = 0; j < N; j++) {
			cur_dist[j] = dist(locs[i], locs[j]);
		}
		for (int msk = 0; msk < (1 << i); msk++) {
			for (int j = 0; j < N; j++) {
				min_dist[{msk | (1 << i), j}] = min(min_dist[{msk, j}], cur_dist[j]);
			}
		}
	}

	tensor<int, 2> cnt_at({M, 1 << N}, -1);
	tensor<int, 2> min_time({1 << N, M+1}, INF);
	vector<int> cur_idx(1 << N, 0);
	min_time[{0, 0}] = 0;
	for (int i = 0; i < N; i++) {
		min_time[{(1 << i), 0}] = 0;
	}

	int ans = 0;
	int cur_time = 0;
	for (int j = 0; j < M; j++) {
		{
			int nxt_time = quests[j].first;

			for (int msk = 1; msk < (1 << N); msk++) {
				int& a = cur_idx[msk];
				while (a <= M && min_time[{msk, a}] <= nxt_time) {
					for (int i = 0; i < N; i++) {
						if (msk & (1 << i)) continue;
						setmin(min_time[{msk | (1 << i), a}], min_time[{msk, a}] + min_dist[{msk, i}]);
					}
					a++;
				}
			}
			cur_time = nxt_time;
		}

		vector<int> cur_dist(N);
		for (int i = 0; i < N; i++) {
			cur_dist[i] = dist(quests[j].second, locs[i]);
		}

		for (int msk = 1; msk < (1 << N); msk++) {
			int d = INF;
			for (int i = 0; i < N; i++) {
				if (!(msk & (1 << i))) continue;
				setmin(d, cur_dist[i]);
			}
			int a = cur_idx[msk]-1;
			while (a >= 0 && min_time[{msk, a}] + d > cur_time) a--;
			cnt_at[{j, msk}] = a+1;
		}

		cnt_at[{j, 0}] = 1;

		for (int k = 0; k < j; k++) {
			if (dist(quests[k].second, quests[j].second) > quests[j].first - quests[k].first) continue;
			for (int msk = 0; msk < (1 << N); msk++) {
				setmax(cnt_at[{j, msk}], cnt_at[{k, msk}] + 1);
			}
		}

		for (int msk = 0; msk < (1 << N); msk++) {
			if (cnt_at[{j, msk}] == 0) {
				cnt_at[{j, msk}] = -1;
				continue;
			}
			setmax(ans, cnt_at[{j, msk}]);
			setmin(min_time[{msk, cnt_at[{j, msk}]}], cur_time);
			for (int i = 0; i < N; i++) {
				if (msk & (1 << i)) continue;
				setmin(min_time[{msk | (1 << i), cnt_at[{j, msk}]}], cur_time + cur_dist[i]);
			}
		}
	}
	cout << ans << '\n';

	return 0;
}