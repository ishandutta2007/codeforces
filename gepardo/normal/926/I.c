#include <stdio.h>
#include <stdlib.h>

int a[1000], n;

int cmp (const void * a, const void * b) {
  return ( *(int*)a - *(int*)b );
}


int main(void) {
	scanf("%d", &n);
	for (int x, y, i = 0; i < n; i++) {
		scanf("%d:%d", &x, &y);
		a[i] = x * 60 + y;
	}
	qsort(a, n, sizeof(int), cmp);
	int ans = 0;
	for (int i = 1; i < n; i++)
		if (a[i] - a[i - 1] - 1 > ans)
			ans = a[i] - a[i - 1] - 1;
	if (1440 - a[n - 1] + a[0] - 1 > ans)
		ans = 1440 - a[n - 1] + a[0] - 1;
	
	printf("%02d:%02d", ans / 60, ans % 60);
	return 0;
}