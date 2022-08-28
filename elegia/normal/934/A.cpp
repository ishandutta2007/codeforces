#include <cstdio>

#include <algorithm>

typedef long long ll;

const int N = 52;

ll max;
int n, m, maxid;
int a[N], b[N];

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i)
		scanf("%d", &a[i]);
	for (int i = 0; i < m; ++i)
		scanf("%d", &b[i]);
	std::pair<int*, int*> pair = std::minmax_element(b, b + m);
	max = std::max((ll)a[0] * *pair.first, (ll)a[0] * *pair.second);
	for (int i = 1; i < n; ++i) {
		ll res = std::max((ll)a[i] * *pair.first, (ll)a[i] * *pair.second);
		if (res > max) {
			max = res;
			maxid = i;
		}
	}
	max = -(1LL << 60);
	for (int i = 0; i < n; ++i)
		if (i != maxid)
			max = std::max(max, std::max((ll)a[i] * *pair.first, (ll)a[i] * *pair.second));
	printf("%lld\n", max);
	return 0;
}