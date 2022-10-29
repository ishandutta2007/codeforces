#include <cstdio>
#include <algorithm>
using namespace std;
int n, a[22], b[22], c[22];

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &a[i]);
	for (int i = 0; i < n; c[b[i] % n] = a[i], ++i)
		for (int j = 0; j < n; ++j)
			b[i] += a[i] >= a[j];
	for (int i = 0; i < n; ++i)
		printf("%d ", c[b[i] - 1]);
}