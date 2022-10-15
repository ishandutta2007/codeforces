#include <algorithm>
#include <bitset>
#include <cassert>
#include <chrono>
#include <climits>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iostream>
#include <iomanip>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <sstream>
#include <tuple>
#include <vector>

using namespace std;
using namespace chrono;

#ifdef DEBUG
	#define LOCAL_INPUT_FILE
#else
	//~ #define USE_FILE_IO
#endif

#ifdef USE_FILE_IO
	#define INPUT_FILE "input.txt"
	#define OUTPUT_FILE "output.txt"
	#define cin ____cin
	#define cout ____cout
	ifstream cin(INPUT_FILE);
	ofstream cout(OUTPUT_FILE);
#else
	#ifdef LOCAL_INPUT_FILE
		#define cin ____cin
		ifstream cin("input.txt");
	#endif
#endif

const int infinity = (int)1e9 + 42;
const int64_t llInfinity = (int64_t)1e18 + 256;
const int mod = 998244353; 
const long double eps = 1e-8;

mt19937_64 randGen(system_clock().now().time_since_epoch().count());

inline void raiseError(string errorCode) {
	cerr << "Error : " << errorCode << endl;
	exit(42);
}

const int sparseDepth = 20;

class SparseTable {
private:
	int n;
	vector< vector<int> > a;
	vector<int> lg;
public:
	inline int rmq(int l, int r) {
		int w = lg[r - l + 1];
		return min(a[w][l], a[w][r - (1 << w) + 1]);
	}
	
	SparseTable(const vector<int> &v)
		: n(v.size()), a(sparseDepth, vector<int>(n)), lg(n+1) {
		lg[1] = 0;
		for (int i = 2; i <= n; i++) {
			lg[i] = lg[i/2] + 1;
		}
		for (int i = 0; i < n; i++) {
			a[0][i] = v[i];
		}
		for (int i = 1; i < sparseDepth; i++) {
			for (int j = 0; j <= n - (1 << i); j++) {
				a[i][j] = min(a[i-1][j], a[i-1][j + (1 << (i-1))]);
			}
		}
	}
};

inline int64_t findAns(const vector<int> &a) {
	int n = a.size();
	assert(n <= 500);
	static int64_t dp[501][501] = {};
	for (int i = 1; i <= n; ++i) {
		dp[i][i-1] = 1;
	}
	for (int i = 0; i < n; ++i) {
		dp[i][i] = 1;
	}
	for (int l = n-1; l >= 0; --l) {
		for (int r = l+1; r < n; ++r) {
			dp[l][r] = 0;
			int mn = l;
			for (int k = l; k <= r; ++k) {
				if (a[k] < a[mn]) {
					mn = k;
				}
				int64_t q = (mn == 0) ? 1 : dp[l][mn-1];
				dp[l][r] += q * dp[mn+1][k] % mod * dp[k+1][r] % mod;
				dp[l][r] %= mod;
			}
		}
	}
	return dp[0][n-1];
}

inline void bad() {
	cout << 0 << endl;
	exit(0);
}

signed main() {
	#ifndef USE_FILE_IO
		ios_base::sync_with_stdio(false);
	#endif
	int n, m; cin >> n >> m;
	vector<int> a;
	for (int i = 0; i < m; ++i) {
		int v; cin >> v; --v;
		if (!a.empty() && v == a.back()) {
			continue;
		}
		a.push_back(v);
	}
	m = a.size();
	vector<int> le(n, INT_MAX), re(n, INT_MIN);
	for (int i = 0; i < m; ++i) {
		int v = a[i];
		le[v] = min(le[v], i);
		re[v] = max(re[v], i);
	}
	for (int i = 0; i < n; ++i) {
		assert(le[i] != INT_MAX);
	}
	SparseTable st(a);
	vector<int> last(n, m), nxt(m);
	for (int i = m-1; i >= 0; --i) {
		nxt[i] = last[a[i]];
		last[a[i]] = i;
	}
	
	function<int64_t(int, int, int)> calc = [&](int l, int r, int glue) {
		if (glue >= 0) {
			if (st.rmq(l, r) != glue) {
				bad();
			}
			if (le[glue] != l || re[glue] != r) {
				bad();
			}
			int64_t ans = 1;
			for (int i = l; i < r; i = nxt[i]) {
				ans *= calc(i+1, nxt[i]-1, -1);
				ans %= mod;
			}
			return ans;
		} else {
			vector<int> chk;
			int64_t ans = 1;
			for (int i = l; i <= r; ++i) {
				if (le[a[i]] == re[a[i]]) {
					assert(le[a[i]] == i);
					chk.push_back(a[i]);
					continue;
				}
				if (le[a[i]] != i || re[a[i]] > r) {
					bad();
				}
				int rr = re[a[i]];
				chk.push_back(a[i]);
				ans *= calc(i, rr, a[i]);
				ans %= mod;
				i = rr;
			}
			ans *= findAns(chk);
			ans %= mod;
			return ans;
		}
	};
	
	int64_t res = calc(0, m-1, -1);
	cout << res << endl;
	return 0;
}