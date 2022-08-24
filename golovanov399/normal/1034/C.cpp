#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

#define random_shuffle(...) shuffle(__VA_ARGS__, rng)
#define rand() rng()

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

const int N = 1111111;
vector<int> a[N];
long long val[N];
long long total;
void dfs(int v) {
	for (int x : a[v]) {
		dfs(x);
		val[v] += val[x];
	}
}

template <int N, int M, typename T = int>
struct Multilist {
	array<T, M> data;
	array<int, M> next;
	array<int, N> head;
	int sz;

	Multilist() {
		sz = 0;
		head.fill(-1);
	}

	void add(int idx, const T& x) {
		next[sz] = head[idx];
		head[idx] = sz;
		data[sz++] = x;
	}

	struct iterator {
		int x;
		array<T, M> *data_ptr;
		array<int, M> *next_ptr;

		T operator *() const {
			return (*data_ptr)[x];
		}

		iterator operator ++() {
			x = (*next_ptr)[x];
			return *this;
		}

		bool operator ==(const iterator& ot) const {
			return x == ot.x;
		}

		bool operator !=(const iterator& ot) const {
			return x != ot.x;
		}
	};

	struct Helper {
		int b, e;
		int idx;
		Multilist *super;

		iterator begin() const {
			return {b, &(super->data), &(super->next)};
		}

		iterator end() const {
			return {e, &(super->data), &(super->next)};
		}

		void push_back(const T& x) {
			super->add(idx, x);
		}

		void add(const T& x) {
			super->add(idx, x);
		}
	};

	Helper operator [](int idx) {
		return {head[idx], -1, idx, this};
	}
};

Multilist<N, 14 * N> divs;

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	int n = nxt();
	for (int i = 0; i < n; ++i) {
		val[i] = nxt();
	}
	for (int i = 0; i < n - 1; ++i) {
		a[nxt() - 1].push_back(i + 1);
	}
	total = accumulate(val, val + n, 0ll);

	dfs(0);

	// sort(val, val + n);
	for (int i = 0; i < n; ++i) {
		val[i] = total / gcd(val[i], total);
	}
	vector<int> cnt(n + 1);
	for (int i = 0; i < n; ++i) {
		if (val[i] <= n) {
			cnt[val[i]] += 1;
		}
	}
	for (int i = n; i; --i) {
		for (int j = i + i; j <= n; j += i) {
			cnt[j] += cnt[i];
		}
	}

	for (int i = 1; i <= n; ++i) {
		for (int j = i + i; j <= n; j += i) {
			divs[j].push_back(i);
		}
	}

	const int mod = 1000000007;
	vector<long long> num_divs(n + 1);
	num_divs[1] = 1;
	for (int i = 2; i <= n; ++i) {
		if (cnt[i] != i) continue;
		for (int j : divs[i]) {
			num_divs[i] += num_divs[j];
		}
		num_divs[i] %= mod;
	}
	long long ans = 0;
	for (int i = 1; i <= n; ++i) {
		if (cnt[i] == i) {
			ans += num_divs[i];
		}
	}
	cout << ans % 1000000007 << "\n";

	return 0;
}