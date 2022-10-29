#include <cmath>
#include <cstdio>
#include <algorithm>
int x[1000];
double res[1000];

inline int sqr(int x) {
	return x * x;
}

double solve(int a, int b, int r) {
	int dist = r - sqr(x[a] - x[b]);
	return dist < 0 ? 0 : res[b] + sqrt(dist);
}

inline void maxi(double &a, double b) {
	if (a < b) a = b;
}

int main() {
	int n, r; scanf("%d%d", &n, &r);
	std::fill(res, res + n, r);
	r *= r *= 2;
	for (int i = 0; i < n; ++i) {
		scanf("%d", &x[i]);
		for (int j = 0; j < i; ++j)
			maxi(res[i], solve(i, j, r));
		printf("%.9f ", res[i]);
	}
}