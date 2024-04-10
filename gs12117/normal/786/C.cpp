#include<stdio.h>
int n;
int a[100100];
int ans[100100];
int chk[100100];
int fans(int x) {
	for (int i = 0; i <= n; i++) {
		chk[i] = 0;
	}
	int res = 1;
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if (chk[a[i]] != res) {
			if (cnt == x) {
				cnt = 0;
				res++;
			}
			chk[a[i]] = res;
			cnt++;
		}
	}
	return res;
}
void calc(int start, int end) {
	if (start + 1 >= end)return;
	if (ans[start] == ans[end]) {
		for (int i = start + 1; i < end; i++) {
			ans[i] = ans[start];
		}
	}
	else {
		int mid = (start + end) / 2;
		ans[mid] = fans(mid);
		calc(start, mid);
		calc(mid, end);
	}
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	ans[1] = fans(1);
	ans[n] = fans(n);
	calc(1, n);
	for (int i = 1; i <= n; i++) {
		printf("%d ", ans[i]);
	}
	return 0;
}