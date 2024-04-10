#include <cmath>
#include <cstdio>
#include <cstring>

#include <algorithm>
#include <numeric>

using namespace std;

typedef long long ll;

int gcd(int a, int b) {
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

int main() {
	int n;
	scanf("%d", &n);
	while (n--) {
		int a, b, g;
		scanf("%d%d", &a, &b);
		g = gcd(a, b);
		a /= g;
		b /= g;
		if (g % a != 0 || g % b != 0) {
			puts("No");
			continue;
		}
		g /= a;
		g /= b;
		int x = pow(g, 1. / 3);
		while (x * x * x < g)
			++x;
		if (x * x * x == g)
			puts("Yes");
		else
			puts("No");
	}
	return 0;
}