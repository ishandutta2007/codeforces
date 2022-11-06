#include <cstdio>
#include <algorithm>
using namespace std;

int Case, n, k;

int main()
{
	for (scanf("%d", &Case); Case; Case --)
	{
		scanf("%d%d", &n, &k);
		int sum = n % k == 0 ? n : n + k - (n % k);
		printf("%d\n", (sum - 1) / n + 1);
	}
	return 0;
}