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

int main() {
	int n = nxt();
	vector<int> m(n);
	for (int i = 0; i < n; ++i) {
		m[i] = nxt();
	}

	vector<int> min_cnt(n);
	int cur = 0;
	for (int i = n - 1; i >= 0; --i) {
		cur -= 1;
		cur = max(cur, m[i] + 1);
		min_cnt[i] = cur;
	}
	for (int i = 1; i < n; ++i) {
		min_cnt[i] = max(min_cnt[i - 1], min_cnt[i]);
	}

	long long s = 0;
	for (int i = 0; i < n; ++i) {
		s += min_cnt[i] - 1 - m[i];
	}
	cout << s << "\n";

	return 0;
}