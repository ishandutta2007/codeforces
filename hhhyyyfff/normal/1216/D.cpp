#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

//------------------------------------OI----------------------------------------

int n, z, a[200010];
long long y;

int gcd(int x, int y) { return y ? gcd(y, x % y) : x; }

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
	sort(a, a + n, greater<int>());
	for (int i = 1; i < n; ++i) z = gcd(a[0] - a[i], z);
	for (int i = 1; i < n; ++i) y += (a[0] - a[i]) / z;
	printf("%I64d %d\n", y, z);
	return 0;
}