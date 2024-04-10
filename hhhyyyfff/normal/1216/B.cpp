#include <cstdio>
#include <cstdlib>
#include <map>
#include <algorithm>

using namespace std;

//------------------------------------OI----------------------------------------

pair<int, int> a[1010];
int n, ans;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i].first);
		a[i].second = i + 1;
	}
	sort(a, a + n, greater<pair<int, int>>());
	for (int i = 0; i < n; ++i) ans += i * a[i].first + 1;
	printf("%d\n%d", ans, a[0].second);
	for (int i = 1; i < n; ++i) printf(" %d", a[i].second);
	printf("\n");
	return 0;
}