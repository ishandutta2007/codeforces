#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define rnd() (rand() << 15 | rand())
#define RND() ((long long)rnd() << 30 | rnd())
using namespace std;

typedef unsigned long long ull;

int n;
int vis[1000010], prime[1000010], tot;
ull val[1000010];
map <ull, int> all;

void GetPrime(int N) {
	for (int i = 2; i <= N; i++) {
		if (!vis[i]) prime[tot++] = i, val[i] = RND();
		for (int j = 0; j < tot && i * prime[j] <= N; j++) {
			vis[i * prime[j]] = 1, val[i * prime[j]] = val[i] ^ val[prime[j]];
			if (i % prime[j] == 0) break;
		}
	}
	for (int i = 1; i <= N; i++) {
		val[i] ^= val[i - 1];
	}
}

int main() {
	// srand((int)time(NULL));
	scanf("%d", &n);
	GetPrime(n);
	ull S = 0;
	for (int i = 1; i <= n; i++) {
		S ^= val[i];
	}
	if (S == 0) {
		printf("%d\n", n);
		for (int i = 1; i <= n; i++) {
			printf("%d ", i);
		}
		printf("\n");
		return 0;
	}
	for (int i = 1; i <= n; i++) {
		if (val[i] == S) {
			printf("%d\n", n - 1);
			for (int j = 1; j <= n; j++) {
				if (i == j) continue;
				printf("%d ", j);
			}
			printf("\n");
			return 0;
		}
	}
	for (int i = 1; i <= n; i++) {
		if (all.count(val[i] ^ S)) {
			int x = all[val[i] ^ S], y = i;
			printf("%d\n", n - 2);
			for (int j = 1; j <= n; j++) {
				if (j == x || j == y) continue;
				printf("%d ", j);
			}
			printf("\n");
			return 0;
		}
		all[val[i]] = i;
	}
	if (n == 1) {
		printf("1\n1\n");
		return 0;
	}
	if (n & 1) n--;
	if (n % 2 == 0) {
		int k = n / 2;
		if (k % 2 == 0) {
			printf("%d\n", n - 1);
			for (int i = 1; i <= n; i++) {
				if (i == k) continue;
				printf("%d ", i);
			}
			printf("\n");
		} else {
			printf("%d\n", n - 2);
			for (int i = 1; i <= n; i++) {
				if (i == 2 || i == k) continue;
				printf("%d ", i);
			}
			printf("\n");
		}
	}
	return 0;
}