#include <bits/stdc++.h>
using namespace std;

string a[5] = {"aeiou", "eioua", "iouae", "ouaei", "uaeio"};

int main(){
	int k; scanf("%d", &k);
	for (int p = 1; p * p <= k; p++){
		if (k % p) continue;
		if (p >= 5 && k / p >= 5){
			for (int i = 0; i < p; i++){
				for (int j = 0; j < k / p; j++){
					printf("%c", a[i % 5][j % 5]);
				}
			}
			printf("\n");
			return 0;
		}
	}
	printf("-1\n");
	return 0;
}