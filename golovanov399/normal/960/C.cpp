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
	int x = nxt(), d = nxt();
	long long cur = 1;
	vector<long long> ans;
	while (x) {
		int b = 1;
		while ((1ll << (b + 1)) - 1 <= x) {
			b += 1;
		}
		x -= ((1 << b) - 1);
		while (b--) {
			ans.push_back(cur);
		}
		cur += d;
	}
	cout << ans.size() << "\n";
	for (auto x : ans) {
		cout << x << " ";
	}
	cout << "\n";

	return 0;
}