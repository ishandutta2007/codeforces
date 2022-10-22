#include <bits/stdc++.h>
using namespace std;

int prime[400010];

int main(){
	int n; scanf("%d", &n);
	int cnt1 = 0, cnt2 = 0;
	for (int i = 0; i < n; i++){
		int x; scanf("%d", &x);
		if (x == 1) cnt1++;
		else cnt2++;
	}
	if (cnt1 == 0){
		for (int i = 0; i < cnt2; i++){
			printf("2 ");
		}
		printf("\n");
		return 0;
	}
	if (cnt2 == 0){
		for (int i = 0; i < cnt1; i++){
			printf("1 ");
		}
		printf("\n");
		return 0;
	}
	printf("2 1 ");
	cnt1--, cnt2--;
	for (int i = 0; i < cnt1 / 2; i++){
		printf("1 1 ");
	}
	for (int i = 0; i < cnt2; i++){
		printf("2 ");
	}
	if (cnt1 & 1) printf("1 ");
	printf("\n");
	return 0;
}