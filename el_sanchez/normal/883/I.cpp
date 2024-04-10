#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <utility>
#include <cstdlib>
#include <memory>
#include <queue>
#include <cassert>
#include <cmath>
#include <ctime>
#include <complex>
#include <bitset>
#include <fstream>
#include <unordered_map>
#include <unordered_set>
#include <numeric>

using namespace std;

#define ws ws_____________________
#define y1 y1_____________________
#define y0 y0_____________________
#define left left_________________
#define right right_______________
#define next next_________________
#define prev prev_________________
#define hash hash_________________

#define pb push_back
#define fst first
#define snd second
#define mp make_pair 
#define sz(C) ((int) (C).size())
#define forn(i, n) for (int i = 0; i < int(n); ++i)
#define ford(i, n) for (int i = int(n) - 1; i >= 0; --i)
#define all(C) begin(C), end(C)

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vii;
typedef long double ld;
typedef complex<double> cd;

#ifdef LOCAL
#define eprintf(args...) fprintf(stderr, args), fflush(stderr)
#else
#define eprintf(...) ;
#endif

#define FILE_NAME "a"

int n, k;
vi a;

bool read() {
	if  (scanf("%d%d", &n, &k) < 2) {
		return 0;
	}
	a.resize(n);
	forn(i, n) {
		scanf("%d", &a[i]);
	}
	sort(all(a));
	return 1;
}

bool can(int D) {
	assert(D >= 0);

	vi dp(n);
	deque<int> q;
	
	int l = 0;
	forn(i, n) {
		while (a[i] - a[l] > D) {
			++l;
		}

		const int max_j = i - k;
		if  (max_j >= 0 && dp[max_j]) {
			// eprintf("push max_j=%d\n", max_j);
			q.push_back(max_j);
		}

		assert(l <= i);

		if  ((!q.empty() && q.back() >= l - 1) || (l == 0 && i - l + 1 >= k)) {
			dp[i] = 1;
		}

		// if  ((!q.empty() && q.back() >= l - 1) || l == 0) {
		// 	dp[i] = 1;
		// }

		// eprintf("i=%d, l=%d, dp=%d\n", i, l, dp[i]);
	}

	return dp[n - 1];
}

int solve() {
	// can(170);
	// return -1;

	int L = -1;
	int R = 1e9 + 10;
	while (L != R - 1) {
		int M = (L + R) >> 1;
		if  (can(M)) {
			R = M;
		} else {
			L = M;
		}
	}
	return R;
}

int main() {
#ifdef LOCAL
	freopen(FILE_NAME ".in", "r", stdin);
	// freopen(FILE_NAME ".out", "w", stdout);
#endif

	while (read()) {
		printf("%d\n", solve());

		// break;
	}

#ifdef LOCAL
	cerr.precision(5);
	cerr << "Time: " << fixed << (double) clock() / CLOCKS_PER_SEC << endl;
#endif
	return 0;
}