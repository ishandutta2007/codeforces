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

int n, k, g;

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

int main() {
	scanf("%d%d", &n, &k);
	g = k;
	for (int i = 1; i <= n; ++i) {
		int x;
		scanf("%d", &x);
		g = gcd(x % k, g);
	}
	int c = k / g;
	printf("%d\n", c);
	for (int i = 0; i < k; ++i)
		if (i % g == 0)
			printf("%d ", i);
	return 0;
}