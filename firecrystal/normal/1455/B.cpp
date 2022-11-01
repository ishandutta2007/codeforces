#include <cstdio>
#include <iostream>
using namespace std;

typedef long long LL;

int x;

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		scanf("%d", &x);
		for (int i = 1; ; i++) {
			if (i * (i + 1) / 2 >= x) {
				int ans = i + i * (i + 1) / 2 - x;
				for (int j = 1; j <= i; j++) {
					if (i * (i + 1) / 2 - j - 1 >= x) {
						ans = min(ans, i + i * (i + 1) / 2 - j - 1 - x);
					}
				}
				printf("%d\n", ans);
				break;
			}
		}
	}	
	return 0;
}