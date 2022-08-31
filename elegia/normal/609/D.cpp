#include <cstdio>

#include <algorithm>
#include <numeric>

using namespace std;

typedef long long ll;

const int N = 200010;

int n, m, k, s;

int nd[N], np[N], t[N], c[N];
ll v[N];
pair<ll, int> vv[N];

bool pred(int n);

int main() {
	scanf("%d%d%d%d", &n, &m, &k, &s);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &nd[i]);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &np[i]);
	for (int i = 1; i <= m; ++i)
		scanf("%d%d", &t[i], &c[i]);
	int l = 1, r = n;
	if (!pred(n)) {
		puts("-1");
		return 0;
	}
	while (l < r) {
		int mid = (l + r) >> 1;
		if (pred(mid))
			r = mid;
		else
			l = mid + 1;
	}
	printf("%d\n", r);
	int dp = min_element(nd + 1, nd + r + 1) - nd, pp = min_element(np + 1, np + r + 1) - np;
	for (int i = 1; i <= m; ++i)
		vv[i] = make_pair(c[i] * (ll)(t[i] == 1 ? nd[dp] : np[pp]), i);
	nth_element(vv + 1, vv + k, vv + m + 1);
	for (int i = 1; i <= k; ++i)
		printf("%d %d\n", vv[i].second, t[vv[i].second] == 1 ? dp : pp);
	return 0;
}

bool pred(int n) {
	int d = *min_element(nd + 1, nd + n + 1), p = *min_element(np + 1, np + n + 1);
	for (int i = 1; i <= m; ++i)
		v[i] = c[i] * (ll)(t[i] == 1 ? d : p);
	nth_element(v + 1, v + k, v + m + 1);
	return accumulate(v + 1, v + k + 1, 0LL) <= s;
}