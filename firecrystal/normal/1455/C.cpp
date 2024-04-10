#include <cstdio>
#include <iostream>
using namespace std;

typedef long long LL;

int x, y;

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &x, &y);
		printf("%d %d\n", x - 1, y);
	}	
	return 0;
}