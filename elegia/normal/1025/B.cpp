#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cctype>

#include <algorithm>
#include <functional>
#include <set>
#include <map>
#include <vector>
#include <iostream>
#include <limits>
#include <numeric>

#define LOG(FMT...) fprintf(stderr, FMT)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int N = 150010;

int n;
int a[N], b[N];

void pred(int x) {
	if (x == 1)
		return;
	for (int i = 1; i <= n; ++i)
		if (a[i] % x && b[i] % x)
			return;
	printf("%d\n", x);
	exit(0);
}

int main() {

	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d%d", &a[i], &b[i]);
	int v = a[1];
	for (int x = 2; x * x <= v; ++x)
		while (v % x == 0) {
			pred(x);
			v /= x;
		}
	if (v != 1)
		pred(v);
	v = b[1];
	for (int x = 2; x * x <= v; ++x)
		while (v % x == 0) {
			pred(x);
			v /= x;
		}
	if (v != 1)
		pred(v);
	puts("-1");

	return 0;
}