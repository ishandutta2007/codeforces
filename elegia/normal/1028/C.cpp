#include <cstdio>
#include <cstring>

#include <algorithm>
#include <limits>

using namespace std;

const int N = 200000;

int n;

int l[N], r[N], d[N], u[N];
int sl[N], sr[N], sd[N], su[N];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d%d%d%d", &l[i], &d[i], &r[i], &u[i]);
	memcpy(sl, l, sizeof(l));
	memcpy(sr, r, sizeof(r));
	memcpy(sd, d, sizeof(d));
	memcpy(su, u, sizeof(u));
	l[0] = d[0] = sl[n + 1] = sd[n + 1] = numeric_limits<int>::min();
	r[0] = u[0] = sr[n + 1] = su[n + 1] = numeric_limits<int>::max();
	for (int i = 1; i <= n; ++i) {
		l[i] = max(l[i], l[i - 1]);
		r[i] = min(r[i], r[i - 1]);
		d[i] = max(d[i], d[i - 1]);
		u[i] = min(u[i], u[i - 1]);
	}
	for (int i = n; i; --i) {
		sl[i] = max(sl[i], sl[i + 1]);
		sr[i] = min(sr[i], sr[i + 1]);
		sd[i] = max(sd[i], sd[i + 1]);
		su[i] = min(su[i], su[i + 1]);
	}
	for (int i = 1; i <= n; ++i) {
		int cl = max(l[i - 1], sl[i + 1]),
		    cr = min(r[i - 1], sr[i + 1]),
			cd = max(d[i - 1], sd[i + 1]),
			cu = min(u[i - 1], su[i + 1]);
		if (cl <= cr && cd <= cu) {
			printf("%d %d\n", cl, cd);
			return 0;
		}
	}
	return 0;
}