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

const int MAXN = 4e5 + 10;
const int A = 26 + 26 + 10;

int code(char c) {
	if  ('a' <= c && c <= 'z') {
		return c - 'a';
	}
	if  ('A' <= c && c <= 'Z') {
		return 26 + (c - 'A');
	}
	assert('0' <= c && c <= '9');
	return 26 * 2 + (c - '0');
}

char decode(int c) {
	if  (c < 26) {
		return 'a' + c;
	}
	c -= 26;
	if  (c < 26) {
		return 'A' + c;
	}
	c -= 26;
	assert(c < 10);
	return '0' + c;
}

int n;
vi cnt;

bool read() {
	if  (scanf("%d\n", &n) < 1) {
		return 0;
	}
	static char s[MAXN];
	scanf("%s\n", s);
	cnt.assign(A, 0);
	forn(i, n) {
		++cnt[code(s[i])];
	}
	return 1;
}

string restore(vi cnt) {
	int len = accumulate(all(cnt), 0);

	string res(len, '0');

	forn(c, A) {
		if  (cnt[c] & 1) {
			assert(len & 1);
			res[len / 2] = decode(c);
			--cnt[c];
		}
	}

	int l = 0;
	forn(c, A) {
		assert(cnt[c] % 2 == 0);
		while (cnt[c] > 0) {
			res[l] = decode(c);
			res[sz(res) - l - 1] = decode(c);
			++l;
			cnt[c] -= 2;
		}
	}

	return res;
}

bool go(vi cnt, int len, vector<string>& res) {
	vvi cnts(n / len, vi(A, 0));

	if  (len & 1) {
		int ptr = 0;
		forn(c, A) {
			if  (cnt[c] & 1) {
				if  (ptr >= sz(cnts)) {
					return 0;
				}
				++cnts[ptr][c];
				--cnt[c];
				++ptr;
			}
		}

		forn(c, A) {
			if  (cnt[c] & 1) {
				return 0;
			}
		}

		int rest = sz(cnts) - ptr;
		if  (rest % 2 != 0) {
			return 0;
		}

		forn(c, A) {
			assert(cnt[c] % 2 == 0);
			while (cnt[c] > 0 && ptr < sz(cnts)) {
				++cnts[ptr][c];
				++ptr;
				++cnts[ptr][c];
				++ptr;
				assert(ptr <= sz(cnts));
				cnt[c] -= 2;
			}
		}
	}

	forn(c, A) {
		if  (cnt[c] & 1) {
			return 0;
		}
	}

	int c = 0;
	forn(i, sz(cnts)) {
		int got = 0;
		forn(cc, A) {
			got += cnts[i][cc];
		}
		while (got < len) {
			while (!cnt[c]) {
				++c;
			}
			assert(c < A);
			cnts[i][c] += 2;
			got += 2;
			cnt[c] -= 2;
		}
	}

	res.resize(sz(cnts));
	forn(i, sz(cnts)) {
		res[i] = restore(cnts[i]);
	}

	return 1;
}

void solve() {
	for (int k = 1; k <= n; ++k) {
		if  (n % k == 0) {
			vector<string> res;
			if  (go(cnt, n / k, res)) {
				printf("%d\n", k);
				assert(sz(res) == k);
				forn(i, sz(res)) {
					printf("%s ", res[i].data());
				}
				printf("\n");
				return;
			}
		} 
	}

	assert(0);
}

int main() {
#ifdef LOCAL
	freopen(FILE_NAME ".in", "r", stdin);
	// freopen(FILE_NAME ".out", "w", stdout);
#endif

	while (read()) {
		solve();
	}

#ifdef LOCAL
	cerr.precision(5);
	cerr << "Time: " << fixed << (double) clock() / CLOCKS_PER_SEC << endl;
#endif
	return 0;
}