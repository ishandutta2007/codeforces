#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()

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

int main() {
	int n = nxt(), k = nxt();
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		a[i] = nxt();
	}

	vector<pair<int, int>> p(n);
	for (int i = 0; i < n; ++i) {
		p[i] = {a[i], i};
	}

	sort(all(p));
	vector<int> which(n + k, -1);
	int cur = k;
	reverse(all(p));
	for (int i = 0; i < n; ++i) {
		int idx = p[i].second;
		if (idx <= cur) {
			idx = cur;
		}
		while (which[idx] != -1) {
			++idx;
		}
		which[idx] = p[i].second;
		while (cur < k + n && which[cur] > -1) {
			++cur;
		}
	}

	long long ans = 0;
	vector<int> res(n);
	for (int i = 0; i < n; ++i) {
		int idx = which[k + i];
		assert(idx <= k + i);
		ans += 1ll * a[idx] * (k + i - idx);
		res[idx] = k + i;
	}
	printf("%lld\n", ans);
	for (int x : res) {
		printf("%d ", x + 1);
	}
	printf("\n");

	return 0;
}