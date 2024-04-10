#include <cstdio>

#include <algorithm>
#include <functional>

using namespace std;

typedef long long ll;

struct Node {
	ll x, y;

	bool operator>(const Node& rhs) const {
		return x - y > rhs.x - rhs.y;
	}
};

const int N = 200010;

int n, a, b;
ll sum;
Node p[N];

int main() {
	scanf("%d%d%d", &n, &a, &b);
	for (int i = 1; i <= n; ++i)
		scanf("%lld%lld", &p[i].x, &p[i].y);
	sort(p + 1, p + n + 1, greater<Node>());
	b = min(b, n);
	for (int i = 1; i <= n; ++i)
		sum += p[i].y;
	ll c0 = 0, c1 = 0;
	if (b == 0) {
		printf("%lld\n", sum);
		return 0;
	}
	ll ans = sum;
	for (int i = 1; i < b; ++i)
		c0 += max(p[i].x - p[i].y, 0LL);
	c1 = c0 + max(p[b].x - p[b].y, 0LL);
	for (int i = 1; i <= b; ++i)
		ans = max(ans, sum + c1 - max(p[i].x - p[i].y, 0LL) + max(p[i].x * (1LL << a) - p[i].y, 0LL));
	for (int i = b + 1; i <= n; ++i)
		ans = max(ans, sum + c0 + max(p[i].x * (1LL << a) - p[i].y, 0LL));
	printf("%lld\n", ans);
	return 0;
}