#include <cmath>
#include <cstdio>
#include <cstring>

#include <algorithm>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

typedef long long ll;

const int N = 5010;

int digsum(int x) {
	int sum = 0;
	while (x > 0) {
		sum += x % 10;
		x /= 10;
	}
	return sum;
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; n; ++i) {
		if (digsum(i) == 10)
			if (--n == 0) {
				printf("%d\n", i);
				break;
			}
	}
	return 0;
}