#include <cstdio>
#include <algorithm>
using namespace std;
int a[50];
double f[50][51], v[50], ans;

int main() {
	int n, sum = 0; scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
		sum += a[i];
	}
	int p; scanf("%d", &p);
	if (sum <= p) {
		printf("%d", n);
		return 0;
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j)
			for (int k = 0; k <= p; ++k)
				f[j][k] = 0;
		f[0][0] = 1;
		for (int j = 0; j < n; ++j)
			if (i != j)
				for (int k = n - 1; k > 0; --k)
					for (int l = a[j]; l <= p; ++l)
						f[k][l] += f[k - 1][l - a[j]] * k / (n - k + 1);
		for (int j = 0; j < n; ++j)
			for (int k = max(p - a[i] + 1, 0); k <= p; ++k)
				v[j] += f[j][k];
	}
	for (int i = 0; i < n; ++i)
		ans += v[i] * i / (n - i);
	printf("%f", ans);
}