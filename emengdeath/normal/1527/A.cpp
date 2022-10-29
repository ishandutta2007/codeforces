#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <assert.h>
#include <queue>
#include <cstring>
using namespace std;
int T, n;
int main() {
	scanf("%d", &T);
	while (T --) {
		scanf("%d", &n);
		int ans = n;
		for (int i = 0; i < 31; i ++)
			if ((n >> i) & 1) ans = min(ans, n - (n & ((1 << i) - 1)) - 1);
		printf("%d\n",ans);
	}
	return 0;
}