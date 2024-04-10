#include<stdio.h>
int n;
int a[10100];
int uft[10100];
int uftf(int x) {
	if (x == uft[x])return x;
	return uft[x] = uftf(uft[x]);
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < n; i++) {
		uft[i] = i;
	}
	for (int i = 0; i < n; i++) {
		int ma, mb;
		ma = uftf(i);
		mb = uftf(a[i] - 1);
		if (ma != mb) {
			uft[ma] = mb;
		}
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (uftf(i) == i)ans++;
	}
	printf("%d", ans);
	return 0;
}