#include <cstdio>

using namespace std;

typedef long long ll;

const int N = 200010;

int k, n, q;
int sum[N];

int main() {
	scanf("%d%d%d", &n, &k, &q);
	while (n--) {
		int l, r;
		scanf("%d%d", &l, &r);
		++sum[l];
		--sum[r + 1];
	}
	for (int i = 1; i < N; ++i)
		sum[i] += sum[i - 1];
	for (int i = 1; i < N; ++i)
		sum[i] = sum[i] >= k;
	for (int i = 1; i < N; ++i)
		sum[i] += sum[i - 1];
	while (q--) {
		int l, r;
		scanf("%d%d", &l, &r);
		printf("%d\n", sum[r] - sum[l - 1]);
	}
	return 0;
}