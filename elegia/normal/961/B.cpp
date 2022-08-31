#include <cstdlib>
#include <cstdio>
#include <cstring>

#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>

#define LOG(FMT...) fprintf(stderr, FMT)

using namespace std;

typedef long long ll;

const int N = 100010;

int n, k;
bool f[N];
int sum[N];
int sum1[N], sum2[N];

int main() {
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &sum[i]);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &f[i]);
	for (int i = 1; i <= n; ++i) {
		sum1[i] = sum1[i - 1] + f[i] * sum[i];
	}
	for (int i = n; i; --i)
		sum2[i] = sum2[i + 1] + f[i] * sum[i];
	int ans = 0;
	for (int i = 1; i <= n; ++i)
		sum[i] += sum[i - 1];
	for (int i = k; i <= n; ++i)
		ans = max(ans, sum1[i - k] + (sum[i] - sum[i - k]) + sum2[i + 1]);
	printf("%d", ans);
	return 0;
}