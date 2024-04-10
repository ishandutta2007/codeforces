#include<stdio.h>
int n;
int a[100100];
int mn, mx;
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	mn = a[0];
	mx = a[0];
	for (int i = 0; i < n; i++) {
		if (a[i] < mn)mn = a[i];
		if (a[i] > mx)mx = a[i];
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] != mn&&a[i] != mx)ans++;
	}
	printf("%d", ans);
	return 0;
}