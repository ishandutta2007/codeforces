#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>

#include <algorithm>
#include <iostream>
#include <numeric>
#include <functional>
#include <set>

#define LOG(FMT...) fprintf(stderr, FMT)

using namespace std;

typedef long long ll;

const int N = 1000100, P = 998244353;

int n;
int a[N], f[N];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		a[i] += a[i - 1];
		if (a[i] >= P)
			a[i] -= P;
	}
	int f = 0, fsum = 0, axpsum = 0;
	for (int i = 1; i <= n; ++i) {
		f = ((fsum + a[i]) % P + axpsum) % P;
		fsum = (fsum + f) % P;
		axpsum = (axpsum * 2LL + a[i]) % P;
	}
	printf("%d\n", f);
	return 0;
}