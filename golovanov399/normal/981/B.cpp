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
	map<int, pair<int, int>> M;
	{
		int n = nxt();
		for (int i = 0; i < n; ++i) {
			int a = nxt(), x = nxt();
			M[a].first = x;
		}
	}
	{
		int n = nxt();
		for (int i = 0; i < n; ++i) {
			int a = nxt(), x = nxt();
			M[a].second = x;
		}
	}

	long long ans = 0;
	for (const auto& [a, p] : M) {
		ans += max(p.first, p.second);
	}

	printf("%lld\n", ans);

	return 0;
}