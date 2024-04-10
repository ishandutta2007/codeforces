// Skyqwq
#include <iostream>
#include <cstdio>

using namespace std;

typedef long long LL;



int main() {
	int T; scanf("%d", &T);
	while (T--) {
		int n, K; scanf("%d%d", &n, &K);
		if (n > K) {
			LL t = (n + K - 1) / K;
			K = t * K;
		}
		printf("%lld\n", (K + (LL)n - 1) / n);
	}
	return 0;
}