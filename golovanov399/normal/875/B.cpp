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
	int n;
	vector<int> a;

	Fenwick(int _n) {
		n = _n;
		a.resize(n);
	}

	void add(int pos, int x = 1) {
		while (pos < n) {
			a[pos] += x;
			pos |= pos + 1;
		}
	}

	int get(int pos) {
		int res = 0;
		while (pos >= 0) {
			res += a[pos];
			pos = (pos & (pos + 1)) - 1;
		}
		return res;
	}
};

int main() {
	int n = nxt();
	Fenwick fenw(n);
	printf("%d ", 1);
	vector<char> used(n);
	int cur_rig = n - 1;
	for (int i = 0; i < n; ++i) {
		int x = nxt() - 1;
		fenw.add(x);
		used[x] = 1;

		while (cur_rig >= 0 && used[cur_rig]) {
			--cur_rig;
		}

		// int l = 0, r = i + 1 + cur_rig - n + 1;
		// while (r > l + 1) {
		// 	int m = (l + r) / 2;
		// 	if (fenw.get(cur_rig - m) <= m) {
		// 		r = m;
		// 	} else {
		// 		l = m;
		// 	}
		// }
		printf("%d ", cur_rig - n + 1 + i + 2);
	}
	printf("\n");

	return 0;
}