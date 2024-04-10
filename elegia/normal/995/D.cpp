#include <cmath>
#include <cstdio>
#include <cstring>

#include <algorithm>
#include <vector>

#define LOG(FMT...) fprintf(stderr, FMT)

using namespace std;

typedef long long ll;

const int L = 18;

int n, r, b, U;
int f[1 << L];

int main() {
	scanf("%d%d", &n, &r);
	b = n / 2;
	U = (1 << n);
	ll sum = 0;
	for (int i = 0; i < U; ++i) {
		scanf("%d", &f[i]);
		sum += f[i];
	}
	printf("%.6lf\n", sum / (double)U);
	while (r--) {
		int g, r;
		scanf("%d%d", &g, &r);
		sum -= f[g];
		sum += f[g] = r;
		printf("%.6lf\n", sum / (double)U);
	}
	return 0;
}