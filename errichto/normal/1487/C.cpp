#include <bits/stdc++.h>
using namespace std;
int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		int n;
		scanf("%d", &n);
		for(int i = 1; i <= n; ++i) {
			for(int j = i + 1; j <= n; ++j) {
				if(2 * (j - i) == n) {
					printf("0 ");
				}
				else if(2 * (j - i) <= n) {
					printf("1 ");
				}
				else {
					printf("-1 ");
				}
			}
		}
		puts("");
	}
}