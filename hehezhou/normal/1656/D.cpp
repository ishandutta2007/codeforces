#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int T;
ll n;
int prime[100010], cnt, np[100010];
ll sum(ll x) {
	return x * (x + 1) / 2;
}
void rmain() {
	scanf("%lld", &n);
	for (ll x = 2; sum(x) <= n; x <<= 1) {
		if ((n - sum(x)) % x == 0) {
			printf("%lld\n", x);
			return;
		}
	}
	ll chk = n;
	while (chk % 2 == 0) chk /= 2;
	for (int i = 1; prime[i] * prime[i] <= chk; i++) if (chk % prime[i] == 0) {
		if (sum(prime[i]) <= n) printf("%d\n", prime[i]);
		else puts("-1");
		return;
	}
	if (chk != 1 && sum(chk) <= n) printf("%lld\n", chk);
	else puts("-1");
}
int main() {
	for (int i = 2; i <= 100000; i++) {
		if (!np[i]) prime[++cnt] = i;
		for (int j = 1; prime[j] * i <= 100000; j++) {
			np[i * prime[j]] = 1;
			if (i % prime[j] == 0) break;
		}
	}
	scanf("%d", &T);
	while (T--) rmain();
}