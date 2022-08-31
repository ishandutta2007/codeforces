#include <cstdio>
#include <cstring>

#include <algorithm>
#include <map>
#include <iostream>
#include <bitset>

#define LOG(FMT...) fprintf(stderr, FMT)

using namespace std;

typedef long long ll;

const int N = 200010;

int n, k;
int a[N];

int main() {
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	sort(a + 1, a + n + 1);
	if (k == 0) {
		if (a[1] == 1)
			puts("-1");
		else
			puts("1");
		return 0;
	}
	if (k == n)
		printf("%d\n", a[n]);
	else {
		if (a[k] == a[k + 1])
			puts("-1");
		else
			printf("%d\n", a[k]);
	}
	return 0;
}