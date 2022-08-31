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

const int N = 1111111;
int g[N];

int f(int n) {
	int res = 1;
	while (n) {
		if (n % 10) {
			res *= n % 10;
		}
		n /= 10;
	}
	return res;
}

const int K = 10;
int sum[K][N];

int main() {
	for (int i = 1; i < N; ++i) {
		if (i < 10) {
			g[i] = i;
		} else {
			int j = f(i);
			assert(j < i);
			g[i] = g[j];
		}
	}

	for (int i = 1; i < N; ++i) {
		for (int j = 0; j < K; ++j) {
			sum[j][i] = sum[j][i - 1];
		}
		sum[g[i]][i] += 1;
	}

	int q = nxt();
	while (q--) {
		int l = nxt() - 1, r = nxt(), k = nxt();
		printf("%d\n", sum[k][r] -  sum[k][l]);
	}

	return 0;
}