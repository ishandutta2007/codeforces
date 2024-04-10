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

struct Fenwick {
	itn n;
	vector<int> a;

	Fenwick(int _n): n(_n) {
		a.resize(n);
	}

	int get(int pos) {
		int res = 0;
		while (pos >= 0) {
			res = max(res, a[pos]);
			pos = (pos & (pos + 1)) - 1;
		}
		return res;
	}

	void add(int pos, int x) {
		while (pos < n) {
			a[pos] = max(a[pos], x);
			pos |= pos + 1;
		}
	}
};

int main() {
	int n = nxt(), m = nxt();
	vector<int> ar(m + 1);
	for (int i = 0; i < n; ++i) {
		ar[nxt() - 1] += 1;
		ar[nxt()] -= 1;
	}

	for (int i = 1; i <= m; ++i) {
		ar[i] += ar[i - 1];
	}

	vector<int> chrono(m);
	iota(all(chrono), 0);
	sort(all(chrono), [&](int x, int y) {
		return make_pair(ar[x], x) < make_pair(ar[y], y);
	});

	Fenwick pref(m), suf(m);
	vector<int> left(m), right(m);

	for (int idx : chrono) {
		left[idx] = pref.get(idx - 1) + 1;
		pref.add(idx, left[idx]);
	}

	sort(all(chrono), [&](int x, int y) {
		return make_pair(ar[x], -x) < make_pair(ar[y], -y);
	});
	for (int idx : chrono) {
		right[idx] = suf.get(m - 1 - idx - 1) + 1;
		suf.add(m - 1 - idx, right[idx]);
	}

	int ans = 0;
	for (int i = 0; i < m; ++i) {
		ans = max(ans, left[i] + right[i] - 1);
	}

	printf("%d\n", ans);

	return 0;
}