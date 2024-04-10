#include <bits/stdc++.h>
using namespace std;

int a[110];
int b[110];

int main(){
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}
	sort(a, a + n), reverse(a, a + n);
	int l = 0, r = n - 1;
	for (int i = 0; i < n; i++){
		if (i & 1) b[r--] = a[i];
		else b[l++] = a[i];
	}
	for (int i = 0; i < n; i++){
		printf("%d ", b[i]);
	}
	printf("\n");
	return 0;
}