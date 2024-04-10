#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 300010;

int n, u;
int e[N];
double ans = -1;

int main() {
	scanf("%d%d", &n, &u);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &e[i]);
	int i = n, k = n;
	for (; i; --i) {
		while (e[k] - e[i] > u)
			--k;
		if (k - i >= 2)
			ans = max(ans, (e[k] - e[i + 1]) / (double)(e[k] - e[i]));
	}
	if (ans < 0)
		puts("-1");
	else
		printf("%.9lf\n", ans);
	return 0;
}