#include <cstdio>

#include <algorithm>

using namespace std;

const int N = 110;

int a[N];

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &a[i]);
	sort(a, a + n);
	int difs = unique(a, a + n) - a;
	if (a[0] == 0)
		--difs;
	printf("%d\n", difs);
	return 0;
}