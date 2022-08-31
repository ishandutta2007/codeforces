#include <cstdio>
#include <cstring>

#include <algorithm>
#include <queue>
#include <limits>

using namespace std;

typedef long long ll;

const int N = 100010, INF = 1 << 20;

struct m_que {
	int l, r, size;
	int a[N];
	int sz[N];

	void clear() {
		l = 0;
		r = -1;
		size = 0;
	}

	void push(int x) {
		int cnt = 1;
		while (l <= r && a[r] >= x)
			cnt += sz[r--];
		sz[++r] = cnt;
		a[r] = x;
		++size;
	}

	void pop() {
		--size;
		if (--sz[l] == 0)
			++l;
	}

	int min() const {
		if (l > r)
			return numeric_limits<int>::max();
		return a[l];
	}
};

int n;
m_que q1, q2;

int dp[2][N], tmp[2][N];

int main() {
	int k, last = 0;
	scanf("%d%d", &n, &k);
	for (int i = 0; i < 2; ++i)
		fill(dp[i], dp[i] + n + 1, INF);
	dp[0][0] = dp[1][0] = 0;
	while (k--) {
		int l, r;
		scanf("%d%d", &l, &r);
		for (int i = 0; i < l - last; ++i)
			tmp[1][i] = INF;
		for (int i = l - last; i <= n; ++i)
			tmp[1][i] = dp[1][i - (l - last)];
		copy(tmp[1], tmp[1] + n + 1, dp[1]);
		q1.clear();
		q2.clear();

		for (int i = 0; i <= n; ++i) {
			q1.push(dp[0][i]);
			q2.push(dp[1][i]);
			if (q1.size > r - l + 1) {
				q1.pop();
				q2.pop();
			}
			tmp[0][i] = min(dp[0][i], min(q1.min() + 2, q2.min() + 1));
			if (i >= r - l)
				tmp[1][i] = min(dp[1][i - (r - l)], min(q1.min() + 1, q2.min() + 2));
			else
				tmp[1][i] = min(q1.min() + 2, q2.min() + 1);
		}
		memcpy(dp, tmp, sizeof(dp));
		last = r;
	}
	for (int i = 0; i < min(n * 2 - last, n + 1); ++i)
		tmp[1][i] = INF;
	for (int i = n * 2 - last; i <= n; ++i)
		tmp[1][i] = dp[1][i - (n * 2 - last)];
	copy(tmp[1], tmp[1] + n + 1, dp[1]);
	int ans = min(dp[0][n], dp[1][n]);
	if (ans >= INF)
		puts("Hungry");
	else
		printf("Full\n%d\n", ans);
	return 0;
}