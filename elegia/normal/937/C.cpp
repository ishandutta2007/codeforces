#include <cstdio>
#include <cmath>

#include <algorithm>

using namespace std;

typedef long long ll;

int main() {
	ll k, d, t, cycle, subTimes;
	ll ans = 0, velocity, t2;
	scanf("%lld%lld%lld", &k, &d, &t);
	k *= 2;
	d *= 2;
	t *= 2;
	subTimes = (k + d - 1) / d;
	cycle = subTimes * d;
	velocity = k + (cycle - k) / 2;
	ans = t / velocity * cycle;
	t2 = t - t / velocity * velocity;
//	fprintf(stderr, "%lld %lld %lld %lld %lld\n", cycle, subTimes, velocity, ans, t2);
	if (t2 <= k) {
		ans += t2;
	} else {
		ans += k + 2 * (t2 - k);
	}
//	fprintf(stderr, "%lld\n", ans);
	printf("%.1lf\n", ans / 2.);
	return 0;
}