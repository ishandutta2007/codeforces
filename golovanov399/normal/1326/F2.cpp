#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

#define random_shuffle(...) shuffle(__VA_ARGS__, rng)
#define rand() rng()

#ifdef OLBOEB
	#define return std::cerr << __FUNCTION__ << "\n"; return
#endif  // OLBOEB

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

const int L = 18;
const int N = 1 << L;

long long dp_way[N][L];
long long ways[L + 1][N];

void wh_minus(long long* b, long long* e) {
	if (e == b + 1) {
		return;
	}
	long long *m = b + (e - b) / 2;
	wh_minus(b, m);
	wh_minus(m, e);
	while (m != e) {
		*m -= *b;
		++b, ++m;
	}
}

void wh_plus(long long* b, long long* e) {
	if (e == b + 1) {
		return;
	}
	long long *m = b + (e - b) / 2;
	wh_plus(b, m);
	wh_plus(m, e);
	while (m != e) {
		*m += *b;
		++b, ++m;
	}
}

long long dp[L + 1][N];
int posit = 0;
vector<int> current;

void mult_ways(int len) {
	current.push_back(len);
	for (int i = 0; i < N; ++i) {
		dp[posit + 1][i] = dp[posit][i] * ways[len][i];
	}
	++posit;
}

long long ans[N];

int getNum(const vector<int>& perm) {
	int res = 0;
	for (int x : perm) {
		res = ((res * 2 + 1) << (x - 1)) - 1;
	}
	return res;
}

ostream& operator <<(ostream& ostr, const vector<int>& v) {
	ostr << "(";
	for (int i = 0; i < (int)v.size(); ++i) {
		if (i) {
			ostr << ", ";
		}
		ostr << v[i];
	}
	return ostr << ")";
}

void rec(int rest, int cur, int n) {
	if (rest == 0) {
		// cerr << current << "\n";
		auto perm = current;
		sort(all(perm));
		long long res = 0;
		for (int i = 0; i < (1 << n); ++i) {
			res += (__builtin_parity(i) ? -1 : 1) * dp[posit][(1 << n) - 1 - i];
		}
		do {
			ans[getNum(perm)] += res; // dp[posit][(1 << n) - 1];
			// cerr << "ans" << perm << " += " << dp[posit][(1 << n) - 1] << "\n";
		} while (next_permutation(all(perm)));
		return;
	}
	cur = min(cur, rest);
	while (cur > 0) {
		mult_ways(cur);
		rec(rest - cur, cur, n);
		--cur;
		--posit;
		current.pop_back();
	}
}

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	int n = nxt();
	vector<string> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	for (int i = 0; i < n; ++i) {
		dp_way[1 << i][i] = 1;
	}
	const int nn = 1 << n;
	for (int mask = 1; mask < nn; ++mask) {
		for (int i = 0; i < n; ++i) {
			if (!(mask & (1 << i))) {
				continue;
			}
			for (int j = 0; j < n; ++j) {
				if (mask & (1 << j) || a[j][i] == '0') {
					continue;
				}
				dp_way[mask | (1 << j)][j] += dp_way[mask][i];
			}
			ways[__builtin_popcount(mask)][mask] += dp_way[mask][i];
		}
	}

	fill(dp[0], dp[0] + N, 1ll);
	for (int i = 1; i <= n; ++i) {
		wh_plus(ways[i], ways[i] + nn);
	}

	rec(n, n, n);
	for (int i = 0; i < nn / 4; ++i) {
		swap(ans[i], ans[(nn / 2 - 1) ^ i]);
	}
	wh_minus(ans, ans + nn / 2);
	for (int i = 0; i < nn / 4; ++i) {
		swap(ans[i], ans[(nn / 2 - 1) ^ i]);
	}
	for (int i = 0; i < nn / 2; ++i) {
		cout << ans[i] << " ";
	}
	cout << "\n";

	return 0;
}