#include <iostream>
using namespace std;
int main() {
	int T; scanf("%d", &T);
	while (T--) {
		int a, b;
		scanf("%d%d", &a, &b);
		if (a == b) puts("0");
		else if (a < b) {
			if ((b - a) % 2 == 0) puts("2");
			else puts("1");
		} else {
			if ((a - b) % 2 == 1) puts("2");
			else puts("1");
		}
	}
	return 0;
}