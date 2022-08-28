#include <cstdio>

#include <algorithm>

using namespace std;

const int N = 110;

int main() {
	int p, y;
	scanf("%d%d", &p, &y);
	for (; y > 1; --y) {
		if (p >= y)
			break;
		bool flag = true;
		for (int x = 2; x * x <= y && x <= p; ++x)
			if (y % x == 0) {
				flag = false;
				break;
			}
		if (flag) {
			printf("%d\n", y);
			return 0;
		}
	}
	puts("-1");
	return 0;
}