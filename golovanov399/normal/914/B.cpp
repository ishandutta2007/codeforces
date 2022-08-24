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

const int N = 111111;
int cnt[N];

int main() {
	int n = nxt();
	while (n--) {
		cnt[nxt()] ^= 1;
	}

	for (int i = 0; i < N; ++i) {
		if (cnt[i]) {
			puts("Conan");
			return 0;
		}
	}

	puts("Agasa");

	return 0;
}