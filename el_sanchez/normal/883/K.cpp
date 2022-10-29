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

int n;
vi s;
vi g;

bool read() {
	if  (scanf("%d", &n) < 1) {
		return 0;
	}
	s.resize(n);
	g.resize(n);
	forn(i, n) {
		scanf("%d%d", &s[i], &g[i]);
	}
	return 1;
}

const int INF = 1e9;

void remin(int& x, int y) {
	if  (x > y) {
		x = y;
	}
}

bool solve() {
	vi upper(n, INF);
	ford(i, n) {
		remin(upper[i], s[i] + g[i]);
		if  (i + 1 < n) {
			remin(upper[i], upper[i + 1] + 1);
		}
	}

	// forn(i, n) {
	// 	eprintf("i=%d, upper=%d\n", i, upper[i]);
	// }

	vi ans(n);
	forn(i, n) {
		if  (i > 0) {
			remin(upper[i], ans[i - 1] + 1);
		}
		// eprintf("i=%d, upper=%d\n", i, upper[i]);
		if  (s[i] > upper[i]) {
			return 0;
		}
		ans[i] = min(s[i] + g[i], upper[i]);
		// eprintf("i=%d, ans=%d\n", i, ans[i]);
		if  (ans[i] < s[i]) {
			return 0;
		}
	}

	forn(i, n - 1) {
		if  (abs(ans[i] - ans[i + 1]) > 1) {
			return 0;
		}
	}

	ll sum = 0;
	forn(i, n) {
		sum += ans[i] - s[i];
	}

	printf("%lld\n", sum);
	forn(i, n) {
		printf("%d ", ans[i]);
	}
	printf("\n");
	return 1;
}

int main() {
#ifdef LOCAL
	freopen(FILE_NAME ".in", "r", stdin);
	// freopen(FILE_NAME ".out", "w", stdout);
#endif

	while (read()) {
		if  (!solve()) {
			puts("-1");
		}
	}

#ifdef LOCAL
	cerr.precision(5);
	cerr << "Time: " << fixed << (double) clock() / CLOCKS_PER_SEC << endl;
#endif
	return 0;
}