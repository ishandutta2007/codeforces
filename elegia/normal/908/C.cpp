#include <cstdio>
#include <cmath>

#include <algorithm>

using namespace std;

const int N = 1010;

int n, r;
int x[N];
double h[N];

int main() {
	scanf("%d%d", &n, &r);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &x[i]);
		h[i] = r;
		for (int j = 1; j < i; ++j)
			if (abs(x[i] - x[j]) <= r * 2) {
				double height = h[j] + sqrt(r * r * 4 - (x[i] - x[j]) * (x[i] - x[j]));
				h[i] = max(h[i], height);
			}
	}
	for (int i = 1; i < n; ++i)
		printf("%lf ", h[i]);
	printf("%lf\n", h[n]);
	return 0;
}