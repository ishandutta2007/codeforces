#include <cstdio>
#include <cstdlib>

#include <algorithm>

using namespace std;

int main() {
	int n, ans = 0;
	scanf("%d", &n);
	while (n--) {
		int x;
		scanf("%d", &x);
		ans += abs(x);
	}
	printf("%d\n", ans);
	return 0;
}