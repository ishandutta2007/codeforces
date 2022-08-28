#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>

#include <algorithm>
#include <iostream>
#include <random>
#include <limits>
#include <numeric>
#include <functional>
#include <vector>
#include <set>
#include <map>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int N = 1010;

int n, m;
double fuel;
int a[N], b[N];

void load(int x) {
	fuel = (fuel * x + m) / (x - 1);
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i)
		scanf("%d", &a[i]);
	for (int i = 0; i < n; ++i)
		scanf("%d", &b[i]);
	if (count(a, a + n, 1) || count(b, b + n + 1, 1)) {
		puts("-1");
		return 0;
	}
	for (int i = n - 1; i >= 0; --i) {
		load(b[(i + 1) % n]);
		load(a[i]);
	}
	printf("%.8lf\n", fuel);
	return 0;
}