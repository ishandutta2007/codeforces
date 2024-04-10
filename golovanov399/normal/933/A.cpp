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
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		a[i] = nxt();
	}

	vector<int> num_ones(n + 1), num_twos(n + 1);
	for (int i = 0; i < n; ++i) {
		num_ones[i + 1] = num_ones[i];
		num_twos[i + 1] = num_twos[i];
		if (a[i] == 1) {
			num_ones[i + 1] += 1;
		} else {
			num_twos[i + 1] += 1;
		}
	}

	int ans = 0;
	for (int i = 0; i <= n; ++i) {
		ans = max(ans, num_ones[i] + num_twos[n] - num_twos[i]);
	}

	for (int r = 0; r < n; ++r) {
		int cur = 0;
		for (int l = r; l >= 0; --l) {
			if (a[l] == 2)  {
				cur += 1;
			}
			cur = max(cur, num_ones[r + 1] - num_ones[l]);
			ans = max(ans, cur + num_ones[l] + num_twos[n] - num_twos[r + 1]);
		}
	}

	cout << ans << "\n";

	return 0;
}