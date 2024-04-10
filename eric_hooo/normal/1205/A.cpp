#include <bits/stdc++.h>
using namespace std;
int main(){
	int n; scanf("%d", &n);
	if (n % 2 == 0) {
		printf("NO\n");
		return 0;
	}
	printf("YES\n");
	for (int i = 0; i < n; i++) {
		printf("%d ", i & 1 ? i * 2 + 2 : i * 2 + 1);
	}
	for (int i = 0; i < n; i++) {
		printf("%d ", i & 1 ? i * 2 + 1 : i * 2 + 2);
	}
	printf("\n");
	return 0;
}