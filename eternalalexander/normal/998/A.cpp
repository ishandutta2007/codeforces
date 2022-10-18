#include <cstdio>
int arr[20]; int a[20]; int b[20];
int flag=0;
int n;
int dfs(int n1, int n2, int sum1, int sum2, int p) {
	if (flag) return 0;
	if (p==n+1) {
		if (sum1!=sum2&&n1>0&&n2>0) {
			printf("%d", n2);
				printf("\n");
			for (int i=1;i<=n2;++i) printf("%d", b[i]);
			flag=1;
			return 0;
		}return 0;
	} a[n1+1]=p;
	dfs(n1+1, n2, sum1+arr[p], sum2, p+1);
	a[n1+1]=0; b[n2+1]=p;
	dfs(n1, n2+1, sum1, sum2+arr[p], p+1);
	b[n2+1]=0;
	return 0;
}

int main() {
	scanf("%d", &n);
	for (int i=1;i<=n;++i) {
		scanf("%d", &arr[i]);
	} dfs(0, 0, 0, 0, 1);
	if (!flag) printf("-1");
	return 0;
}