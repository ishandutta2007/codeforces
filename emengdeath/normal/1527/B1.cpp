#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <assert.h>
#include <queue>
#include <cstring>
#include <map>
using namespace std;
int T, n;
char a[1001];
int main() {
	scanf("%d", &T);
	while (T --) {
		scanf("%d", &n);
		scanf(" %s", a + 1);
		for (int i = 1; i <= n; i ++) a[i] -= '0';
		bool sig = 0;
		int sum0 = 0;
		for (int i = 1; i <= n; i ++) {
			if (a[i] != a[n - i + 1]) sig = 1;
			sum0 += (a[i]== 0);
		}
		if (!sig) {
			if ((n & 1) && !a[(n + 1) / 2]) {
				if (sum0 == 1) puts("BOB");
				else
					puts("ALICE");
			} else {
				puts("BOB");
			}
		} else puts("ALICE");
		 
	}
	return 0;
}