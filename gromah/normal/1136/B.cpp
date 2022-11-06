#include <cstdio>
#include <algorithm>
using namespace std;

int n, k;

int main()
{
	scanf("%d%d", &n, &k);
	printf("%d\n", 3 * n + min(k - 1, n - k));
	return 0;
}