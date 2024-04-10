#include <bits/stdc++.h>
using namespace std;

int a[20];

int main(){
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}
	for (int p = 0; p < (1 << n); p++){
		int sum = 0;
		for (int i = 0; i < n; i++){
			if (p & (1 << i)) sum += a[i];
			else sum -= a[i];
		}
		if (sum % 360 == 0){
			printf("YES\n");
			return 0;
		}
	}
	printf("NO\n");
	return 0;
}