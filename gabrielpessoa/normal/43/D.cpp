#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	if(m == 1 && n > 2) {
		printf("1\n%d %d 1 1\n", n, m);
		for(int i = 1; i <= n; i++) {
			printf("%d %d\n", i, 1);
		}
		printf("1 1\n");
	} else if(n == 1 && m > 2) {
		printf("1\n%d %d 1 1\n", n, m);
		for(int j = 1; j <= m; j++) {
			printf("%d %d\n", 1, j);
		}
		printf("1 1\n");	
	} else if(n % 2 == 0) {
		printf("0\n1 1\n");
		for(int i = 1; i <= n; i += 2) {
			for(int j = 2; j <= m; j++) {
				printf("%d %d\n", i, j);
			}
			for(int j = m; j >= 2; j--) {
				printf("%d %d\n", i+1, j);
			}
		}
		for(int i = n; i > 0; i--) {
			printf("%d 1\n", i);
		} 
	} else if(m % 2 == 0) {
		printf("0\n1 1\n");
		for(int j = 1; j <= m; j += 2) {
			for(int i = 2; i <= n; i++) {
				printf("%d %d\n", i, j);
			}
			for(int i = n; i >= 2; i--) {
				printf("%d %d\n", i, j+1);
			}
		}
		for(int j = m; j > 0; j--) {
			printf("1 %d\n", j);
		}		
	} else {		
		printf("1\n%d %d 1 1\n", n, m);
		for(int i = 1; i < n; i += 2) {
			for(int j = 1; j <= m; j++) {
				printf("%d %d\n", i, j);
			}
			for(int j = m; j >= 1; j--) {
				printf("%d %d\n", i+1, j);
			}
		}
		for(int j = 1; j <= m; j++) {
			printf("%d %d\n", n, j);
		}
		printf("1 1\n");
	}
	return 0;
}