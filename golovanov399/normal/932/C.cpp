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
	int n = nxt(), a = nxt(), b = nxt();
	int num_a = 0;
	while (num_a * a <= n && (n - num_a * a) % b) {
		++num_a;
	}
	if (num_a * a > n) {
		puts("-1");
		return 0;
	}
	int num_b = (n - num_a * a) / b;

	int cur = 1;
	while (num_a--) {
		for (int i = 0; i < a - 1; ++i) {
			printf("%d ", cur + i + 1);
		}
		printf("%d ", cur);
		cur += a;
	}
	while (num_b--) {
		for (int i = 0; i < b - 1; ++i) {
			printf("%d ", cur + i + 1);
		}
		printf("%d ", cur);
		cur += b;
	}

	printf("\n");

	return 0;
}