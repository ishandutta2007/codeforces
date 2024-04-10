#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

#define random_shuffle(...) shuffle(__VA_ARGS__, rng)
#define rand() rng()

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

const int N = 444444;
int erat[N];

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	for (int i = 2; i < N; ++i) {
		if (erat[i] == 0) {
			erat[i] = i;
			if (1.0 * i * i < N + N) {
				for (int j = i * i; j < N; j += i) {
					if (erat[j] == 0) {
						erat[j] = i;
					}
				}
			}
		}
	}

	int n = nxt();
	int cnt[3] = {0, 0, 0};
	for (int i = 0; i < n; ++i) {
		cnt[nxt()] += 1;
	}

	if (cnt[1] == 0) {
		for (int i = 0; i < cnt[2]; ++i) {
			printf("2 ");
		}
		printf("\n");
	} else if (cnt[1] >= 3) {
		printf("1 1 1 ");
		cnt[1] -= 3;
		for (int i = 0; i < cnt[2]; ++i) {
			printf("2 ");
		}
		for (int i = 0; i < cnt[1]; ++i) {
			printf("1 ");
		}
		printf("\n");
	} else if (cnt[2] >= 1 && cnt[1] >= 1) {
		printf("2 1 ");
		cnt[1] -= 1;
		cnt[2] -= 1;
		for (int i = 0; i < cnt[2]; ++i) {
			printf("2 ");
		}
		for (int i = 0; i < cnt[1]; ++i) {
			printf("1 ");
		}
		printf("\n");
	} else {
		assert(cnt[2] == 0);
		for (int i = 0; i < cnt[1]; ++i) {
			printf("1 ");
		}
		printf("\n");
	}

	return 0;
}