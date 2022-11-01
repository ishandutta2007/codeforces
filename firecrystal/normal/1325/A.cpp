#include <iostream>
#include <cstdio>

using namespace std;

int x;

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		scanf("%d", &x);
		printf("%d %d\n", 1, x - 1);
	}
	return 0;
}