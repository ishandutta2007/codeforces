#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int MAXN = 5005;
int S[MAXN], n, T;
LL f[MAXN];

int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) scanf("%d", S + i);
		LL ans = 0;
		memset(f, 0, sizeof(f));
		for (int i = 1; i <= n; i++) {
			if (f[i] < S[i] - 1) ans += S[i] - 1 - f[i], f[i] = S[i] - 1;
			for (int j = min(i + S[i], n); j > i + 1; j--) ++f[j];
			f[i + 1] += f[i] - (S[i] - 1);
		}
		printf("%lld\n", ans);
	}
	return 0;
}