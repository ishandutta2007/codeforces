#include <cstdio>
#include <iostream>
using namespace std;
 
typedef long long LL;
 
int n;
 
bool inline check() {
	for (int c = 0; c <= n / 7; c++) {
		int s = n - c * 7;
		for (int b = 0; b <= s / 5; b++) {
			int d = s - b * 5;
			if (d % 3 == 0) {
				printf("%d %d %d\n", d / 3, b, c);
				return true;
			}
		}
	}
	return false;
}
 
int main() {
	int T; scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);	
		if (!check()) puts("-1");
	}	
	return 0;
}