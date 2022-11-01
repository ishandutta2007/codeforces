#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;

typedef long long LL;

int x, y;

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &x, &y);
		if (x == y) printf("%d\n", x + y);
		else {
			if (x < y) swap(x, y);
			printf("%d\n", x + max(x - 1, y));
		}
	}	
	return 0;
}