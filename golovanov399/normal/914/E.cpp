#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

#ifdef ONLINE_JUDGE
	inline int pidorand() {
		return ((rand() & 32767) << 15) | (rand() & 32767);
	}
	#define rand pidorand
#endif	// ONLINE_JUDGE

#ifdef OLBOEB
	#define return std::cerr << __FUNCTION__ << "\n"; return
#endif  // OLBOEB

using namespace std;

inline int nxt() {
	int x;
	cin >> x;
	return x;
}

const int N = 222222;
vector<int> a[N];

char used[N];
int size[N];

void mark_size(int v) {
	size[v] = 1;
	used[v] = 1;
	for (int x : a[v]) {
		if (used[x]) {
			continue;
		}
		mark_size(x);
		size[v] += size[x];
	}
}

void clear_used(int v) {
	used[v] = 0;
	for (int x : a[v]) {
		if (used[x] == 1) {
			clear_used(x);
		}
	}
}

int find_root(int v, int sz) {
	while (true) {
		int nx = -1;
		for (int x : a[v]) {
			if (used[x] > 1 || size[x] > size[v]) {
				continue;
			}
			if (2 * size[x] > sz) {
				nx = x;
				break;
			}
		}
		if (nx > -1) {
			v = nx;
		} else {
			return v;
		}
	}
}

long long ans[N];

const int M = 1 << 20;
int num[M];
int ar[N];
int msk[N];

void add(int v, int cur, int ad, int p = -1) {
	cur ^= ar[v];
	msk[v] = cur;
	num[cur] += ad;
	for (int x : a[v]) {
		if (x == p || used[x] == 2) {
			continue;
		}
		add(x, cur, ad, v);
	}
}

long long total;
long long alone;

long long upd(int v, int ad, int mask, int p = -1) {
	long long res = 0;
	for (int x = 1; x < M; x *= 2) {
		int idx = msk[v] ^ x ^ mask;
		int tmp = num[idx] * ad;
		res += tmp;
		total += tmp;
		if (!idx) {
			alone += ad;
		}
	}
	{
		int idx = msk[v] ^ mask;
		int tmp = num[idx] * ad;
		res += tmp;
		total += tmp;
		if (!idx) {
			alone += ad;
		}
	}
	for (int x : a[v]) {
		if (x == p || used[x]) {
			continue;
		}
		res += upd(x, ad, mask, v);
	}
	ans[v] += res;
	return res;
}

void solve(int v) {
	mark_size(v);
	v = find_root(v, size[v]);
	clear_used(v);
	used[v] = 2;

	// cerr << v + 1 << " is center now\n";

	total = 0;
	for (int x : a[v]) {
		if (used[x]) {
			continue;
		}
		add(x, 0, 1, v);
		upd(x, -1, ar[v], v);
		add(x, 0, -1, v);
	}

	for (int x : a[v]) {
		if (used[x]) {
			continue;
		}
		add(x, 0, 1, v);
	}

	// for (int i = 0; i < M; ++i) {
	// 	if (num[i]) {
	// 		cerr << num[i] << " of " << i << "\n";
	// 	}
	// }

	alone = 0;
	num[0] += 1;
	for (int x : a[v]) {
		if (used[x]) {
			continue;
		}
		upd(x, 1, ar[v], v);
	}
	num[0] -= 1;
	// cerr << "total " << total << " paths through " << v + 1 << "\n";
	// cerr << alone << " alone paths through " << v + 1 << "\n\n";
	// cerr << "ans(2) = " << ans[1] << " now\n";

	ans[v] += (total + alone) / 2;

	for (int x : a[v]) {
		if (used[x]) {
			continue;
		}
		add(x, 0, -1, v);
	}

	for (int x : a[v]) {
		if (!used[x]) {
			solve(x);
		}
	}
}

int n;

vector<long long> smart() {
	solve(0);
	return vector<long long>(ans, ans + n);
}

vector<long long> stupid() {
	vector<long long> result(n);
	function<int(int, int, int)> dfs = [&](int v, int mask, int p) {
		int res = 0;
		mask ^= ar[v];
		if (__builtin_popcount(mask) <= 1) {
			++res;
		}
		for (int x : a[v]) {
			if (x == p) {
				continue;
			}
			res += dfs(x, mask, v);
		}
		result[v] += res;
		return res;
	};
	for (int i = 0; i < n; ++i) {
		dfs(i, 0, -1);
	}
	for (int i = 0; i < n; ++i) {
		result[i] /= 2;
	}
	return result;
}

int main() {
	// while (true) {
	// 	n = rand() % 300 + 2;
	// 	for (int i = 0; i < n; ++i) {
	// 		a[i].clear();
	// 		if (i > 0) {
	// 			int j = rand() % i;
	// 			a[i].push_back(j);
	// 			a[j].push_back(i);
	// 		}
	// 		ar[i] = 1 << (rand() % 20);
	// 	}
	// 	memset(ans, 0, sizeof(long long) * n);
	// 	memset(num, 0, sizeof(int) * n);
	// 	memset(used, 0, sizeof(char) * n);

	// 	auto r1 = smart();
	// 	auto r2 = stupid();
	// 	if (r1 != r2) {
	// 		cerr << n << "\n";
	// 		for (int i = 0; i < n; ++i) {
	// 			for (int j : a[i]) {
	// 				if (j < i) {
	// 					cerr << j + 1 << " " << i + 1 << "\n";
	// 				}
	// 			}
	// 		}
	// 		for (int i = 0; i < n; ++i) {
	// 			cerr << (char)('a' + __builtin_ctz(ar[i]));
	// 		}
	// 		cerr << "\n";
	// 		for (auto x : r1) {
	// 			cerr << x << " ";
	// 		}
	// 		cerr << "\n";
	// 		for (auto x : r2) {
	// 			cerr << x << " ";
	// 		}
	// 		cerr << "\n";
	// 		return 0;
	// 	} else {
	// 		cerr << "ok ";
	// 	}
	// }

	cin.sync_with_stdio(0);
	n = nxt();
	for (int i = 0; i < n - 1; ++i) {
		int u = nxt() - 1, v = nxt() - 1;
		a[u].push_back(v);
		a[v].push_back(u);
	}
	string s;
	cin >> s;
	for (int i = 0; i < n; ++i) {
		ar[i] = 1 << (s[i] - 'a');
	}

	solve(0);
	for (int i = 0; i < n; ++i) {
		printf("%lld ", ans[i] + 1);
	}
	printf("\n");

	return 0;
}