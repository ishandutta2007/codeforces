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

int f, T, t0;
int a1, t1, p1;
int a2, t2, p2;

bool read() {
	if  (scanf("%d%d%d", &f, &T, &t0) < 3) {
		return 0;
	}
	scanf("%d%d%d", &a1, &t1, &p1);
	scanf("%d%d%d", &a2, &t2, &p2);
	return 1;
}

const ll INF = 1e18;

ll go(int T, int f) {
	// eprintf("go T=%d, f=%d\n", T, f);

	if  (T / t0 >= f) {
		return 0;
	}

	ll ans = INF;

	{
		ll c2 = (T + 1ll * a2 * t2 - 1) / (1ll * a2 * t2);
		ll got = T / t2;
		if  (got >= f) {
			// eprintf("got=%lld, c2=%lld\n", got, c2);
			ans = min(ans, 1ll * c2 * p2);
		}
	}

	ll A = 1ll * a2 * t0 - 1ll * a2 * t2;
	ll B = 1ll * f * t0 - T;
	
	if  (A <= 0) { // t2 >= t0
		return ans;
	}

	ll c2 = (B + A - 1) / A;
	if  (c2 * a2 * t2 > T) {
		return ans;
	}

	ll got = c2 * a2;
	got += (T - c2 * a2 * t2) / t0;

	// eprintf("got=%lld, c2=%lld\n", got, c2);
	if  (got >= f) {
		return min(ans, 1ll * p2 * c2);
	}

	return ans;
}

ll go(int c1) {
	if  (1ll * c1 * t1 * a1 >= T) {
		ll got = T / t1;
		if  (got >= f) {
			return 1ll * p1 * c1;
		} else {
			return INF;
		}
	}

	ll cur = go(T - c1 * t1 * a1, f - c1 * a1);
	if  (cur >= INF) {
		return INF;
	}
	cur += 1ll * p1 * c1;
	return cur;
}

ll solve() {
	ll ans = INF;

	forn(it, 2) {
		forn(c1, f / a1 + 1) {
			ans = min(ans, go(c1));
		}
	
		swap(a1, a2);
		swap(t1, t2);
		swap(p1, p2);
	}

	if  (ans >= INF) {
		return -1;
	}
	return ans;
}

int main() {
#ifdef LOCAL
	freopen(FILE_NAME ".in", "r", stdin);
	// freopen(FILE_NAME ".out", "w", stdout);
#endif

	while (read()) {
		printf("%lld\n", solve());

		// break;
	}

#ifdef LOCAL
	cerr.precision(5);
	cerr << "Time: " << fixed << (double) clock() / CLOCKS_PER_SEC << endl;
#endif
	return 0;
}