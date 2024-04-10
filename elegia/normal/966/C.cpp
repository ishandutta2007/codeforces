#include <cstdio>

#include <queue>

using namespace std;

typedef long long ll;

const int N = 100010;

int n, cnt;
ll ans[N];

queue<ll> q[60];

int main() {
	scanf("%d", &n);
	for (int rep = 0; rep < n; ++rep) {
		ll x;
		scanf("%lld", &x);
		for (int j = 59; j >= 0; --j)
			if ((x >> j) & 1) {
				q[j].push(x);
				break;
			}
	}
	ll cur = 0;
	for (int rep = 0; rep < n; ++rep) {
		for (int j = 0; j < 60; ++j)
			if (!q[j].empty() && (cur ^ q[j].front()) > cur) {
				ans[++cnt] = q[j].front();
				q[j].pop();
				cur ^= ans[cnt];
				break;
			}
	}
	if (cnt < n) {
		puts("No");
		return 0;
	}
	puts("Yes");
	for (int i = 1; i <= n; ++i)
		printf("%lld ", ans[i]);
	return 0;
}