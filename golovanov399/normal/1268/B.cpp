#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

#define random_shuffle(...) shuffle(__VA_ARGS__, rng)
#define rand() rng()

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
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	long long cnt[2] = {0, 0};
	int n = nxt();
	for (int i = 0; i < n; ++i) {
		int x = nxt();
		cnt[0] += x / 2;
		cnt[1] += x / 2;
		cnt[i % 2] += x % 2;
	}
	cout << min(cnt[0], cnt[1]) << "\n";

	return 0;
}