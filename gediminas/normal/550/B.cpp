#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define EDEBUG
#if defined(LOCAL) && defined(EDEBUG)
#include "includes/debug.cpp"
#else
#define debug(...)
#define dbgarr(...)
#define dbgline
#endif

struct Bitmask {
	static unsigned lsb(unsigned mask) {
		return mask & (-mask);
	}
	static inline int lsbpos(unsigned mask) {
		// 0 -> -1, 1 -> 0, 10 -> 1
		return __builtin_ffs(mask) - 1;
	}
	static inline int size(unsigned mask) {
		return __builtin_popcount(mask);
	}
	static unsigned add(unsigned mask, int p) {
		return mask | (1 << p);
	}
	static unsigned rem(unsigned mask, int p) {
		return mask & (~(1 << p));
	}
	static unsigned flip(unsigned mask, int p) {
		return mask ^ (1 << p);
	}
	static unsigned end(int n) {
		return (1 << n);
	}
	static unsigned all(int n) {
		return (1 << n) - 1;
	}
	static bool has(unsigned mask, int p) {
		return mask & (1 << p);
	}
	static bool issub(unsigned mask, unsigned sub) {
		return sub == (mask & sub);
	}
	static bitset<32> bs(unsigned mask, int p) {
		return mask & (1 << p);
	}
	struct It {
		unsigned mask;
		It(unsigned mask): mask(mask) {}
		It &operator++() {
			mask = mask ^ lsb(mask);
			return *this;
		}
		unsigned operator*() const {
			return lsbpos(mask);
		}
		friend bool operator!=(const It &a, const It &b) {
			return a.mask != b.mask;
		}
		It begin() {
			return It(mask);
		}
		It end() {
			return It(0);
		}
	};
	struct Subs {
		unsigned mask, cur;
		Subs(unsigned mask): mask(mask), cur(mask) {}
		Subs(unsigned mask, unsigned c): mask(mask), cur(c) {}
		Subs &operator++() {
			cur = mask & (cur - 1);
			return *this;
		}
		unsigned operator*() const {
			return cur;
		}
		friend bool operator!=(const Subs &a, const Subs &b) {
			return a.mask != b.mask || a.cur != b.cur;
		}
		Subs begin() {
			return Subs(mask);
		}
		Subs end() {
			return Subs(mask, 0);
		}
	};
	struct All {
		int n;
		unsigned mask;
		All(int n): n(n), mask(0) {}
		All(int n, unsigned mask): n(n), mask(mask) {}
		All &operator++() {
			mask++;
			return *this;
		}
		unsigned operator*() const {
			return mask;
		}
		friend bool operator!=(const All &a, const All &b) {
			return a.mask != b.mask || a.n != b.n;
		}
		All begin() {
			return *this;
		}
		All end() {
			return All(n, (1 << n));
		}
	};
};

/*input
3 5 6 1
1 2 3
*/
/*input
4 40 50 10
10 20 30 25
*/
/*input
5 25 35 10
10 10 20 10 20
*/

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	int n, l, r, x;
	cin >> n >> l >> r >> x;
	int a[n];

	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	int ans = 0;

	for (unsigned mask : Bitmask::All(n, 1)) {
		int tot = 0;
		int mi = a[Bitmask::lsbpos(mask)];
		int ma = mi;

		for (int v : Bitmask::It(mask)) {
			tot += a[v];
			mi = min(mi, a[v]);
			ma = max(ma, a[v]);
		}

		if (tot < l or tot > r or ma - mi < x) {
			continue;
		}

		ans++;
	}

	cout << ans;
}