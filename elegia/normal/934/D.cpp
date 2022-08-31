#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>

#include <algorithm>
#include <limits>
#include <numeric>
#include <iostream>

#ifdef LBT_DEBUG
#define LOG(FMT...) fprintf(stderr, "[LOG MESSAGE]: " FMT)
#define OUT(X) std::cerr << "[LOG #" #X "]: " << X << std::endl
#else
#define LOG(FMT...)
#define OUT(X)
#endif

typedef long long ll;

const int N = 2010;

int n;
int a[100];

int main() {
#ifdef LBT_DEBUG
	freopen("test.in", "r", stdin);
#endif
	ll p;
	int k;
	scanf("%lld%d", &p, &k);
	while (p) {
		a[n] = p % k;
		if (a[n] < 0)
			a[n] += k;
		p = (a[n] - p) / k;
		++n;
	}
	printf("%d\n", n);
	for (int i = 0; i < n - 1; ++i)
		printf("%d ", a[i]);
	printf("%d\n", a[n - 1]);
	return 0;
}