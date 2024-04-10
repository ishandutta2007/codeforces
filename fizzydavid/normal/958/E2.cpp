#undef DEBUG
#include <bits/stdc++.h>

using namespace std;

const int maxn = 5e5 + 10;

const long long oo = 1e10;

int x[maxn], a[maxn], n, k;
pair<long long, int> dp[maxn];

pair<long long, int> work(long long dlt) {
#ifdef DEBUG
	printf("dlt = %I64d\n", dlt);
#endif
	dp[0] = make_pair(0, 0);
	for (int i = 1; i <= n; ++i) {
		dp[i] = dp[i - 1];
		pair<long long, int> t;
		if(i >= 2) {
			t = make_pair(dp[i - 2].first + dlt + a[i], dp[i - 2].second + 1);
		}
		else {
			t = make_pair(a[i] + dlt, 1);
		}
		if(t.first < dp[i].first || t.first == dp[i].first && t.second < dp[i].second) {
			dp[i] = t;
		}
#ifdef DEBUG
		printf("%d:\t%I64d, %d\n", i, dp[i].first, dp[i].second);
#endif
	}
	return dp[n];
}

int main() {
	scanf("%d%d", &k, &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", x + i);
	}
	sort(x, x + n);
	--n;
	for (int i = 1; i <= n; ++i) {
		a[i] = x[i] - x[i - 1];
	}
#ifdef DEBUG
	for (int i = 1; i <= n; ++i) {
		printf("%d ", a[i]);
	}
	puts("");
#endif
	long long lb = -oo, rb =oo;
	while(lb <= rb) {
		long long mid = lb + rb >> 1;
		auto t = work(mid);
		if(t.second > k) {
			lb = mid + 1;
		}
		else {
			rb = mid - 1;
		}
	}
	auto t = work(lb);
#ifdef DEBUG
	printf("%I64d\n", lb);
	printf("%I64d, %d\n", t.first, t.second);
#endif
	printf("%d\n", (int) (t.first - k * lb));
	return 0;
}