#include <stdio.h>
#include <memory.h>
#include <math.h>
#include <stdlib.h>

#define int64_t long long

int64_t min(int64_t x, int64_t y) {
	return x < y ? x : y;
}

void handle(int from, int to, int64_t* balance, int decay, int* ans) {
	// fprintf(stderr, "from = %d, to = %d, balance = %ld, ans = %d\n", from, to, *balance, *ans);
	if ((*balance) < decay) {
		(*ans) += to - from;
	} else {
		int64_t num_nonneg = (*balance) / decay;
		(*ans) += to - from - min(to - from, num_nonneg);
	}
	(*balance) -= (int64_t)decay * (to - from);
}

int main() {
	int n, p, m;
	scanf("%d%d%d", &n, &p, &m);
	int ans = 0;
	int64_t cur = 0;
	int from = 1;
	for (int i = 0; i < n; ++i) {
		int d, t;
		scanf("%d%d", &d, &t);
		handle(from, d, &cur, p, &ans);
		from = d;
		cur += t;
	}
	handle(from, m + 1, &cur, p, &ans);

	printf("%d\n", ans);

	return 0;
}