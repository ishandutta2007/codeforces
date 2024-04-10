#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

typedef pair <int, int> pii;

int minp[1000010], prime[1000010], tot, vis[1000010];
vector <pii> fac;
int ans[1000010];

int gcd(int a, int b) {
	return !b ? a : gcd(b, a % b);
}

void get_prime(int n) {
	for (int i = 2; i <= n; i++) {
		if (!vis[i]) prime[tot++] = i, minp[i] = i;
		for (int j = 0; j < tot && i * prime[j] <= n; j++) {
			vis[i * prime[j]] = 1, minp[i * prime[j]] = prime[j];
			if (i % prime[j] == 0) break;
		}
	}
}

int main () {
	get_prime(1000000);
	int n = 1000000, cnt = 0;
	memset(vis, 0, sizeof(vis));
	int cur = 0;
	ans[1] = 1;
	for (int i = 2; i <= n; i++) {
		ans[i] = ans[i - 1] + 1;
		if (i != minp[i]) ans[i]--;
		while (cur < tot && 1ll * prime[cur] * prime[cur] <= i) ans[i]--, cur++;
	}
	int T; scanf("%d", &T);
	while (T--) {
		int x; scanf("%d", &x);
		printf("%d\n", ans[x]);
	}
	return 0;
}