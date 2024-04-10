#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, sum = 0, sum2 = 0, a[200200];
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		sum += a[i];
	}
	for(int i = 0; i < n; i++) {
		sum2 += a[i];
		if(sum2 >= (sum / 2.0)) {
			printf("%d\n", i + 1);
			break;
		}
	}
	return 0;
}