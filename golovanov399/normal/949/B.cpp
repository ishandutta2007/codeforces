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
	scanf("%d", &x);
	return x;
}

long long bitrev(long long a, int len) {
	long long res = 0;
	for (int i = 0; i < len; ++i) {
		res = (res << 1) | (a & 1ll);
		a >>= 1;
	}
	return res;
}

vector<int> f(int n) {
	vector<int> a;
	for (int i = 0; i < n; ++i) {
		a.push_back(i + 1);
		a.push_back(0);
	}
	while ((int)a.size() > n) {
		int v = a.back();
		a.pop_back();
		if (v == 0) {
			continue;
		}
		int i = (int)a.size() - 1;
		while (a[i]) {
			--i;
		}
		a[i] = v;
	}
	return a;
}

long long g(long long len, long long pos) {
	if (len == 1ll) {
		return 0;
	} else if (pos % 2) {
		return len / 2 + pos / 2;
	} else {
		return g(len / 2, pos / 2);
	}
}

int main() {
	long long n;
	// cin >> n;
	int q;
	scanf("%lld%d", &n, &q);
	
	long long len = 1;
	while (len * 2 <= n) {
		len *= 2;
	}

	// auto fn = f(n);
	// vector<int> gn;

	while (q--) {
	// for (long long i = 0; i < n; ++i) {
		long long pos;
		scanf("%lld", &pos);
		// pos = i + 1;

		if (pos <= 2 * (n - len)) {
			if (pos % 2 == 1) {
				printf("%lld\n", pos / 2 + 1);
				// gn.push_back(pos / 2 + 1);
			} else {
				printf("%lld\n", n - g(len, n - len - pos / 2));
				// gn.push_back(n - g(len, n - len - pos / 2));
			}
			continue;
		}
		printf("%lld\n", n - g(len, n + (n - len) - pos));
		// gn.push_back(n - g(len, n + (n - len) - pos));
	}
	// for (int i = 0; i < n; ++i) {
	// 	cerr << fn[i] << " ";
	// }
	// cerr << "\n";
	// for (int i = 0; i < n; ++i) {
	// 	cerr << gn[i] << " ";
	// }
	// cerr << "\n";
	// assert(fn == gn);

	return 0;
}