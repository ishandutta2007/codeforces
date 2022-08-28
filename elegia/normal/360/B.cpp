#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cassert>

#include <algorithm>
#include <queue>
#include <stack>
#include <numeric>
#include <limits>

#define LOG(FMT...) fprintf(stderr, FMT)

using namespace std;

typedef long long ll;

const int N = 2010, INF = 1000000000;

int n, k;
int a[N];
int dp[N];

bool pred(int x);

int main() {
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	int l = 0, r = INF * 2;
	while (l < r) {
		int mid = (l + (ll)r) >> 1;
		if (pred(mid))
  		   r = mid;
        else
			l = mid + 1; 
	}
	printf("%d\n", l);
	return 0;
}

bool pred(int x) {
	for (int i = 1; i <= n; ++i) {
		dp[i] = i - 1;
		for (int j = 1; j < i; ++j)
			if (abs(a[i] - (ll)a[j]) <= (i - j) * (ll)x)
			   dp[i] = min(dp[i], dp[j] + i - j - 1);
		if (dp[i] + n - i <= k)
		   return true;
	}
	return false;
}