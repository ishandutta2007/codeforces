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
	int n = nxt();
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		a[i] = nxt() - 1;
	}

	vector<long long> add_0(n + 1), add_1(n + 1);
	for (int i = 0; i < n; ++i) {
		if (a[i] >= i) {
			add_0[0] += a[i] - i;
			add_1[0] -= 1;
			add_1[a[i] - i] += 2;
			add_1[n - i] -= 2;
			add_0[n - i] += a[i] * 2 - n;
		} else {
			add_0[0] += i - a[i];
			add_1[0] += 1;
			add_1[n - i] -= 2;
			add_0[n - i] += 2 * a[i] - n;
			add_1[n - i + a[i]] += 2;
		}
	}

	pair<long long, int> ans = {100000000000000000ll, 0};
	long long cur_0 = 0;
	long long cur_1 = 0;
	for (int i = 0; i < n; ++i) {
		cur_0 += cur_1 + add_0[i];
		cur_1 += add_1[i];
		ans = min(ans, make_pair(cur_0, i));
	}

	cout << ans.first << " " << ans.second << "\n";

	return 0;
}