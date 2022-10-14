#include <algorithm>
#include <cstdio>
#include <climits>
#include <utility>

const int N = 100000;
const int M = 4 * N + 2;

using Pair = std::pair<int, int>;

int n;
Pair p[M], s[M];

void upd(Pair& x, const Pair& a)
{
	x.first = std::min(x.first, a.first);
	x.second = std::max(x.second, a.second);
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < M; ++ i) {
		p[i] = s[i] = {INT_MAX, INT_MIN};
	}
	for (int i = 0, x, y; i < n; ++ i) {
		scanf("%d%d", &x, &y);
		auto d = x - y;
		upd(p[x + y + N + N], std::make_pair(d, d));
	}
	for (int i = M - 1; i >= 0; -- i) {
		s[i] = p[i];
		if (i + 2 < M) {
			upd(s[i], s[i + 2]);
		}
	}
	for (int i = 2; i < M; ++ i) {
		upd(p[i], p[i - 2]);
	}
	long long result = 0;
	for (int i = 1; i < M - 1; ++ i) {
		int mi = std::max(p[i - 1].first, s[i + 1].first);
		int ma = std::min(p[i - 1].second, s[i + 1].second);
		if (mi <= ma) {
			result += (ma - mi) >> 1;
		}
	}
	printf("%lld\n", result);
}