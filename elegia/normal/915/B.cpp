#include <cmath>
#include <cstdio>
#include <cstdlib>

#include <algorithm>

using namespace std;

int main() {
	int n, p, l, r;
	scanf("%d%d%d%d", &n, &p, &l, &r);
	if (l == 1) {
		if (r == n)
			puts("0");
		else
			printf("%d\n", abs(r - p) + 1);
	} else {
		if (r == n)
			printf("%d\n", abs(l - p) + 1);
		else
			printf("%d\n", min(abs(p - l), abs(p - r)) + abs(l - r) + 2);
	}
	return 0;
}