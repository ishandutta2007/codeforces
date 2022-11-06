#include <cstdio>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>

using namespace std;

int a, b;

int main() {
	scanf("%d%d", &a, &b);
	long long ma = 1LL * a * a - 1LL * b * b;
	int k = 1;
	for (int i = 2; i <= b && i <= a + 1; i++) {
		int x = b / i, t1 = b - x * i, t2 = i - t1;
		if (1LL * (a + 2 - i) * (a + 2 - i) + (i - 2) - 1LL * x * x * t2 - 1LL * (x + 1) * (x + 1) * t1 > ma)
		ma = max(ma, 1LL * (a + 2 - i) * (a + 2 - i) + (i - 2) - 1LL * x * x * t2 - 1LL * (x + 1) * (x + 1) * t1), k = i;
	}
	cout << ma << endl;
	int x = b / k, t1 = b - x * k;
	for (int i = 1; i <= k; i++) {
		if (i > 1)	printf("o");
		if (i == k)	for (int j = 1; j < a + 2 - k; j++)	printf("o");
		for (int j = 1; j <= x; j++)	printf("x");
		if (i <= t1)	printf("x");
	}
}