#include <bits/stdc++.h>
using namespace std;
int main(){
	int T;
	scanf("%d", &T);
	while (T--){
		int n, k;
		scanf("%d%d", &n, &k);
		if (n % k == 0){
			for (int i = 0; i < n % k; i++){
				for (int j = 0; j < n / k - 1; j++) printf("%c", char(i + 'a'));
			}
			for (int i = n % k; i < k; i++){
				for (int j = 0; j < n / k; j++) printf("%c", char(i + 'a'));
			}
			printf("\n");
			continue;
		}
		for (int i = 0; i < n % k; i++){
			for (int j = 0; j < n / k + 1; j++) printf("%c", char(i + 'a'));
		}
		for (int i = n % k; i < k; i++){
			for (int j = 0; j < n / k; j++) printf("%c", char(i + 'a'));
		}
		printf("\n");
	}
	return 0;
}