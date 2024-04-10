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

template <typename T> void setmax(T& a, T b) { if (b > a) a = b; }

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int N, K; cin >> N >> K;
	string S, T; cin >> S >> T;
	assert(int(S.size()) == N);
	assert(int(T.size()) == 2);
	if (T[0] == T[1]) {
		int cnt = 0;
		for (int i = 0; i < N; i++) {
			cnt += S[i] == T[0];
		}
		cnt = min(cnt + K, N);
		cout << int64_t(cnt) * int64_t(cnt-1) / 2 << '\n';
		exit(0);
	}

	assert(T[0] != T[1]);

	// split the array into 2 pieces based on where we change -> T[0] and where we change to T[1]
	// # 0's on left is orig 0's + K_0, # 1's on the right is orig 1's + K_1
	// left_internal + (left 0's + K_0) * (right 1's + K_1) + right_internal

	// Greedy means that we should pick 4 number's K_0, K_10, K_1, K_01;
	// change K_0 leftmost randoms, K_10 leftmost 1's to 0
	// change K_1 rightmost randoms, K_01 rightmost 0's to 1

	// 0x10x1x0xxxxx0xx0xxx1
	// 00000100xxxxx0xx0xxx1
	//
	// closed form of left_internal: sum of last indices of 1's
	// x -> 0 benefit is # 1's to the right
	// 1 -> 0 benefit is # 1's to the right - idx
	// **Can greedy on these**
	//
	// pick k_0 best val_0's and k_1 best val_1's so that sum(val_0) + sum(val_1) + k_0 * k_1 is maximized

	int orig_ans = 0;
	{
		int c0 = 0;
		for (int i = 0; i < N; i++) {
			if (S[i] == T[1]) orig_ans += c0;
			else if (S[i] == T[0]) c0++;
		}
	}

	vector<int> suff_1(N+1);
	vector<int> pref_0(N+1);
	for (int i = 0; i < N; i++) {
		pref_0[i+1] = pref_0[i] + (S[i] == T[0]);
	}
	for (int i = N-1; i >= 0; i--) {
		suff_1[i] = suff_1[i+1] + (S[i] == T[1]);
	}

	vector<int> val_0(N);
	vector<int> val_1(N);
	for (int i = 0; i < N; i++) {
		if (S[i] == T[0]) {
			val_0[i] = -N-1;
			val_1[i] = pref_0[i] - (N-1-i);
		} else if (S[i] == T[1]) {
			val_1[i] = -N-1;
			val_0[i] = suff_1[i+1] - i;
		} else {
			val_0[i] = suff_1[i+1];
			val_1[i] = pref_0[i];
		}
	}

	for (int i = 0; i < N; i++) {
		//cerr << i << ' ' << val_0[i] << ' ' << val_1[i] << '\n';
	}

	int ans = 0;
	for (int m = 0; m <= N; m++) {
		vector<int> cur_val_0(val_0.begin(), val_0.begin() + m);
		vector<int> cur_val_1(val_1.begin() + m, val_1.end());
		sort(cur_val_0.begin(), cur_val_0.end(), std::greater<>());
		sort(cur_val_1.begin(), cur_val_1.end(), std::greater<>());
		for (int k0 = 0; k0 <= int(cur_val_0.size()); k0++) {
			for (int k1 = 0; k1 <= int(cur_val_1.size()); k1++) {
				if (k0 + k1 > K) continue;
				int cnd = orig_ans + k0 * k1;
				for (int i = 0; i < k0; i++) {
					cnd += cur_val_0[i];
				}
				for (int i = 0; i < k1; i++) {
					cnd += cur_val_1[i];
				}
				ans = max(ans, cnd);
			}
		}
	}

	cout << ans << '\n';

/*
	int ans = 0;
	int cnd = 0;
	multiset<int> los, his;
	for (int i = 0; i < N; i++) {
		los.insert(val_1[i]);
	}
	while (int(his.size()) < K) {
		cnd += *los.rbegin();
		his.insert(*los.rbegin());
		los.erase(los.find(*los.rbegin()));
	}
	cerr << cnd << '\n';
	ans = cnd;

	for (int i = 0; i < N; i++) {
		cerr << "move " << i << '\n';
		if (his.count(val_1[i])) {
			cnd -= val_1[i];
			his.erase(his.find(val_1[i]));
		} else {
			assert(los.count(val_1[i]));
			los.erase(los.find(val_1[i]));
		}

		if (his.empty() || val_0[i] < *his.begin()) {
			los.insert(val_0[i]);
		} else {
			cnd += val_0[i];
			his.insert(val_0[i]);
		}

		while (int(his.size()) < K) {
			cnd += *los.rbegin();
			his.insert(*los.rbegin());
			los.erase(los.find(*los.rbegin()));
		}
		while (int(his.size()) > K) {
			cnd -= *his.begin();
			los.insert(*his.begin());
			his.erase(his.begin());
		}

		cerr << cnd << '\n';
		ans = max(ans, cnd);
	}

	{
		int c0 = 0;
		for (int i = 0; i < N; i++) {
			if (S[i] == T[1]) ans += c0;
			else if (S[i] == T[0]) c0++;
		}
	}
	cout << ans << '\n';
	*/

	/*
	tensor<int, 3> dp({N+1, N+1, K+1}, -1);
	dp[{0, 0, 0}] = 0;

	for (int i = 0; i < N; i++) {
		for (int c0 = 0; c0 <= N; c0++) {
			for (int k = 0; k <= K; k++) {
				if (dp[{i, c0, k}] == -1) continue;
				// treat it as nothing
				setmax(dp[{i+1, c0, k}], dp[{i, c0, k}]);

				// change it to T[0]
				if (k + (S[i] != T[0]) <= K && c0+1 <= N) {
					setmax(dp[{i+1, c0+1, k + (S[i] != T[0])}], dp[{i, c0, k}]);
				}

				// change it to T[1]
				if (k + (S[i] != T[1]) <= K) {
					setmax(dp[{i+1, c0, k + (S[i] != T[1])}], dp[{i, c0, k}] + c0);
				}
			}
		}
	}

	int ans = 0;
	for (int c0 = 0; c0 <= N; c0++) {
		for (int k = 0; k <= K; k++) {
			ans = max(ans, dp[{N, c0, k}]);
		}
	}
	cout << ans << '\n';
	*/

	return 0;
}