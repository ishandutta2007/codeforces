#include <bits/stdc++.h>
using namespace std;

int a[110];

int main(){
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}
	int ans = 0;
	for (int i = 1; i < n; i++){
		if (a[i - 1] == 2 && a[i] == 3 || a[i - 1] == 3 && a[i] == 2 || a[i] == a[i - 1]){
			printf("Infinite\n");
			return 0;
		}
		int x = min(a[i - 1], a[i]), y = max(a[i - 1], a[i]);
		if (x == 1){
			if (y == 2) ans += 3;
			else ans += 4;
		}
		if (i >= 2 && a[i] == 2 && a[i - 1] == 1 && a[i - 2] == 3) ans--;
	}
	printf("Finite\n");
	printf("%d\n", ans);
	return 0;
}