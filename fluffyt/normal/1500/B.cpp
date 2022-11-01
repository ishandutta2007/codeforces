#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
 
const int MAXN = 500005;
void exgcd(LL &x,LL &y,LL a,LL b) {
    if (!b) {
        x = 1;
        y = 0;
        return;
    }
    exgcd(x, y, b, a % b);
    int t = x;
    x = y;
    y = t - a / b * y;
}
int a[MAXN], b[MAXN], mp[MAXN << 1], n, m;
LL k, arr[MAXN];

int main() {
	scanf("%d%d%lld", &n, &m, &k);
	for (int i = 0; i < n; i++) scanf("%d", a + i);
	memset(mp, -1, sizeof(mp));
	for (int i = 0; i < m; i++) scanf("%d", b + i), mp[b[i]] = i;
	int g = __gcd(n, m), c = 0;
	LL x, y, lcm = (LL)n * m / g;
	exgcd(x, y, n, m);
	for (int i = 0; i < n; i++) {
		if (mp[a[i]] < 0 || (i - mp[a[i]]) % g) continue;
		LL k = -x * (i - mp[a[i]]) / g % lcm;
		LL f = (k * n + i) % lcm;
		if (f < 0) f += lcm;
		arr[++c] = f + 1;
	}
	sort(arr + 1, arr + 1 + c);
	c = unique(arr + 1, arr + 1 + c) - arr - 1;
	LL cy = (k - 1) / (lcm - c);
	k -= cy * (lcm - c);
	LL ans = cy * lcm;
	int flag = 0;
	for (int i = 1; i <= c; i++) {
		if (arr[i] - i >= k) {
			flag = 1;
			ans += k + i - 1;
			break;
		}
	}
	if (!flag) ans += k + c;
	printf("%lld\n", ans);
	return 0;
}