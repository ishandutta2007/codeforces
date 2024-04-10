#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long LL;

LL n, k;

int main()
{
	scanf("%lld%lld", &n, &k);
	LL b = min(n, k - 1);
	printf("%lld\n", max(b - (k >> 1), 0LL));
	return 0;
}