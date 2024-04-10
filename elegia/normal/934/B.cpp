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

int a[52], b[52];

int main() {
#ifdef LBT_DEBUG
	freopen("test.in", "r", stdin);
#endif
	int k;
	scanf("%d", &k);
	if (k > 36) {
		puts("-1");
		return 0;
	}
	while (k >= 2) {
		putchar('8');
		k -= 2;
	}
	if (k)
		putchar('6');
	return 0;
}