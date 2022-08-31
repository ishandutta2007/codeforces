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

int a = 1, b;

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i) {
		int ca, cb;
		scanf("%d%d", &ca, &cb);
		if (b * ca < a * cb) {
			a = ca;
			b = cb;
		}
	}
	printf("%.8lf\n", 1. * m * a / b);
	return 0;
}