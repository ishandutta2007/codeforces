#pragma GCC target ("mmx,sse,sse2")
#pragma GCC optimize (3)
#include "immintrin.h"
#include <bits/stdc++.h>
using namespace std;

typedef __m128i mi;
#define M(x) _mm_##x##_si128
#define M16(x) _mm_##x##_epi16
#define M32(x) _mm_##x##_epi32

#define rep(i, from, to) for (int i = from; i < int(to); ++i)
#define trav(a, x) for (auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct Counter {
	int N;
	short *xs, *ys, *ups;
	Counter() : N(0) {
		xs = (short*)_mm_malloc(200000, 32);
		ys = (short*)_mm_malloc(200000, 32);
		ups = (short*)_mm_malloc(200000, 32);
	}
	void insert(short x, short y, short len) {
		xs[N] = x;
		ys[N] = y;
		ups[N] = x + y + len;
		N++;
	}
	int count(short x, short y) {
		mi mx = M16(set1)(x);
		mi my = M16(set1)(y);
		mi msum = M16(set1)(x + y);
		int ans = 0;
		int i = 0;
		mi* mxs = (mi*)xs;
		mi* mys = (mi*)ys;
		mi* mups = (mi*)ups;
		int j = 0;
		int res = N;
		mi mres = M16(set1)(0);
		while (i + 8 <= N) {
			mi fails = M(or)(
				M(or)(
					M16(cmplt)(my, mys[j]),
					M16(cmplt)(mx, mxs[j])
				),
				M16(cmplt)(mups[j], msum)
			);
			mres = M16(add)(mres, fails);
			i += 8;
			j++;
		}

		union { unsigned short v[8]; mi m;} u; u.m = mres;
		rep(i,0,8)
			res -= (int)(unsigned short)-u.v[i];

		while (i < N) {
			if (!(ys[i] <= y && xs[i] <= x && x + y <= ups[i]))
				res--;
			++i;
		}
		return res;
	}
};

int main() {
	cin.sync_with_stdio(false);
	int N, Q;
	cin >> N >> Q;
	Counter d1, d2, d3, d4;
	rep(qi,0,Q) {
		short type;
		cin >> type;
		if (type == 1) {
			short dir, x, y, len;
			cin >> dir >> x >> y >> len;
#ifdef BENCH
			rep(ti,0,10000) {
#endif
			if (dir == 1) d1.insert((short)x, (short)y, len);
			if (dir == 2) d2.insert((short)x, (short)-y, len);
			if (dir == 3) d3.insert((short)-x, (short)y, len);
			if (dir == 4) d4.insert((short)-x, (short)-y, len);
#ifdef BENCH
			}
#endif
		}
		else {
			assert(type == 2);
			short x, y;
			cin >> x >> y;
			int ans = 0;
#ifdef BENCH
			rep(ti,0,10000) {
#endif
			ans += d1.count((short)x, (short)y);
			ans += d2.count((short)x, (short)-y);
			ans += d3.count((short)-x, (short)y);
			ans += d4.count((short)-x, (short)-y);
#ifdef BENCH
			}
#endif
			cout << ans << '\n';
		}
	}
}